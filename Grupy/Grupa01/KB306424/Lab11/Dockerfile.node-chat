FROM ubuntu:latest
ENV TZ=Europe/Warsaw
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update -y
RUN apt-get install -y git npm
RUN git clone https://github.com/binhxn/node-chat-app.git
WORKDIR node-chat-app
EXPOSE 3000
RUN npm install
CMD npm start
