cmake_minimum_required(VERSION 3.6)
project(projet_dbf)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES DBFsrc/main.cpp DBFsrc/errno_dbf.h DBFsrc/SocketFactory.cpp DBFsrc/SocketFactory.h DBFsrc/SocketDbf.cpp DBFsrc/SocketDbf.h DBFsrc/Connection.cpp DBFsrc/Connection.h DBFsrc/Config.h DBFsrc/processConnection.cpp DBFsrc/processConnection.h DBFsrc/Message.cpp DBFsrc/Message.h DBFsrc/TypeMessage.h)
add_executable(projet_dbf ${SOURCE_FILES})

target_link_libraries(projet_dbf
        pthread
        )