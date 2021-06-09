#!/bin/bash

docker build -t messenger-build:1.0 -f Dockerfile.build .
docker-compose build && docker-compose up -d
