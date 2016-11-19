FROM jamesdsmith/bearhacks

MAINTAINER James Smith <james.smith@berkeley.edu>

USER root

RUN apt-get update
RUN apt-get install npm libzmq3-dev && apt-get clean
RUN npm install -g ijavascript

USER main

