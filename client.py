import socket
import sys
import string
import random
import thread
import time
#---------------------------------- Functions -------------------------------------#
def id_generator(size=10, chars=string.ascii_uppercase + string.ascii_lowercase):
    return ''.join(random.choice(chars) for _ in range(size))

def GetHost(host):                            # Return Host
    host = host.split('@')[1]
    host = host.split(' ')[0]
    return host

def GetChannel(data):                        # Return Channel
    channel = data.split('#')[1]
    channel = channel.split(':')[0]
    channel = '#' + channel
    channel = channel.strip(' \t\n\r')
    return channel

def GetNick(data):                            # Return Nickname
    nick = data.split('!')[0]
    nick = nick.replace(':', ' ')
    nick = nick.replace(' ', '')
    nick = nick.strip(' \t\n\r')
    return nick

def PRIVMSG(msg):
    irc.send('PRIVMSG ' + chan + ' : ' + msg +  '\r\n')

def Join(chan):
    irc.send ( 'JOIN ' + chan + '\r\n' )

def Part(chan):
    irc.send ( 'PART ' + chan + '\r\n' )

def Op(to_op, chan):
    irc.send( 'MODE ' + chan + ' +o: ' + to_op + '\r\n')

def DeOp(to_deop, chan):
    irc.send( 'MODE ' + chan + ' -o: ' + to_deop + '\r\n')

def Voice(to_v, chan):
    irc.send( 'MODE ' + chan + ' +v: ' + to_v + '\r\n')

def DeVoice(to_dv, chan):
    irc.send( 'MODE ' + chan + ' -v: ' + to_dv + '\r\n')

#------------------------------------------------------------------------------#
def RECEIVE():
    while True:
        action = 'none'
        data = irc.recv ( 4096 )
        print(data)

        if data.find ( 'Welcome to the freenode Internet Relay Chat Network ' + nick) != -1:
                irc.send ( 'JOIN ' + chan + '\r\n' )

        if data.find ( 'PING' ) != -1:
                irc.send ( 'PONG ' + data.split() [ 1 ] + '\r\n' )

        #--------------------------- Action check --------------------------------#
        if data.find('#') != -1:
            action = data.split('#')[0]
            action = action.split(' ')[1]
            #print action
         
        #----------------------------- Actions -----------------------------------#
        if action != 'none':
            if action == 'PRIVMSG':
                if data.find('!') != -1:
                    sender = GetNick(data)
                    raw_msg = data.split(':')[2]
                    print sender + " said: " + raw_msg


def SEND():
    while True:
        msg = raw_input()
        if msg[0] == '/':
            irc.send(msg.strip('/') + '\r\n')
        else:
            PRIVMSG(msg)

        

if __name__ == "__main__":
    #--------------------------- Connect to server and login w/ an unique NICK name--------------------------------#
    irc = socket.socket()
    irc.connect(("irc.freenode.net",6667))
    bot_owner = "jtlin"
    nick = id_generator()
    chan = "#testset"
    irc.send(("USER " + nick + " 0 * :" + bot_owner + "\r\n").encode())
    irc.send(("NICK " + nick + "\r\n").encode())

    lock = thread.allocate_lock()
    thread.start_new_thread(RECEIVE,())
    thread.start_new_thread(SEND,())

    while (True):
        pass 
