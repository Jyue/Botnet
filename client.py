import socket



bot_owner = "Jakash3"
chan = "#testset"
irc = socket.socket()
irc.connect(("irc.freenode.net",6667))
nick = "dfddhdhdh"

#nick = raw_input(">>> Nickname: ")
irc.send("USER " + nick + " 0 * :" + bot_owner + "\r\n")
irc.send("NICK " + nick + "\r\n")


#---------------------------------- Functions -------------------------------------#


def readAdmin(host):                        # Return status 0/1
    bestand = open('admins.txt', 'r')
    for line in bestand:
        if host in line:
            status = 1
            return status
        else:
            status = 0
            return status

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

def Send(msg):
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



while True:
    action = 'none'
    data = irc.recv ( 4096 ) 
    print data

    if data.find ( 'Welcome to the freenode Internet Relay Chat Network '+nick) != -1:
            Join(chan)
    if data.find ( 'PING' ) != -1:
            irc.send ( 'PONG ' + data.split() [ 1 ] + '\r\n' )
    
   
    