FROM alpine:3.10
RUN apk update
RUN apk add git

RUN apk update
RUN apk add npm

RUN mkdir home/chat
WORKDIR home/chat
RUN git clone https://github.com/igorantun/node-chat

RUN npm install --prefix ./node-chat
RUN npm audit fix --prefix ./node-chat
RUN npm install --prefix ./node-chat




