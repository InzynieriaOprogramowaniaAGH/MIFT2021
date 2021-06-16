FROM ubuntu:latest
MAINTAINER Weronika Smieja

ENV TZ=Europe/Warsaw
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo TZ > /etc/timezone

RUN apt-get -y update
RUN apt-get -y install git
RUN apt-get -y install npm

RUN git clone https://github.com/angristan/node-chat-app
WORKDIR node-chat-app

EXPOSE 3000
RUN npm install

CMD ["npm", "start"]
