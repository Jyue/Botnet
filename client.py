import sys
import socket
import string

HOST=" "
PORT=6667
NICK="MauBot"
IDENT="maubot"
REALNAME="MauritsBot"
readbuffer=""

s=socket.socket( )
s.connect((HOST, PORT))
#s.send("NICK %s\r\n" % NICK)
#s.send("USER %s %s bla :%s\r\n" % (IDENT, HOST, REALNAME))

print "hi"
while 1:
    readbuffer = readbuffer + s.recv(1024)
    temp = string.split(readbuffer, "\n")
    readbuffer = temp.pop( )

    for line in temp:
        line=string.rstrip(line)
        line=string.split(line)

        if(line[0]=="PING"):
            s.send("PONG %s\r\n" % line[1])