#!/bin/bash

git add .
git commit -am "publi.sh"
git push

ndev commit arduinodk
ndev commit arduinodk-filter
ndev commit boor
ndev commit cliz
ndev commit nodejs-fu
ndev commit yoctojs
