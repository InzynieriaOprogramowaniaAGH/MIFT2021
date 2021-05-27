FROM node:latest
RUN apt-get -y update
RUN apt-get -y install git
RUN git clone https://github.com/binhxn/node-chat-app.git
WORKDIR node-chat-app
RUN npm install
