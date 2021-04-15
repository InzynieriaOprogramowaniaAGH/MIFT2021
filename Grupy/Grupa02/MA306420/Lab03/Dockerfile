FROM ubuntu:latest

RUN apt-get -y update && apt-get install -y --no-install-recommends git wget ca-certificates

RUN mkdir /usr/local/share/ca-certificates/cacert.org
RUN wget -P /usr/local/share/ca-certificates/cacert.org http://www.cacert.org/certs/root.crt http://www.cacert.org/certs/class3.crt && update-ca-certificates

RUN git clone https://github.com/InzynieriaOprogramowaniaAGH/MIFT2021.git
