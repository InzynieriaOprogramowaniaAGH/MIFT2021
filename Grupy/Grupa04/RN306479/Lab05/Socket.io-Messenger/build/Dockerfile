FROM ubuntu:latest

ENV TZ=Europe/Warsaw
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update && apt-get install git -y && apt-get install npm -y

RUN git clone https://github.com/AlexTraher/Socket.io-Messenger.git
WORKDIR Socket.io-Messenger
RUN npm install
