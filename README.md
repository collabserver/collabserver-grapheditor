# CollabServer - Proof of Concept
[![release-version](https://img.shields.io/badge/release-no--release-red.svg)]()
[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collab-example-poc/blob/dev/LICENSE.txt)
> Work in progress.


# Install with CMake on GNU/Linux
- [CMake](https://cmake.org/)
- C++11
- Requires pragma support (pragma once)
- Automatically download and build [collab-client-interface](https://github.com/CollabServer/collab-client-interface.git)

```
git clone --recursive https://github.com/CollabServer/collab-example-poc.git
cd collab-example-poc
mkdir build
cd build
cmake ..
make -j4
make runClientPOC
```


# Author
Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))
