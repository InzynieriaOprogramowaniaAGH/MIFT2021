FROM ubuntu:latest

#problem ze strefą czasową

ENV TZ=Europe/Warsaw

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update

RUN apt-get install git -y

RUN apt-get install curl -y

RUN curl -sL https://deb.nodesource.com/setup_14.x | bash -

RUN apt-get install nodejs -y

RUN git clone https://github.com/MStabryla/wire-desktop

RUN cd wire-desktop

RUN npm install --global yarn

WORKDIR /wire-desktop

#RUN npm install -g typescript 

#RUN npm install

RUN yarn

RUN yarn build:linux

#CMD ["./dist/linux-unpacked/wire-desktop"]