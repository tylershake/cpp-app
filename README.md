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

## Software Build Instructions

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

## Docker Build Instructions

The software and documentation can also be built inside a docker container. The currently dockerfile is derived from an nginx container to host the doxygen autodocumentation. To build the container, follow the instructions below.

To build the container from scratch, navigate to the project root and execute the following command, replacing [version] with the correct project version:

```
docker build --no-cache=true -t "cpp-app:[version]" .
```

To run the container, execute the following command, replacing [version] with the correct project version:

```
docker run -p 80:80 cpp-app:[version]
```

To run the container and open up a shell, execute the following command, replacing [version] with the correct project version:

```
docker run -p 80:80 -it python-app:[version] bash
```

The preferred method of running the container is via docker-compose. Include the following in your docker-compose file to connect this container with your other infrastructure.

```
TODO
```

## Templates Notes

When utilizing the template, there are a few things to keep in mind as you develop your application or library.

### Version Strings

Version strings are hidden throughout the project. When tagging your project at various version, be sure to update the version strings in the following places to match.

* CMakeLists.txt in project root (if using CMake)
* Doxyfile in project root (if using GNU Make)
* config.hpp in config directory (if using GNU Make)
* Docker container tag (if building a docker container)
