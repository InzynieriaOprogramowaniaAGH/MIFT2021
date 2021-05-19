FROM ubuntu:latest


ENV TZ=Europe/Warsaw

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update

RUN apt-get install git -y

RUN apt-get install npm -y

RUN git clone https://github.com/wireapp/wire-desktop

RUN cd wire-desktop

RUN npm install --global yarn

WORKDIR /wire-desktop

RUN npm install -g typescript 

RUN npm install

RUN yarn build:linux
