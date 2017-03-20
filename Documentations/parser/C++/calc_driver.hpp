#ifndef __CALCDRIVER_HPP__
#define __CALCDRIVER_HPP__ 1

#include <string>
#include <cstddef>
#include <istream>

#include "calc_scanner.hpp"
#include "calc_parser.tab.hh"

namespace CALC{

class CALC_Driver{
public:
   CALC_Driver() = default;

   virtual ~CALC_Driver();
   
   /** 
    * parse - parse from a file
    * @param filename - valid string with input file
    */
   void parse( const char * const filename );
   /** 
    * parse - parse from a c++ input stream
    * @param is - std::istream&, valid input stream
    */
   void parse( std::istream &iss );

   std::ostream& print(std::ostream &stream);
private:

   void parse_helper( std::istream &stream );

   CALC::CALC_Parser  *parser  = nullptr;
   CALC::CALC_Scanner *scanner = nullptr;
 
};

} /* end namespace CALC */
#endif /* END __CALCDRIVER_HPP__ */
