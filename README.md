# CollabServer - Proof of Concept
[![release-version](https://img.shields.io/badge/release-no--release-red.svg)]()
[![Build Status](https://travis-ci.org/CollabServer/collab-example-poc.svg?branch=master)](https://travis-ci.org/CollabServer/collab-example-poc)
[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collab-example-poc/blob/dev/LICENSE.txt)

| master | dev |
| :-----: | :----: |
| [![Build Status](https://travis-ci.org/CollabServer/collab-example-poc.svg?branch=master)](https://travis-ci.org/CollabServer/collab-example-poc) | [![Build Status](https://travis-ci.org/CollabServer/collab-example-poc.svg?branch=dev)](https://travis-ci.org/CollabServer/collab-example-poc) |


# Overview
> Work in progress.


# Feature
- client: example of client implementation


# Install with CMake on GNU/Linux
- [CMake](https://cmake.org/)
> Be sure to check the dependency requirements first.

```
git clone --recursive https://github.com/CollabServer/collab-example-poc.git
cd collab-example-poc
mkdir build
cd build
cmake ..
make -j4
make runClientPOC
```


# Dependencies and requirements
> Dependencies marked with (CMake) are automatically downloaded by CMake script.
> Others must be installed manually (Generally system-wide install).

- Build with C++11 (tested with gcc 4.8.4 and higher and clang 5.0.0)
- Requires pragma support (pragma once)
- [collab-client-interface](https://github.com/CollabServer/collab-client-interface.git) (CMake)
- [ZeroMQ](http://zeromq.org/) (Must be installed system-wide)


# Author
Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))
