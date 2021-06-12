FROM node:latest
RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y git
RUN git clone https://github.com/binhxn/node-chat-app.git
WORKDIR node-chat-app
RUN npm install
ENTRYPOINT [ "npm", "run", "dev" ]
