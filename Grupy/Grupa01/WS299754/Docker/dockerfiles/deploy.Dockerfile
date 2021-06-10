FROM ubuntu:latest
MAINTAINER Weronika Smieja

ENV TZ=Europe/Warsaw
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo TZ > /etc/timezone

RUN apt-get -y update
RUN apt-get install -y build-essential
RUN apt-get -y install git
RUN apt-get -y install npm

WORKDIR ~
COPY . node-chat-app/
WORKDIR node-chat-app
RUN ls
RUN npm install
