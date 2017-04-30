cmake_minimum_required(VERSION 3.6)
project(projet_dbf)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/Parser)
BISON_TARGET(calc_parser
        DBFsrc/Parser/calc_parser.yy
        ${PROJECT_SOURCE_DIR}/DBFsrc/Parser/calc_parser.tab.cc)
FLEX_TARGET(calc_lexer
        DBFsrc/Parser/calc_lexer.l
        ${PROJECT_SOURCE_DIR}/DBFsrc/Parser/calc_lexer.yy.cc)
ADD_FLEX_BISON_DEPENDENCY(calc_lexer calc_parser)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES DBFsrc/errno_dbf.h
        DBFsrc/SocketFactory.cpp DBFsrc/SocketFactory.h
        DBFsrc/SocketDbf.cpp DBFsrc/SocketDbf.h DBFsrc/Connection.cpp
        DBFsrc/Connection.h DBFsrc/Config.h DBFsrc/processConnection.cpp DBFsrc/processConnection.h
        DBFsrc/Message.cpp DBFsrc/Message.h DBFsrc/TypeMessage.h DBFsrc/Monitoring/LogManager.cpp
        DBFsrc/Monitoring/LogManager.h
        DBFsrc/Monitoring/TypeError.h
        DBFsrc/Monitoring/processLogger.cpp
        DBFsrc/Monitoring/processLogger.h
        DBFsrc/Parser/calc_driver.cpp
        ${FLEX_calc_lexer_OUTPUTS}
        ${BISON_calc_parser_OUTPUTS} DBFsrc/Monitoring/processLogger.cpp)

add_library(DBFsrc ${SOURCE_FILES})
add_executable(projet_dbf
        DBFsrc/main.cpp
        )

target_link_libraries(projet_dbf
        pthread
        DBFsrc
        )

add_subdirectory(DBFtest)

