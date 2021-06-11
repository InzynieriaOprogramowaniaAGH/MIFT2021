FROM ubuntu:latest
RUN apt-get update && apt-get upgrade -y
RUN apt-get update && apt-get install git -y
ENV TZ=Europe/Warsaw
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update && apt-get install tzdata -y
RUN apt-get update && apt-get install npm -y
RUN apt-get update && apt-get install apt-utils -y
RUN git clone https://github.com/deltachat/deltachat-desktop.git
RUN npm install --prefix deltachat-desktop/
RUN npm run build --prefix deltachat-desktop/

