FROM ubuntu:latest
RUN \
	apt-get update && \
	apt-get -y upgrade && \
	apt-get install -y build-essential && \
	apt-get install -y git
ENV HOME /root
WORKDIR /root
CMD ["bash"]
