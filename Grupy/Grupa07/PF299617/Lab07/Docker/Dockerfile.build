FROM ubuntu:latest

ENV TZ=Europe/Warsaw
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install -y git 
RUN apt-get install npm -y

RUN git clone https://github.com/deltachat/deltachat-desktop.git
WORKDIR ./deltachat-desktop

RUN npm install
RUN npm run build
