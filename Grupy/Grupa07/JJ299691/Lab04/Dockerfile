FROM ubuntu:latest

ENV TZ=Europe/Warsaw

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update

RUN apt-get -q install npm -y

RUN npm install --global yarn

RUN npm install -g typescript 

RUN cd ~

COPY wire-desktop ./wire-desktop

RUN npm --prefix wire-desktop install
