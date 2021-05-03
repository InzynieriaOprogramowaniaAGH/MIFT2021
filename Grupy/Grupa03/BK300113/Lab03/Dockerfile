FROM ubuntu:latest
RUN apt update
RUN apt dist-upgrade -y
RUN apt install -y build-essential
RUN apt install -y byobu curl git man unzip wget
ENV HOME /root
WORKDIR /root
CMD ["bash"]