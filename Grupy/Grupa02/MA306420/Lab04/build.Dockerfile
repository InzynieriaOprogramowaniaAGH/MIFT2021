FROM node:12.21.0-buster-slim

# add git and tools required to build native node packages
RUN apt-get update && apt-get install -y --no-install-recommends git gcc g++ make python wget ca-certificates

RUN mkdir /usr/local/share/ca-certificates/cacert.org
RUN wget -P /usr/local/share/ca-certificates/cacert.org http://www.cacert.org/certs/root.crt http://www.cacert.org/certs/class3.crt && update-ca-certificates

RUN git clone https://github.com/RocketChat/Rocket.Chat.git application

WORKDIR /application

RUN npm ci && npm build
