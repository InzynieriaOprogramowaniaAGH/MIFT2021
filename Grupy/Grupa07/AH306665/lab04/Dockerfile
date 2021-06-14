FROM ubuntu:latest
ENV TIME_ZONE=Europe/Warsaw
RUN ln -snf /usr/share/zoneinfo/$TIME_ZONE /etc/localtime && echo $TIME_ZONE > /etc/timezone
RUN apt-get update
RUN apt-get install -y git npm
RUN git clone https://github.com/binhxn/node-chat-app.git
RUN cd node-chat-app; npm install
