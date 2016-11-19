"""Credits to instructables.com for providing this code"""
import cfg
import socket
import re
from time import sleep

CHAN = '#'+cfg.CHANNEL_NAME

def chat(sock, msg):
    """
    Send a chat message to the server.
    Keyword arguments:
    sock -- the socket over which to send the message
    msg -- the message to be sent
    """
    sock.send("PRIVMSG {} : {}\r\n".format(CHAN,msg).encode("utf-8"))

def ban(sock, user):
    """
    Ban a user from the current channel.
    Keyword arguments:
    sock -- the socket over which to send the ban command
    user -- the user to be banned
    """
    chat(sock, ".ban {}".format(user))

def timeout(sock, user, secs=600):
    """
    Time out a user for a set period of time.
    Keyword arguments:
    sock -- the socket over which to send the timeout command
    user -- the user to be timed out
    secs -- the length of the timeout in seconds (default 600)
    """
    chat(sock, ".timeout {}".format(user, secs))

def process_chat(user, message):
    if len(message)>0:
        prefix, _ , rest = message.partition(' ')
        #Says hello when you type !greet {name}
        if prefix[0]=='!':
            command = prefix[1:].strip()
            if command=='greet':
                msg = rest.strip()
                chat(s, "Hello, {}".format(msg))

CHAT_MSG = re.compile(r"^:\w+!\w+@\w+\.tmi\.twitch\.tv PRIVMSG #\w+ :")

s = socket.socket()
s.connect((cfg.HOST, cfg.PORT))
s.send("PASS {}\r\n".format(cfg.PASS).encode("utf-8"))
s.send("NICK {}\r\n".format(cfg.NICK).encode("utf-8"))
s.send("JOIN {}\r\n".format(CHAN).encode("utf-8"))
chat(s,"Hello, this is a bot")

while True:
    response = s.recv(1024).decode("utf-8")
    if response == "PING :tmi.twitch.tv\r\n":
        s.send("PONG :tmi.twitch.tv\r\n")
    else:
        username = re.search(r"\w+",response).group(0)
        message = CHAT_MSG.sub("", response)
        print(username + " : " + message)
        process_chat(username, message)
    sleep(1 / cfg.RATE)

