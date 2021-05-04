FROM ubuntu:latest
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y build-essential
RUN apt-get install -y byobu curl git htop man unzip wget
ENV HOME /root
WORKDIR /root
CMD ["bash"]
    
