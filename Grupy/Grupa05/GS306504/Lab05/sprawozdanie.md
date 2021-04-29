## Lab 5: Jenkins as CI/CD driver

**Task:**

1. *familiarize yourself with the diagram discussed in class.*
2. *familiarize yourself with the Jenkins software: [https://www.jenkins.io/](https://www.jenkins.io/).*
3. *create a Jenkins Docker container using the instructions [https://www.jenkins.io/doc/book/installing/docker/](https://www.jenkins.io/doc/book/installing/docker/)*
4. *Upload your Jenkins image to DockerHub just like the previous images.*
5. *from within Jenkins running in a container (point 2) run docker-compose created within Lab04.*
- *we assume Jenkins is running in a container*
- *we assume that after Lab04 docker-compose.yaml file is in our repository*
- *we assume that from Jenkins we download the repo where our docker-compose.yaml file is*
- *assume Jenkins runs the docker-compose.yaml file and creates the environment with Lab04*
- *note that running docker-compose requires.yaml of the Docker software*

**Notes:**

- Created a bridge network in Docker using the following docker network create command

    `docker network create jenkins`

- In order to execute Docker commands inside Jenkins nodes, downloaded and run the *docker:dind* Docker image

```docker
docker run --name jenkins-docker --rm --detach \
  --privileged --network jenkins --network-alias docker \
  --env DOCKER_TLS_CERTDIR=/certs \
  --volume jenkins-docker-certs:/certs/client \
  --volume jenkins-data:/var/jenkins_home \
  --publish 2376:2376 docker:dind --storage-driver overlay2
```

- To customise official Jenkins Docker image created a Dockerfile:

```docker
FROM jenkins/jenkins:2.277.2-lts-jdk11
USER root
RUN apt-get update && apt-get install -y apt-transport-https \
       ca-certificates curl gnupg2 \
       software-properties-common
RUN curl -fsSL https://download.docker.com/linux/debian/gpg | apt-key add -
RUN apt-key fingerprint 0EBFCD88
RUN add-apt-repository \
       "deb [arch=amd64] https://download.docker.com/linux/debian \
       $(lsb_release -cs) stable"
RUN apt-get update && apt-get install -y docker-ce-cli
USER jenkins
RUN jenkins-plugin-cli --plugins "blueocean:1.24.6 docker-workflow:1.26"
```

- Built a new docker image from this Dockerfile

```docker
docker build -t myjenkins-blueocean:1.1 .
```

- Run new docker image as docker container

```docker
docker run --name jenkins-blueocean --rm --detach `
  --network jenkins --env DOCKER_HOST=tcp://docker:2376 `
  --env DOCKER_CERT_PATH=/certs/client --env DOCKER_TLS_VERIFY=1 `
  --publish 8080:8080 --publish 50000:50000 `
  --volume jenkins-data:/var/jenkins_home `
  --volume jenkins-docker-certs:/certs/client:ro `
  myjenkins-blueocean:1.1
```

- went to [localhost:8080](http://localhost:8080) to unlock jenkins
- created new jenkins job *freestyle* of type
- configured to execute the following shell scirpt as a build step:
```
cd Grupy/Grupa05/GS306504/Lab04
pwd
ls
docker --version
curl -L https://github.com/docker/compose/releases/download/1.1.0/docker-compose-`uname -s`-`uname -m` > /usr/local/bin/docker-compose
chmod +x /usr/local/bin/docker-compose
docker-compose --version
docker-compose up
```

