FROM alpine:3.10
RUN apk update
RUN apk add git

RUN apk update
RUN apk add npm

RUN mkdir home/chat
WORKDIR home/chat
RUN git clone https://github.com/AlexTraher/Socket.io-Messenger

RUN npm install --prefix ./Socket.io-Messenger
RUN npm audit fix --prefix ./Socket.io-Messenger
RUN npm install --prefix ./Socket.io-Messenger




