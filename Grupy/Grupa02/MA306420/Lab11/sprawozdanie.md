1. Zainstalowałem kubectl oraz minikube za pomocą package managera chocolatey
2. Uruchomiłem minikube za pomocą komendy `minikube start` oraz otwarłem dashboard za pomocą komendy `minikube dashboard`
3. Za pomocą minikube dashboard można zrobić bardzo wiele rzeczy związanej z zarządzaniem klastrem oraz działającymi w nim aplikacjami, m.in.:
     - Sprawdzić stan podów, replik i deploymentów działających w klastrze
     - Przejrzeć logi poszczególnych podów
     - Usunąć pod, deployment
     - Edytować właściwości usług, deploymentów, podów
1. W celu uruchomienia aplikacji chatu w klastrze kubernetes zbudowałem obraz uruchomieniowy za pomocą komendy `docker build` na podstawie 2 dockerfile które znajdowały się w repozytorium z chatem. Następnie otagowałem zbudowany obraz i wrzuciłem go na dockerhub za pomocą komend `docker tag` i `docker push`. Następnie utworzyłem nowy deployment na klastrze, używając obrazu z dockerhuba, za pomocą komendy `kubectl create deployment feathers-chat --image=mafciejewiczow/feathers-chat:latest`.
2. Próbowałem udostępnić aplikację za pomocą komendy `kubectl expose deployment`, ale niestety nie udawało mi się załadować aplikacji w przeglądarce po użyciu tej komendy. Użyłem `kubectl port-forward` zamiast tego.
