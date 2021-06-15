|1| Uruchomiono klaster Kubernetes podobnie jak podczas laboratorium 11.

```
sudo services docker start
minikube start
minikube kubectl -- get pods -A
```

|2| Uruchomiono dashboard poleceniem `minikube dashboard` i upewniono się, że działa.

|3| Zapoznano się z dokumentacją tworzenia manifestów dla obiektów "Deployment" 

|4| Stworzono plik komunikator-deployment.yaml zgodnie z powyższą dokumentacją, ale zawierający:
    * nazwa: komunikator-deployment
    * app: komunikator
    * obraz z komunikatorem tak jak na poprzednich zajęciach
    * 4 repliki

|5| Zlecono klastrowi zrealizowanie powyższzego pliku używając polecenia: ` kubectl apply --filename=./komunikator-deployment.yaml`

|6| Udokumentowano stan klastra zrzutem ekranu

|7| Wprowadzono zmiane w pliku .yaml - zmieniono ilosc replik na 2, zlecono klastrowi aktualizację.

|8|  Udokumentowano nowy stan klastra zrzutem ekranu.