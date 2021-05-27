1. Przygotowano kontener uzyskany w czasie poprzednich zajęć (szumied/node_chat_starter)
2. Podążając krokami wskazanymi na stronie https://minikube.sigs.k8s.io/docs/start/ zainstalowano minikube/kubectl  wybierając konfigurację Linux x86-64 Binary Download, polecenia:
- `curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64`
- `sudo install minikube-linux-amd64 /usr/local/bin/minikube`
Przy pomocy kolejnych komend uruchomiono klaster: `minikube start`i pobrano kubectl: `minikube kubectl -- get po -A`.

3. Uruchomiono Dashboard poleceniem `minikube dashboard` i uruchomiono wypisany adres w przeglądarce.

3.1. Pobieżnie zapoznano się z interfejsem Dashboarda (na pierwszym screenie dashboarda widoczne są 4 wykresy workload związane z początkowymi próbami rozwiązania napotkanych problemów najróżniejszymi komendami; po rozwiązaniu problemu leżącego po stronie obrazu kontenera posprzątano i zostawiono tylko to, co trzeba do wykonania laboratorium)

4. Uruchomiono teraz kontener-komunikator w Kubernetes wykorzystując lekko zmodyfikowaną wersję polecenia z instrukcji (konieczne było dodanie `minikube` na początku oraz bardziej podchwytliwe - dodanie `--`)
```
minikube kubectl -- run komunikatorio --image=szumied/node_chat_starter --port=9999 --labels app=komunikatorio
minikube kubectl port-forward komunikatorio 9996:3000
```

5. Nastepnie upewniono się, ze komunikator działa w klastrze i zbadano jego status w dashboardzie, gdzie wszystko również było prawidłowe.