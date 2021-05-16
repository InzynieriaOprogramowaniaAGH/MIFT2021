FROM node:14.16.0-buster

RUN apt-get update
RUN apt-get install -y --no-install-recommends git make python g++ yarn

COPY . node-chat-app/
WORKDIR node-chat-app
RUN ls
