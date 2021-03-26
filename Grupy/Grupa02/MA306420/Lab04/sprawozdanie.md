1. Utworzyłem nowy branch do pracy za pomocą polecenia `git checkout -b`
   1.1 Otagowałem obraz utworzony na poprzednich zajęciach jako `mafciejewiczow/devops:1.0`. Następnie zpushowałem go do serwisu dockerhub za pomocą polecenia `docker push`. Nie musiałem się logować do dockerhuba ponieważ zrobiłem to już wcześniej za pomocą interfejsu graficznego programu Docker Desktop.
2. Wybranym przeze mnie komunikatorem open source jest [Rocket.Chat](https://github.com/RocketChat/Rocket.Chat)
3. Utworzyłem dockerfile, które instaluje narzędzia wymagane do zbudowania niektórych zależności Rocket chatu, gita oraz odpowiednie certyfikaty; klonuje repozytorium aplikacji z githuba i uruchamia w nim komendy `npm ci` a potem `npm build`
