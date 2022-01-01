# Testing task for JetBrains Internship

This is a testing task for JetBrains Internship 2021: Unreal Editor project.
The task is to develop fast search in [dictionary](https://raw.githubusercontent.com/dwyl/english-words/master/words.txt) without freezes 

## Build & run

Run `build.sh` script to install necessary dependencies

* `build-essential` & `cmake` to build the application
* `CUrl` to download the dictionary
* `Qt` for GUI
* `gtest` to test complex functions

Then execute `./jb-rider-test-task [path-to-dictionary]` to run application.
By default, `path-to-dictionary` equals to `words.txt`
