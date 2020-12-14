# collabserver - GraphEditor

[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/collabserver/collabserver-grapheditor/blob/dev/LICENSE.txt)
[![Build Status](https://travis-ci.org/collabserver/collabserver-grapheditor.svg?branch=master)](https://travis-ci.org/collabserver/collabserver-grapheditor)

| master | dev |
| :-----: | :----: |
| [![Build Status](https://travis-ci.org/collabserver/collabserver-grapheditor.svg?branch=master)](https://travis-ci.org/collabserver/collabserver-grapheditor) | [![Build Status](https://travis-ci.org/collabserver/collabserver-grapheditor.svg?branch=dev)](https://travis-ci.org/collabserver/collabserver-grapheditor) |

## Overview

---

GraphEditor is a command line tool to edit graphs in realtime collaboration.
Contributors may edit the same graph concurrency, without any needs of synchronization or locking.
This is achieved using the CollabServer Framework.

## Quick Start

---

1. Goal
    - A running local CollabServer
    - A running grapheditor connected with CollabServer
    - Working on a graph with concurrent users
1. Setup CollabServer
    - Be sure you have all the requirements
    - Clone the [collabserver-server](https://github.com/collabserver/collabserver-server) project
    - Build the server (see [build instructions](https://github.com/collabserver/collabserver-server))
1. Setup GraphEditor
    - Be sure you have all the requirements
    - Clone this project
    - Build this project (follow the build instructions)
1. Start GraphEditor (client 1)
    - Open a console
    - Run the grapheditor executable (created from the build)
    - Use `help` or `h` to show all commands
    - Each command has a full name (ex: `vertexAdd`) and a short version (ex: `vadd`)
1. Create a Graph
    - `co localhost 4242` (connect your local CollabServer)
    - `crea` (start a collaboration)
    - `info` (display the current status. You should be connected and data loaded)
    - `vadd v1` (add a vertex v1)
    - `vadd v2` (add a vertex v2)
    - `eadd v1 v2` (add edge)
    - `aadd v1 name Panda`
    - `aadd v2 name Gnu`
    - `gshow` (display the whole graph)
1. Start GraphEditor (client 2)
    - Do the same steps as for client 1
    - `co localhost 4242` (connect the same CollabServer)
    - `join 1` (join the previously created data. ID 1 is from `info` on first client)
    - `gshow` (you should see the exact same graph)
1. Collaborate
    - Apply any operation on any user and see the changes on others.
    - Example: `arem v1 name` to remove attribute name from v1
    - Example: `aset v2 name Raccoon` to change attribute value in v2

## Features

---

- SimpleGraph
  - A full example of custom data built using the CollabServer framework
  - All graph operations are CRDT
- Graph Data
  - vertex
    - ID name (String)
    - Edges (Set)
    - Attributes (Map)
  - Edge
    - ID source (String)
    - ID destination (String)
  - Attribute
    - Name (String)
    - Value (String)
- Graph Editing
  - Add vertex
  - Remove vertex
  - Add edge between two vertices
  - Remove edge
  - Add vertex attribute
  - Remove vertex attribute
  - Change vertex attribute value
- Graph Info
  - List all vertices
  - Show vertex info
  - Show all graph
- CollabServer
  - Connect
  - Disconnect
  - Create new collaborative data
  - Join existing collaborative data
  - Leave collaborative data
- Mvk persistent storage (Optional)
  - Connect to MVK
  - Load data from MVK

## Build (CMake)

---

- Requirements
  - [CMake](https://cmake.org/)
  - C++11
  - `pragma once` support
  - Tested with gcc 4.8.4
  - Tested with clang 5.0.0
  - Tested only on Linux. No support certified for Mac and Windows
- Dependencies (already in the repo and built by CMake)
  - [collabserver-client](https://github.com/collabserver/collabserver-client)
  - [collabserver-datatypes](https://github.com/collabserver/collabserver-datatypes)
  - [MessagePack](https://msgpack.org/)
  - [GoogleTest](https://github.com/google/googletest)
- Dependencies (**Must be installed on the system**)
  - [Curl](https://curl.haxx.se/)

```bash
# Build the tests

mkdir build
cd build
cmake -DCOLLABSERVER_CLIENT_TESTS=ON ..
make
make runTests

# Or use the build script
./build.sh
```

| CMake option | Description |
| --- | --- |
| COLLABSERVER_CLIENT_TESTS | (ON / OFF) Set ON to build unit tests |
| CMAKE_BUILD_TYPE | Debug, Release, RelWithDebInfo, MinSizeRel |

## Modelverse persistant storage (Optional)

---

**Warning: Not fully functional (only used as a code example).**

Mvk is persistent storage for Model-Driven Engineering and stores everything as an MDE model.
If an Mvk is running, you may automatically save any changes done on a graph during the collaboration.
CollabServer deals with users concurrency.

- Download Mvk (See [official install documentation](https://msdl.uantwerpen.be/documentation/modelverse/installation.html#dependencies))
- Run local Mvk `python mvk_location/scripts/run_local_modelverse.py`

## Generate Documentation

---

1. Install [Doxygen](https://www.stack.nl/~dimitri/doxygen/)
1. Run `doxygen Doxyfile`
1. Files are placed in `doc` folder

## Contribution

---

Feel free to ask me any question, share your ideas or open an issue.
I started this project during my master thesis at University of Montreal.
Format uses clang-format with the Google Coding style <https://google.github.io/styleguide/cppguide.html> (see `.clang-format` for further information).
Make sure you autoformat on save (see <https://clang.llvm.org/docs/ClangFormat.html>)
