FROM ubuntu:latest
RUN \ 
	apt-get update && \
	apt-get -y upgrade && \
	apt-get install -y build-essential && \
	apt-get install -y byobu curl git htop man unzip vim wget && \
	apt-get install --assume-yes git
	
ENV HOME /root
WORKDIR /root
CMD ["bash"]
