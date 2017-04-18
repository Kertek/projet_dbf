//
// Created by menguy on 21/03/17.
//

#include <cctype>
#include <fstream>
#include <sstream>

#include "calc_driver.h"

CALC::CALC_Driver::~CALC_Driver()
{
    delete(scanner);
    scanner = nullptr;
    delete(parser);
    parser = nullptr;
}

bool
CALC::CALC_Driver::parse(std::string String)
{
    std::istringstream in(String);
    if( ! in.good() )
    {
        exit( EXIT_FAILURE );
    }
    return parse_helper(in);
}

bool
CALC::CALC_Driver::parse_helper( std::istream &stream )
{

    delete(scanner);
    try
    {
        scanner = new CALC::CALC_Scanner( &stream );
    }
    catch( std::bad_alloc &ba )
    {
        std::cerr << "Failed to allocate scanner: (" <<
                  ba.what() << "), exiting!!\n";
        exit( EXIT_FAILURE );
    }

    delete(parser);
    try
    {
        parser = new CALC::CALC_Parser( (*scanner) /* scanner */,
                                        (*this) /* driver */ );
    }
    catch( std::bad_alloc &ba )
    {
        std::cerr << "Failed to allocate parser: (" <<
                  ba.what() << "), exiting!!\n";
        exit( EXIT_FAILURE );
    }
    const int accept( 0 );
    if( parser->parse() != accept )
    {
        std::cerr << "Parse failed!!\n";
        return false;
    }
    return true;
}

