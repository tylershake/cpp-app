# Example C++ Application

Welcome to **Example C++ Application**, a real life example C++ application!

The repository exists as a template for a C++ application or library. By utilizing this repository, you will be able to boostrap development of your application or library by not having to worry about directory structure, building, and documentation. Just utilize the template!

## Features

This template repository consists of many features to leverage to help boostrap your projects:

* Software autodocumentation using Doxygen
* Unit test implementation using Googletest
* Building the application via either CMake or GNU Make
* Building within a Docker container
* Building both applications and static libraries
* Using pesky config files

## Platforms

This template repository can be used on a variety of platforms. The current list of verified platforms are:

* Linux (Ubuntu 16.04)

## Requirements

These are the base requirements to build and use this example application:

* Boost
* CMake (optional)
* GNU Make (optional)
* Doxygen (optional)

## Build Instructions

The software and documentation can be built using two utilities: CMake and GNU Make. Please see their respective sections below.

### CMake

CMake is the preferred build utility for this program. To build the example application using CMake, navigate to the project root and execute the following commands.

```
mkdir build
cd build
cmake ..
make
make test
make docs
sudo make install
sudo ldconfig
```

### GNU Make

Alternatively, GNU Make can be used to build the program. To build the example application using GNU Make, navigate to the project root and execute the following commands.

```
make
make test
sudo make install
sudo ldconfig
```
