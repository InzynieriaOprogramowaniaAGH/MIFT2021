#!/bin/sh

echo "Triggering jenkins pipeline"
curl -X POST -L --user admin:11b18c0eaee3e6da9fccf6dd070101bade http://localhost:8080/job/wire-desktop-3/build