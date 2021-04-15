FROM debian:latest

RUN apt-get update && apt-get -y upgrade && \
	 apt-get -y install git && \
	 apt-get -y install python3-pip
RUN pip3 install cmake && \
	 curl https://sh.rustup.rs -sSf | sh


RUN git clone https://github.com/deltachat/deltachat-core-rust.git

RUN cmake deltachat-core-rust/CMakeLists.txt && \
	 apt-get -y install python3

