FROM node:15.12.0-alpine3.10

RUN apk add git

RUN git clone https://github.com/feathersjs/feathers-chat.git /application

WORKDIR /application

RUN npm ci

CMD ["npm", "start"]
