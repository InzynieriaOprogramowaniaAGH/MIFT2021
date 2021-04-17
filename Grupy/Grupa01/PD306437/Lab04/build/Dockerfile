FROM node:14

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y git

WORKDIR /

RUN git clone https://github.com/binhxn/node-chat-app.git

WORKDIR /node-chat-app
RUN npm install
RUN npm build

