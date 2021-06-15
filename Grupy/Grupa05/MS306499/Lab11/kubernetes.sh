#!/bin/bash

minikube start
minikube kubectl -- get po -A
minikube dashboard
