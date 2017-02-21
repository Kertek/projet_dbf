cmake_minimum_required(VERSION 3.6)
project(projet_dbf)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES DBFsrc/main.cpp DBFsrc/errno_dbf.h DBFsrc/SocketFactory.cpp DBFsrc/SocketFactory.h DBFsrc/SocketDbf.cpp DBFsrc/SocketDbf.h)
add_executable(projet_dbf ${SOURCE_FILES})