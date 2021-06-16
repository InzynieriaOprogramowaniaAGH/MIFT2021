1. uruchomiłem lokalnie klaster Kubernetes (kubectl oraz Minikube) (jak w lab 11)

2. uruchomiłem dashboarda

3. Zapoznałem się z dokumentacją tworzenia manifestów dla obiektow: Deployment

4. Stworzyłem plik komunikator-deployment.yaml, który zawierał:
   name: komunikator-deployment
   app: komunikator
   obraz z komunikatorem tak jak na poprzednich zajęciach
   replicas: 4

  zawrtość pliku yaml:
  
    apiVersion: apps/v1
    kind: Deployment
    metadata:
    name: komunikator-deployment
    labels:
        app: komunikator
    spec:
    replicas: 4
    selector:
        matchLabels:
        app: komunikator
    template:
        metadata:
        labels:
            app: komunikator
        spec:
        containers:
        - name: komunikator-deployment
            image: wiktorligeza/socketio:messenger
            ports:
            - containerPort: 9999
  	
5. uruchomienie pliku yaml komenda:
	kubectl apply -f komunikator-deployment.yaml

6. zmiana liczby replik z 4 na 5.

7. sprawdzenie dashboarda
