# Zad 1.1:
## 1.1.1.
Przełączenie na brancha z poprzednich zajęć i opublikowanie obrazu w Docker Hub:
```
git checkout Grupa05-JS283683_Lab03
sudo docker login
```

## 1.1.2. 
Spędzono trochę czasu na szukanie powodu dlaczego Docker pod Windowsem przestał poprawnie działać. Ostatecznym lekarstwem (po reinstalacjach WSL, Docker Desktop, docker na WSL, zmianach w ściezkach środowiskowych i )
okazalo się ręczne startowanie daemona dockerowego: `sudo service docker start` oraz późniejsze wywoływanie komend dockerowych BEZ SUDO (w przeciwieństwie do Dockera wykorzystywanego na natywnej instalacji Ubuntu).

Następnie po przełączeniu na gąłąź z poprzednich zajęć (lab3) zbudowano obraz:
`docker build . -t mift-lab03`

## 1.1.3. 
Nadanie tagu i push do dockerhub
```
docker images
docker tag mift-lab03 szumied/mift-lab03
docker push szumied/mift-lab03
```

# Zad 2: 
Wybranie komunikatora: Przełączono się ponownie na gałąź z laboratorium 4.
`git checkout Grupa05-JS283683_Lab04`
Do wykonannia laboratorium wykorzystano [node-chat-app](https://github.com/binhxn/node-chat-app) 

# Zad 3: 
## 3.1.
Przygotowanie Dockerfile, stworzono plik `workspace/build_agent/Dockerfile`
Poczatkowo obraz wymagał konfiguracji tzdata, dlatego uzupełniono Dockerfile o automatyzację tej konfiguracji:
```
FROM ubuntu:latest
ENV TIME_ZONE=Europe/Warsaw
RUN ln -snf /usr/share/zoneinfo/$TIME_ZONE /etc/localtime && echo $TIME_ZONE > /etc/timezone
RUN apt-get update
RUN apt-get install -y git npm
RUN git clone https://github.com/binhxn/node-chat-app.git
RUN cd node-chat-app; npm install
```
## 3.2.
`docker build -t build_agent . -f build_agent/Dockerfile`


# Zad 4:
Stworzono nowy obraz kontenera dockerowego (nowy Dokcerfile) i skonfigurowano go tak, aby był w stanie wykonać operację testowanie "komunikatora" korzystając ze zbudowanego wcześniej programu w pkt 3.
W pliku: test_agent/Dockerfile:

```
FROM build_agent
RUN npm test
```

stworzono obraz przy pomocy `docker build -t test_agent . -f test_agent/Dockerfile`

# Zad 5:
## 5.1.
Zainstalowano docker-compose:
`sudo curl -L "https://github.com/docker/compose/releases/download/1.29.0/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose; sudo chmod +x /usr/local/bin/docker-compose; `
Sprawdzoono poprawność instalacji:
` docker-compose --version`

Utworzono plik `workspace/docker-compose.yml` Przygotowano odpowiednią konfigurację:

```
version: '3.9'
services:
build_agent:
  container_name: lab04-chat-build
  image: build_agent
  build:
   context: .
   dockerfile: build_agent/Dockerfile
test_agent:
  container_name: lab04-chat-test
  image: test_agent
  build:
   context: .
   dockerfile: test_agent/Dockerfile
  depends_on:
  - build_agent
```

## 5.2.
Uruchomiono przygotowaną konfigurację poleceniem: `docker-compose up`