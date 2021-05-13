#!/bin/sh

echo "Uruchamiamy Pipeline"
curl -X POST -L --user admin:key http://localhost:8080/job/wire-desktop-3/build
