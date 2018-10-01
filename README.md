# CollabServer - GraphEditor

[![license](https://img.shields.io/badge/license-LGPLv3.0-blue.svg)](https://github.com/CollabServer/collab-grapheditor/blob/dev/LICENSE.txt)
[![Build Status](https://travis-ci.org/CollabServer/collab-grapheditor.svg?branch=master)](https://travis-ci.org/CollabServer/collab-grapheditor)

| master | dev |
| :-----: | :----: |
| [![Build Status](https://travis-ci.org/CollabServer/collab-grapheditor.svg?branch=master)](https://travis-ci.org/CollabServer/collab-grapheditor) | [![Build Status](https://travis-ci.org/CollabServer/collab-grapheditor.svg?branch=dev)](https://travis-ci.org/CollabServer/collab-grapheditor) |


# Overview
GraphEditor is a command line tool for graph that supports realtime collaboration with several users.
Contributors may edit a graph at the same time, even with totally concurrent operations.
Concurrency is resolved without any locking or synchronization.


The goal of this project is to show an example of end-user client using the
CollabServer Framework.
It is built using the `collab-data-crdts` (SimpleGraph data structure) and,
`collab-client-interface` (Client interface to work with a collab-server).
All the "black magic" is done behind the scene and this project may be
done by an application / UI developer (Without any knowledge about collaboration and, concurrency).


# Quick Start
1. Goal
    - A running local CollabServer
    - A running grapheditor connected with CollabServer
    - Working on a graph in collaboration
1. Setup CollabServer
    - Be sure you have all the system-wide dependencies and requirements.
    - Clone [collab-server project](https://github.com/CollabServer/collab-server)
    - Build collab-server (See [Build server instructions](https://github.com/CollabServer/collab-server))
1. Setup GraphEditor
    - Be sure you have all the system-wide dependencies and requirements.
    - Clone this project
    - Build this project (Follow the build instructions)
1. Start GraphEditor (First client)
    - Open a console (Must be started from a console)
    - Run the grapheditor executable (You enter editor)
    - Use `help` or `h` to show all commands
    - Each command has a full name (ex: `vertexAdd`) and a short version (ex: `vadd`)
1. Create a Graph
    - `co localhost 4242` (connect your local CollabServer)
    - `crea` (Start a collaboration)
    - `info` (Display current status. You should be connected and data loaded)
    - `vadd v1` (Add a vertex v1)
    - `vadd v2` (Add a vertex v2)
    - `eadd v1 v2` (Add edge)
    - `aadd v1 name Panda`
    - `aadd v2 name Gnu`
    - `gshow` (Display the whole graph)
1. Start a second client
    - `co localhost 4242` (connect the same CollabServer)
    - `join 1` (join the previously created data. ID 1 is from `info` on first client)
    - `gshow` (You should see the exact same graph)
1. Collaborate
    - Apply any operation on any user and see the changes on others.
    - `arem v1 name` to remove attribute name from v1
    - `aset v2 name Raccoon` to change attribute value in v2


# Features
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
- Mvk Database (Optional)
    - Connect to MVK
    - Load data from MVK



# Build on Linux (CMake)
```bash
# Warning: Install system-wide dependencies
# Be sure you have all requirements

# Using cmake manual
mkdir build
cd build
cmake -DCOLLAB_DEPENDENCIES_DOWNLOAD=ON ..
make
make run # This start the grapheditor

# Or use build script
./build.sh
cd build
make run
```

| CMake option Name | Description |
| --- | --- |
| COLLAB_DEPENDENCIES_DIR | (STRING) Path to a directory where to find all dependencies (By default, uses current cmake build) |
| COLLAB_DEPENDENCIES_DOWNLOAD | (ON/OFF) Set ON to also download dependencies at cmake time. This is useful the first time you setup the project. Dependencies are placed in COLLAB_DEPENDENCIES_DIR. (By default: OFF).|
| CMAKE_BUILD_TYPE | Debug, Release, RelWithDebInfo, MinSizeRel |


# Requirements
- C++11
- `pragma once` support
- Tested with gcc 4.8.4
- Tested with clang 5.0.0
- Tested only on Linux. No support certified for Mac and Windows


# Dependencies
- System-Wide (**Must be installed manually**)
    - [ZeroMQ](http://zeromq.org/)
        - ArchLinux: `pacman -S zeromq`
        - Ubuntu: `apt-get install libzmq3 libzmq3-dev`
        - There is also a [Windows binary here](http://zeromq.org/distro:microsoft-windows) (Not tested yet)
    - [Curl](https://curl.haxx.se/)
- Automatically downloaded and built by CMake
    - [collab-client-interface](https://github.com/CollabServer/collab-client-interface.git)
    - [collab-data-crdts](https://github.com/CollabServer/collab-data-crdts.git)

**Option: save dependencies for offline use**
> Dependencies downloaded by CMake are placed in the current CMake build folder
> (in `dependencies` folder).
> This is useful the firs time.
> To speedup the cmake process, you may keep these downloaded and built dependencies
> in a safe place and change the CMake dependencies path (See CMake options).

**Option: use environment variable for dependencies path**
> If `COLLAB_DEPENDENCIES_DIR` environment variable is set, CMake will use
> it as the current dependencies path.


# Modelverse Database (Optional)
> Warning: Not fully functional yet. Don't use it in release.

Mvk is a database for Model-Driven Engineering and stores everything as an MDE model.

If an Mvk database is running, you may automatically save any changes done
on a graph during the collaboration.
CollabServer deals with users concurrency.

- Download Mvk (See [official install documentation](https://msdl.uantwerpen.be/documentation/modelverse/installation.html#dependencies))
- Run local Mvk database `python mvk_location/scripts/run_local_modelverse.py`


# Generate Documentation
1. Install [Doxygen](https://www.stack.nl/~dimitri/doxygen/)
1. `doxygen Doxyfile`
1. Files are placed in `doc` folder


# Contribution
Feel free to ask me any question, share your ideas or open an issue.
I created this project during my master thesis at University of Montreal.
I generally try to follow the [Google C++ Coding Style](https://google.github.io/styleguide/cppguide.html)
with some exceptions (For instance, I use 4 space indentation).

Uses C++11


# Authors
- Constantin Masson ([constantinmasson.com](http://constantinmasson.com/))
- Robin
- Thierry


