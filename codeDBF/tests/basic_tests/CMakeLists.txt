
include_directories(${PROJECT_SOURCE_DIR} ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../../DBFsrc/Parser)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)
BISON_TARGET(calc_parser
        ../../DBFsrc/Parser/calc_parser.yy
        ../../DBFsrc/Parser/calc_parser.tab.cc)
FLEX_TARGET(calc_lexer
        ../../DBFsrc/Parser/calc_lexer.l
        ../../DBFsrc/Parser/calc_lexer.yy.cc)
ADD_FLEX_BISON_DEPENDENCY(calc_lexer calc_parser)

set(SOURCES ../../DBFsrc/errno_dbf.h ../../DBFsrc/SocketFactory.cpp ../../DBFsrc/SocketFactory.h
        ../../DBFsrc/SocketDbf.cpp ../../DBFsrc/SocketDbf.h ../../DBFsrc/Connection.cpp ../../DBFsrc/Connection.h
        ../../DBFsrc/Config.h ../../DBFsrc/processConnection.cpp ../../DBFsrc/processConnection.h ../../DBFsrc/Message.cpp
        ../../DBFsrc/Message.h ../../DBFsrc/TypeMessage.h ../../DBFsrc/Monitoring/Logger.h ../../DBFsrc/Monitoring/LoggerConsole.h
        ../../DBFsrc/Monitoring/LoggerFile.h)


add_executable(runBasicTests
        MainTests.cpp
        ${SOURCES}
        ../../DBFsrc/Parser/calc_driver.cpp

        ${BISON_calc_parser_OUTPUTS}
        ${FLEX_calc_lexer_OUTPUTS}
        test1.cpp

        )


target_link_libraries(runBasicTests gtest gtest_main)
