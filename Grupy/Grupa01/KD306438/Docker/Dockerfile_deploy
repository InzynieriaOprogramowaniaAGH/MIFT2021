FROM node:14.16.0-buster
RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install --assume-yes git
RUN apt-get install --assume-yes g++

COPY . node-chat/
WORKDIR node-chat
RUN ls
