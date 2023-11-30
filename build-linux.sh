#!/bin/bash
premake5 gmake
pushd generated
make
popd
