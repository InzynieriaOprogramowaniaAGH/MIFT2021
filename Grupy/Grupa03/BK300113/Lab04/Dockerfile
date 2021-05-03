FROM ubuntu:latest
RUN apt update
RUN apt dist-upgrade -y
RUN apt install -y build-essential
RUN apt install -y byobu curl git man unzip wget
RUN apt update -y
RUN apt upgrade -y
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get install gnupg2 software-properties-common build-essential -y --fix-missing
RUN curl -sL https://deb.nodesource.com/setup_10.x | bash -
RUN apt-get install nodejs -y
RUN curl -fsSL https://www.mongodb.org/static/pgp/server-4.4.asc | apt-key add -
RUN echo "deb [ arch=amd64,arm64 ] https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/4.4 multiverse" | tee /etc/apt/sources.list.d/mongodb-org-4.4.list
RUN apt-get update -y
RUN apt-get install mongodb-org -y

ENV HOME /root
WORKDIR /root
CMD ["bash"]