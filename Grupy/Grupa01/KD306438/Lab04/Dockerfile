FROM node:14.16.0-buster
# instalacja gita
RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install --assume-yes git
RUN apt-get install --assume-yes g++
RUN git clone https://github.com/igorantun/node-chat.git
WORKDIR ./node-chat
RUN npm install
CMD ["npm", "start"]

