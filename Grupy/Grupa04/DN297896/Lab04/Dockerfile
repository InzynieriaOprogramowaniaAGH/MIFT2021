FROM node:14.16.0-buster

RUN apt-get -y update
RUN apt-get -y install git

RUN git clone https://github.com/deltachat/deltachat-desktop.git
WORKDIR ./deltachat-desktop

RUN npm install
RUN npm run build