0. Zapoznano się z diagramem omawinaym na zajęciach

1. Zapoznano się z oprogramowaniem Jenkins.

2. Stworzono kontener dockerowy z Jenkinsem posługując się instrukcją https://www.jenkins.io/doc/book/installing/docker/

Stworzono sieć:
`docker network create jenkins`

Pobrano i uruchomiono obraz `docker:dind`:
```
docker run \
  --name jenkins-docker \
  --rm \
  --detach \
  --privileged \
  --network jenkins \
  --network-alias docker \
  --env DOCKER_TLS_CERTDIR=/certs \
  --volume jenkins-docker-certs:/certs/client \
  --volume jenkins-data:/var/jenkins_home \
  --publish 2376:2376 \
  docker:dind \
  --storage-driver overlay2
```

Po stworzeniu Dockerfile'a, zbudowano kontener: `docker build -t myjenkins-blueocean:1.1 .`

A potem uruchomiłem go kolejnym porządnie długim poleceniem:
```
docker run --name jenkins-blueocean --rm --detach \
  --network jenkins --env DOCKER_HOST=tcp://docker:2376 \
  --env DOCKER_CERT_PATH=/certs/client --env DOCKER_TLS_VERIFY=1 \
  --publish 8080:8080 --publish 50000:50000 \
  --volume jenkins-data:/var/jenkins_home \
  --volume jenkins-docker-certs:/certs/client:ro \
  myjenkins-blueocean:1.1
```

3. `docker push szumied/myjenkins-blueocean:1.1`
napotkano problem, jako że Docker nie mógł odnaleźć podanego obrazu:
```
docker images
docker tag 87e7f581032e szumied/myjenkins-blueocean:1.1`
```

4. Z poziomu Jenkinsa uruchomionego w kontenerze uruchomiono docker-compose stworzony w ramach Lab04:
Uzyskanie CONTAINER ID: `docker container ls` -> fddc802d5ec7
`docker logs fddc802d5ec7`
Powrócono pod adres `localhost:8080` i uzyskanym hasłem zalogowano się do panelu administratora. Pojawił się prompt wskazujący możliwość zainstalowania pluginów. 

Doinstalowano plugin Groovy oraz PowerShell dla wygody przygotowania Jenkinsfile'a. `sudo docker exec -u root -it jenkins-blueocean bash`
w kontenerze:
```
curl -L "https://github.com/docker/compose/releases/download/1.29.0/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose; chmod +x /usr/local/bin/docker-compose;
```

Utworzono pipeline, zapisano discardownaie historii więcej niż dwóch buildów, żeby nie zaśmiecać pamięci.
Przygotowano prostego Jenkinsfile'a do konfiguracji pipeline'u:

```groovy
node {
    def workspacePath = 'Grupy/Grupa05/JS283683/Lab04/workspace' 
    def repoUrl = 'https://github.com/InzynieriaOprogramowaniaAGH/MIFT2021/'

    stage('Preparation: SCM'){ 
        checkout([$class: 'GitSCM',
          branches: [[name: 'Grupa05']],
          extensions: [],
          userRemoteConfigs: [[url: repoUrl]]])
    }
    stage('StartUp') {
        script {
            dir(workspacePath) {
                pwsh script: """
                    pwd; tree
                    docker-compose up
                """, label: "Running `docker-compose up` from PowerShell Core"
            } 
        }
    }
}
```

Build z powyższą konfiguracją uruchomiono i pomyślnie przeszedł wszystkie kroki.