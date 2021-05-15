FROM node:14.16.0-buster

RUN apt-get update 
RUN apt-get install -y --no-install-recommends git

RUN git clone https://github.com/deltachat/deltachat-desktop.git
WORKDIR ./deltachat-desktop
RUN npm install 
RUN npm run build 
