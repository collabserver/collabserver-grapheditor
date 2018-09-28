# CollabServer - GraphEditor

[![release-version](https://img.shields.io/badge/release-no--release-red.svg)]()
[![Build Status](https://travis-ci.org/CollabServer/collab-grapheditor.svg?branch=master)](https://travis-ci.org/CollabServer/collab-grapheditor)
[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collab-grapheditor/blob/dev/LICENSE.txt)

| master | dev |
| :-----: | :----: |
| [![Build Status](https://travis-ci.org/CollabServer/collab-grapheditor.svg?branch=master)](https://travis-ci.org/CollabServer/collab-grapheditor) | [![Build Status](https://travis-ci.org/CollabServer/collab-grapheditor.svg?branch=dev)](https://travis-ci.org/CollabServer/collab-grapheditor) |


## Overview
GraphEditor is a command line tool for graph.
This is an example of end-user client that uses collab-data-crdts to
handle multi-users real-time collaboration.
Each vertex in the graph has a map of attributes: {name,value}.


## Quick Start
1. Start a CollabServer (See [CollabServer project](https://github.com/CollabServer/collab-server))
1. Be sure you have all the system-wide dependencies and requirements.
1. Build this grapheditor project (See build instruction)
1. Run one grapheditor (You enter the command line mode)
1. Use `help` in editor to show all commands
1. Each command has a fullname (ex: `vertexAdd`) and a short version (ex: `vadd`)
1. In the editor, do the following commands
    - `help` or `h` to display help
    - `co localhost 4242` to connect your local CollabServer
    - `crea` to start a collaboration
    - `info` to display current status (You should be connected and data loaded)
    - `vadd v1` add a vertex 1
    - `vadd v2` add a vertex 2
    - `eadd v1 v2` add edge
    - `aadd v1 name Panda`
    - `aadd v2 name Gnu`
    - `gshow` to display the whole graph
1. On another console, run a second grapheditor
    - `co localhost 4242` connect the same CollabServer
    - `join 1` join the previously created data (It's the first data so ID is 1)
    - `gshow` you should see the exact same graph
1. Apply other operation on any user and see the changes on others.
    - `arem v1 name` to remove attribute name from v1
    - `aset v2 name Raccoon` to change attribute value in v2


## Features
- Graph editing
    - Add vertex
    - Remove vertex
    - Add edge between two vertices
    - Remove edge
    - Add vertex attribute
    - Remove vertex attribute
    - Change vertex attribute value
- Graph info
    - List all vertices
    - Show vertex info
    - Show all graph
- CollabServer
    - Connect
    - Disconnect
    - Create new collaborative data
    - Join existing collaborative data
    - Leave collaborative data


## Build instructions (CMake)

### Requirements
- C++11
- `pragma once` support
- Tested with gcc 4.8.4
- Tested with clang 5.0.0
- Tested only on Linux. Not support certified for Mac and Windows

### Dependencies
All dependencies are automatically downloaded by CMake and placed in a folder
named `dependencies`.
You may move this folder in another place later and request CMake not to
download dependencies anymore (**See CMake options**).

If you are using a custom permanent location for your dependencies, a convenient
solution is to set the environment variable `COLLAB_DEPENDENCIES_DIR` with this path.
CMake will use this one as the default location (Except if a custom path is
given as CMake parameter).

- [collab-client-interface](https://github.com/CollabServer/collab-client-interface.git)
- [collab-data-crdts](https://github.com/CollabServer/collab-data-crdts.git)

### Manual dependencies (System Wide)
These dependencies **must be installed system-wide** and are not downloaded by CMake.
Check the instruction specific to your operating system for further information.
(Ex: `pacman -S zeromq` on ArchLinux)

- [ZeroMQ](http://zeromq.org/)
- [Curl](https://curl.haxx.se/)
- Moderlverse MVK (Optional. Only if you need it. See instructions)

### CMake options
| Name | Description |
| --- | --- |
| COLLAB_DEPENDENCIES_DIR | (STRING) Path to a directory where to find all dependencies (By default, uses current cmake build) |
| COLLAB_DEPENDENCIES_DOWNLOAD | (ON/OFF) Set ON to also download dependencies at cmake time. This is useful the first time you setup the project. Dependencies are placed in COLLAB_DEPENDENCIES_DIR. (By default: OFF).|
| CMAKE_BUILD_TYPE | Debug, Release, RelWithDebInfo, MinSizeRel |

### Build and run with CMake
```bash
mkdir build
cd build
cmake -DCOLLAB_DEPENDENCIES_DOWNLOAD=ON ..
make -j2
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


## Generate documentation
- [Doxygen](https://www.stack.nl/~dimitri/doxygen/)

Generate documentation with `doxygen Doxyfile`.
Generated files are places in `doc` folder.


## Contribution
Feel free to ask me any question, share your ideas or open an issue.
I created this project during my master thesis at University of Montreal.
I generally try to follow the [Google C++ Coding Style](https://google.github.io/styleguide/cppguide.html)
with some exceptions (For instance, I use 4 space indentation).


## Author
- Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))
- Robin
- Thierry


