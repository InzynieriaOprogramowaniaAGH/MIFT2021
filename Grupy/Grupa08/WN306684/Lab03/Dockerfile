FROM ubuntu:latest
RUN \
    apt-get update && \
    apt-get -y upgrade && \
    apt-get install -y git &&\
    apt-get install --assume-yes git
ENV HOME /root
WORKDIR /root
CMD ["bash"]

