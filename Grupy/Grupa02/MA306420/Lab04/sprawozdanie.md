1. Utworzyłem nowy branch do pracy za pomocą polecenia `git checkout -b`
   1.1 Otagowałem obraz utworzony na poprzednich zajęciach jako `mafciejewiczow/devops:1.0`. Następnie zpushowałem go do serwisu dockerhub za pomocą polecenia `docker push`. Nie musiałem się logować do dockerhuba ponieważ zrobiłem to już wcześniej za pomocą interfejsu graficznego programu Docker Desktop.
2. Wybranym przeze mnie komunikatorem open source jest [feathers-chat](https://github.com/feathersjs/feathers-chat)
3. Utworzyłem dockerfile, które instaluje gita, klonuje repozytorium z aplikacją i instaluje jej zależności za pomocą npm. Aplikacja nie wymaga budowania.
4. Następnie utworzyłem dockerfile obrazu testowego, bazującego na obrazie zbudowanym przez poprzednie dockerfile. Ustala ono domyślną komendę kontenera na uruchamianie testów aplikacji.
5. Utworzyłem plik docker-compose.yml który definiuje dwie usługi: jedną uruchamiającą aplikację chatu bazując na obrazie z punktu trzeciego oraz drugi uruchamiający jej testy za pomocą obrazu z punktu 4
