#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros
#define client_num 30

#define MAX_MESSAGE_LEN 100
#define Refresh_TABLE_TIME 5


/******Table*******/
int ID[client_num];
char IP[client_num][16];
int  Port_[client_num];
char client_time[client_num][64]={0};
int alive[client_num];
int j=0;
/******************/
int client_socket[client_num];


void print_table(){
    printf("***********************************************************************************************************");
    printf("\nID              IP                Port      Time                                 Alive?    \n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    for(j=0;j<client_num;j++){
        if(client_socket[j]!=0){
            printf("%d    %s    %d       %s    %s\n",ID[j],IP[j],Port_[j],client_time[j],(alive[j]==1?"YES":"NO"));
        }
    }
}

/*** djb2 hash function - used to hash IP+Port into a unique ID ***/
unsigned long hash(unsigned char *str)
    {
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }


int main(int argc, char *argv[]) {
	char job[4][10];
	int jobnum;
	printf("\nestablish job list:\n");
	printf("1.)");
	scanf("%s",job[0]);
	printf("2.)");
	scanf("%s",job[1]);
	printf("3.)");
	scanf("%s",job[2]);
	printf("4.)");
	scanf("%s",job[3]);
	printf("\n\n");
    /***
    Check command line argument and configure socket address structure.
    ***/
    if(argc != 2) {
        puts("Usage: echo_server {port}");
        exit(1);
    }

    struct sockaddr_in self_addr;
    bzero(&self_addr, sizeof(self_addr));
    self_addr.sin_addr.s_addr = (in_addr_t) 0x00000000;
    self_addr.sin_port = htons(atoi(argv[1]));
    self_addr.sin_family = AF_INET;

 //   fd_set master; // master file descriptor
    fd_set read_fds, active_fd_set; // set of socket descriptors
    int fdmax; // max file descriptor number
    int nbytes;
    int Rewrite = 0;//hash flag
    int i = 0;
    int sd = 0;
    int new_client_fd;
    int p = 0;
	struct timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    //initialize all client_socket[] to 0 so not checked
    for (i = 0; i < client_num; i++)
    {
        client_socket[i] = 0;
		alive[i]=0;
    }



    /***
    Create socket.
    ***/
    puts("Creating socket...");
    int s_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(s_fd == -1) {
        puts("Fail to create socket.");
        exit(2);
    }
    else {
        puts("Socket created");
    }






    /***
    Bind.
    ***/

    puts("Binding...");

    if(bind(s_fd, (struct sockaddr *) &self_addr, sizeof(self_addr)) == -1) {
        puts("Fail to bind.");
        exit(2);
    }
    else {
        puts("Bind successfully.");
    }



    /***
    Listen.
    ***/
    if(listen(s_fd, 10) == -1) {                           //10 for max number of connections
        puts("Fail to listen.");
        exit(2);
    }
    else {
        //printf("%s\n",self_addr.sin_addr.s_addr);
        puts("Start listening...");
    }


    FD_ZERO(&active_fd_set);
    //Add s_fd into read_fds
    FD_SET(s_fd, &active_fd_set);
    // Continue tracking the largeset file descriptor
    fdmax = s_fd;




Start:
    // Main Loop: Keep accept connection and recieve msg sent from clients
    while(1){
		
		/******Current Time*****/
		time_t ct = time(0);
		char cur_time[64];
		strftime( cur_time, sizeof(cur_time), "%Y/%m/%d %X %A %z",localtime(&ct) );
		/***********************/
		puts("***********************************************************************************************************");
		printf("目前時間 : ");
		puts( cur_time );
		printf("\n\n");




		timeout.tv_sec = 5;





        /* Block until input arrives on one or more active sockets. */
        read_fds = active_fd_set;
        /***
        Select clients.
        ***/
		if(select(fdmax+1, &read_fds, NULL, NULL, &timeout) == 0){
			print_table();

			goto Start;
		}
        else if (select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1) {
            puts("Fail to select.");
            exit(2);
        }







        /***
        Accepting clients.
        ***/
        struct sockaddr_in client_addr;
        int client_addr_size;

        char str[INET_ADDRSTRLEN];


        //inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, str, sizeof(client_addr));//put dots on client addr(unsigned long int) in order to see more clearly



        for (i = 0; i < FD_SETSIZE; ++i){
            if (FD_ISSET(i, &read_fds)) {
                char recv_msg[MAX_MESSAGE_LEN + 1]="\0";
                char send_msg[MAX_MESSAGE_LEN + 1]="\0";
                memset(recv_msg, 0, MAX_MESSAGE_LEN + 1);
                memset(send_msg, 0, MAX_MESSAGE_LEN + 1);
                char hash_str[25];
                char port_str[6];
                if(i == s_fd){/* Connection request on original socket. */
                    /***
                    Accept
                    ***/
                    client_addr_size = sizeof(client_addr); //initialize size
                    new_client_fd = accept(s_fd, (struct sockaddr *) &client_addr, &client_addr_size);/// client_s_fd : new client's socket fd
                    if(new_client_fd == -1) {
                        puts("Fail to accept.");
                        exit(2);
                    }

                    FD_SET (new_client_fd, &active_fd_set);
                    //highest file descriptor number, need it for the select function
                    if(new_client_fd > fdmax) fdmax = new_client_fd;


                    puts("Accepted from client.");

                    for(i=0;i<client_num;i++){
                        if(client_socket[i]==0){
                            client_socket[i] = new_client_fd;
                            break;
                        }
                    }





                    inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, str, sizeof(client_addr));//put dots on client addr(unsigned long int) in order to see more clearly
                    //printf("=== New client's address:%s ===\n",str);
                    //printf("=== New client's port number:%d ===\n",ntohs(client_addr.sin_port));
        			//printf(" %c ",client_addr.sin_addr);

        			/***TIME THE CLIENTS CONNECT****/
        			time_t t = time(0);
        			char tmp[64];
        			strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A %z",localtime(&t) );
        			int k;
        			for(k=0;k<64;k++)
        				client_time[i][k]=tmp[k];
                    

        			//ID[i] = i;

                    /*  Combine IP and port into 
                        a string and hash it.        */
                    sprintf(port_str, "%d", ntohs(client_addr.sin_port)); //port number: int to string
                    strncpy(hash_str, str, 16);//put IP string into hash_str
                    strcat(hash_str,port_str);//Combine hash_str(IP) and port string
                    for(i = 0; ID[i]!=0; i++){
                        if(ID[i] == hash(hash_str)){//if there is a same hash ID already existed
                            ID[i] = hash(hash_str);//Rewrite
                            Rewrite = 1;//flag = 1
                            break;
                        }
                    }
                    if(Rewrite == 0) ID[i] = hash(hash_str); //New hash ID


                    /********************************
                    *********************************/
        			strncpy(IP[i], str, 16);
        			Port_[i]=ntohs(client_addr.sin_port);
                    
                    alive[i] = 1;


                    
        			
        			/*printf("Who's alive:\n ");
                    for(p=0;p<client_num;p++)
                        printf("%d,  ",alive[p]);
                    printf("\n"); */


                    print_table();
                    break;
                }

                else {

                    for(p = 0; p <client_num; p++){


                        sd = client_socket[p];
                        if(FD_ISSET(sd, &active_fd_set )&& alive[p]==1){
                            // if got error or connection closed by client
                            if ((nbytes=recv(sd, recv_msg, MAX_MESSAGE_LEN, 0)) <= 0) {
                                if (nbytes == 0) {
                                 // Somebody disconnected
                                    printf("selectserver: socket %d hung up\n", p);

                                }
                                else {
                                  puts("Fail to receive message.");
                                }

                               // printf("sd = %d\n", sd);
                                close(sd); // bye!
                                FD_CLR(sd, &active_fd_set); // Remove from &read_fds


        						//int temp = client_socket[i];
                                int temp_i = p;
                                client_socket[p]=0;



                                client_socket[temp_i]=sd;

				

                                alive[p]=0;
                                /*printf("Who's alive:\n ");
                                for(p=0;p<client_num;p++)
                                    printf("%d,  ",alive[p]);
                                printf("\n");*/

                                print_table();
        						

                            }

                            else {
                            // Receive some data from client
                                printf("Message received:\n\t%s\n", recv_msg);

                                memset(send_msg, 0, MAX_MESSAGE_LEN + 1);
                                strcpy(send_msg, "You said:\"");
                                strcat(send_msg, recv_msg);
                                strcat(send_msg, "\" :)");


                                printf("Sending back message: %s...\n", send_msg);
                                //send_msg[MAX_MESSAGE_LEN + 1] = '\0';
                                

                                if(send(sd, send_msg, MAX_MESSAGE_LEN, 0) == -1) {
                                    puts("Fail to send message");
                                    exit(2);
                                }
                                else {
                                    //close(client_s_fd);
                                    puts("Message sent\n");
                                    /***
									Send job to server.
									(Maybe we can establish a job database in the future.)
									***/
                                   
                                }
       								printf("\nJob List: ");
                                   	for(jobnum=0;jobnum<=3;jobnum++){
									   		printf("%d.)%s ",jobnum+1,job[jobnum]);
									   }
									printf("\nPlease enter the job you want client to do(Enter the number): ");
									scanf("%d",&jobnum);
									printf("You want client '%s' ...\n", job[jobnum-1]);

									if(send(new_client_fd , job[jobnum-1], strlen(job[jobnum-1]), 0) == -1) {
										puts("Fail to send job to client.");
										exit(2);
									} else {
										puts("Job has sented to client.");
									}  
                            }
                          		
                        }
                    
					}
                    
                }// END handle data from client

            }
		}
       // }
    }







        /***
                }
                Receive, process message, and send back.

                while(1) {
                    puts("Receiveing...");
                    if(recv(client_s_fd, recv_msg, MAX_MESSAGE_LEN, 0) == -1) {
                        puts("Fail to receive message.");
                        exit(2);
                    }
                    else {
                        printf("Message received:\n\t%s\n", recv_msg);
                    }

                    strcpy(send_msg, "You said: \"");
                    strcat(send_msg, recv_msg);
                    strcat(send_msg, "\" :)");

                    printf("Sending back message: %s...\n", send_msg);
                    if(send(client_s_fd, send_msg, MAX_MESSAGE_LEN, 0) == -1) {
                        puts("Fail to send message");
                        exit(2);
                    }
                    else {
                        //close(client_s_fd);
                        puts("Message sent\n");

                    }
                }***/
    
    close(s_fd);
    //close(client_fd);
    return 0;
}

