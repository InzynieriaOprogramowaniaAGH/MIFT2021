1. Uruchomiłem minikube i otwarłem dashboard za pomocą polecenia `minikube dashboard`
2. Stworzyłem plik opisujący deployment wybranej przeze mnie aplikacji z chatem, na podstawie przykładowego pliku obecnego w dokumentacji pluków konfiguracyjnych kubernetes
3. Zleciłem zrealizowanie tego deploymentu za pomocą polecenia `kubectl apply -f komunikator-deployment.yaml`
4. Następnie zmodyfikowałem plik, zmieniając rządaną liczbę replik z 4 na 2. Zaaplikowałem zmiany w deploymencie za pomocą takiego samego polecenia jak w punkcie 3.
