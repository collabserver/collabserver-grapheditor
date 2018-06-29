#!/bin/bash

set -e
set -x
set -v

mkdir build || true
cd build

cmake -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
      -Dcollab_graphiceditor=ON \
      -Dcollab_mvk=ON \
      ..
make


