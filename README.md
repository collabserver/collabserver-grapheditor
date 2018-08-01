# CollabServer - Proof of Concept

[![release-version](https://img.shields.io/badge/release-no--release-red.svg)]()
[![Build Status](https://travis-ci.org/CollabServer/collab-poc.svg?branch=master)](https://travis-ci.org/CollabServer/collab-poc)
[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collab-poc/blob/dev/LICENSE.txt)

| master | dev |
| :-----: | :----: |
| [![Build Status](https://travis-ci.org/CollabServer/collab-poc.svg?branch=master)](https://travis-ci.org/CollabServer/collab-poc) | [![Build Status](https://travis-ci.org/CollabServer/collab-poc.svg?branch=dev)](https://travis-ci.org/CollabServer/collab-poc) |


## Overview
> Work in progress.


## Requirements
- C++11
- `pragma once` support
- Tested with gcc 4.8.4
- Tested with clang 5.0.0
- Tested only on Linux. Not support certified for Mac and Windows


## Dependencies
> Dependencies marked with *(CMake)* are automatically downloaded by CMake
> script and placed in *bin* folder.
> Others must be installed manually (Generally system-wide install).
- [collab-client-interface](https://github.com/CollabServer/collab-client-interface.git) (CMake)
- [collab-data-crdts](https://github.com/CollabServer/collab-data-crdts.git) (CMake)
- [ZeroMQ](http://zeromq.org/) (**Must be installed system-wide**)
- Curl (**Must be installed System-wide**)


## Submodules
This project uses submodules to manage dependencies with the other collab
components used internally. You may need to work on these component and
this poc project at the same time and submodules are useful for that purpose. \\
For further information about submodules, check the official documentation:
https://git-scm.com/book/en/v2/Git-Tools-Submodules and
https://git-scm.com/docs/git-submodule.

### Clone with submodules
```bash
git clone --recursive https://github.com/CollabServer/collab-poc.git
```
### Pull new changes
Because of submodule, you should use the recursive argument of `pull`.
```bash
git pull --recurse-submodules=on
```
### Update submodules
```bash
git submodule update --remote
```


## Graphic Editor client
Graph editor is a command line tool to edit graph.
This is an example of end-user client that uses collab-data-crdts to
handle multi-users real-time collaboration.
Each vertex in the graph has a map of attributes: {name,value}.

### Build and run with CMake
```bash
mkdir build
cd build
cmake ..
make -j4
make runGrapheditor

# Or use build script
./build.sh
cd build
make runGrapheditor
```


## Mvk collab client (Modelverse)
Mvk is a database for Model-Driven Engineering models (MDE).
This is an example of client to a Mvk database in order to work with the
grapheditor client project.

### Setup Mvk
The Mvk is an external database that must be run separately.
Please refers to the official Mvk installation documentation:
https://msdl.uantwerpen.be/documentation/modelverse/installation.html#dependencies

### Run Mvk database
Once downloaded and setup, start the Mvk database.
```bash
python scripts/run_local_modelverse.py
```

### Build and run with CMake
**Mvk database must be running locally first**
```bash
mkdir build
cd build
cmake ..
make -j4
make runMvk

# Or use build script
./build.sh
cd build
make runMvk
```


## Author
- Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))
- Robin
- Thierry
