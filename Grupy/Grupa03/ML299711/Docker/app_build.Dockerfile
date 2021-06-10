FROM ubuntu:latest

ENV TZ=Europe/Warsaw
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime
RUN echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install git -y
RUN apt-get install npm -y

RUN git clone https://github.com/AlexTraher/Socket.io-Messenger.git
WORKDIR Socket.io-Messenger
RUN npm install