FROM node:15.14.0-stretch
RUN apt-get update
RUN apt-get install -y git
RUN npm install -g npm@7.8.0

RUN git clone https://github.com/deltachat/deltachat-desktop.git
WORKDIR ./deltachat-desktop
RUN npm install
RUN npm run build
