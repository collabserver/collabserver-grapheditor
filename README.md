# CollabServer - GraphEditor

[![release-version](https://img.shields.io/badge/release-no--release-red.svg)]()
[![Build Status](https://travis-ci.org/CollabServer/collab-grapheditor.svg?branch=master)](https://travis-ci.org/CollabServer/collab-grapheditor)
[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collab-grapheditor/blob/dev/LICENSE.txt)

| master | dev |
| :-----: | :----: |
| [![Build Status](https://travis-ci.org/CollabServer/collab-grapheditor.svg?branch=master)](https://travis-ci.org/CollabServer/collab-grapheditor) | [![Build Status](https://travis-ci.org/CollabServer/collab-grapheditor.svg?branch=dev)](https://travis-ci.org/CollabServer/collab-grapheditor) |


## Overview
Graph editor is a command line tool to edit graph.
This is an example of end-user client that uses collab-data-crdts to
handle multi-users real-time collaboration.
Each vertex in the graph has a map of attributes: {name,value}.


## Requirements
- C++11
- `pragma once` support
- Tested with gcc 4.8.4
- Tested with clang 5.0.0
- Tested only on Linux. Not support certified for Mac and Windows


## Dependencies
> Dependencies marked with *(CMake)* are automatically downloaded by CMake
> script and placed in *dependencies* folder.
> Others must be installed manually (Generally system-wide install).
- [collab-client-interface](https://github.com/CollabServer/collab-client-interface.git) (CMake / gitsubmodule)
- [collab-data-crdts](https://github.com/CollabServer/collab-data-crdts.git) (CMake / gitsubmodule)
- collab-common (CMake / gitsubmodule. Required by collab-client-interface)
- [ZeroMQ](http://zeromq.org/) (**Must be installed system-wide**)
- Curl (**Must be installed System-wide**)
- Moderlverse MVK (**Must be installed manually**)


## Submodules
This project uses submodules to manage dependencies with other CollabServer
project. For further information about submodules,
check the official documentation:
https://git-scm.com/book/en/v2/Git-Tools-Submodules and
https://git-scm.com/docs/git-submodule.

### Work with submodules
```bash
# Clone
git clone --recursive https://github.com/CollabServer/collab-grapheditor.git

# Pull new changes
git pull --recurse-submodules=on

# Update submodules
git submodule update --remote
```


## Build
### Build and run with CMake
```bash
mkdir build
cd build
cmake ..
make -j4
make run

# Or use build script
./build.sh
cd build
make run
```


## Modelverse Database (MVK)
Mvk is a database for Model-Driven Engineering models (MDE).

### Setup Mvk
The Mvk is an external database that must be run separately.
Please refers to the official Mvk installation documentation:
https://msdl.uantwerpen.be/documentation/modelverse/installation.html#dependencies

### Run Mvk database
Once downloaded and setup, start the Mvk database.
```bash
python scripts/run_local_modelverse.py
```


## Author
- Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))
- Robin
- Thierry
