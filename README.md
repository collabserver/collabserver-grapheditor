# CollabServer - Proof of Concept

[![release-version](https://img.shields.io/badge/release-no--release-red.svg)]()
[![Build Status](https://travis-ci.org/CollabServer/collab-example-poc.svg?branch=master)](https://travis-ci.org/CollabServer/collab-example-poc)
[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collab-example-poc/blob/dev/LICENSE.txt)

| master | dev |
| :-----: | :----: |
| [![Build Status](https://travis-ci.org/CollabServer/collab-example-poc.svg?branch=master)](https://travis-ci.org/CollabServer/collab-example-poc) | [![Build Status](https://travis-ci.org/CollabServer/collab-example-poc.svg?branch=dev)](https://travis-ci.org/CollabServer/collab-example-poc) |


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
- [ZeroMQ](http://zeromq.org/) (Must be installed system-wide)


## Build instructions

### Clone project with dependencies
```bash
git clone --recursive https://github.com/CollabServer/collab-poc.git
cd collab-poc
```

### Build and run with CMake
```bash
# Manual instructions
mkdir build
cd build
cmake ..
make -j4
make runGrapheditor
# or runMvk for db server

# With build script
./build.sh
cd build
make runGrapheditor
# or runMvk for db server
```


## Author
Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))
