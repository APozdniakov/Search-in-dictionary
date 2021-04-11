#!/usr/bin/env bash
mkdir _build && cd _build
cmake ..
make
mv dictionary ../dictionary
cd ..
rm -rf _build
