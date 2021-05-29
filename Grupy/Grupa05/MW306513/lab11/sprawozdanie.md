# Instalacja kubernetesa

```
$ sudo apt-get update -y
$ sudo apt-get upgrade -y
$ sudo apt-get install curl
$ sudo apt-get installl apt-transport-https
$ sudo apt install virtualbox virtualbox-ext-pack
$ wget https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
$ sudo cp minikube-linux-amd64 /usr/local/bin/minikube
sudo chmod 755 /usr/local/bin/minikube
```
# sprawdzenie czy jest ok
```commandline
    minikube version
```
![img.png](img.png)


# Instalacja Kubectl
```
curl -LO https://storage.googleapis.com/kubernetes-release/release/`curl -s https://storage.googleapis.com/kubernetes-release/release/stable.txt`/bin/linux/amd64/kubectl
chmod +x ./kubectl
sudo mv ./kubectl /usr/local/bin/kubectl
```

# sprawdzenie
```commandline
kubectl version -o json
```
![img_1.png](img_1.png)

# Odpalenie kubenetesa 
```commandline
minikube start
```
![img_2.png](img_2.png)

# dashboard
![img_3.png](img_3.png)

# uruchomienie kontenera w kubernetesie
![img_4.png](img_4.png)

```commandline
minikube kubectl -- run komunikator --image=node-chat-app-deploy:latest --port=9999 --labels app=komunikator
```

# kubenetes pod
![img_5.png](img_5.png)

# port forwarding
![img_7.png](img_7.png)

# pod w dashboardzie
![img_8.png](img_8.png)

# dzialajaca apka
![img_6.png](img_6.png)