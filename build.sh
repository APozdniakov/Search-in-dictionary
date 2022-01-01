#!/usr/bin/env bash
apt-get -yq update
xargs -a requirements.txt apt-get -yq install
mkdir _build &&
cd _build &&
cmake .. &&
make -j"$(nproc)" --silent &&
mv jb-rider-test-task ../ &&
cd .. &&
rm -rf _build
curl --silent --output words.txt https://raw.githubusercontent.com/dwyl/english-words/master/words.txt
