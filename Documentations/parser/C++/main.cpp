#include <iostream>
#include <cstdlib>
#include <cstring>

#include "calc_driver.hpp"

int 
main( const int argc, char **argv )
{
   /** check for the right # of arguments **/
   if( argc == 2 )
   {
      CALC::CALC_Driver driver;
      /** simple help menu **/
      if( std::strncmp( argv[ 1 ], "-h", 2 ) == 0 )
      {
         std::cout << "use -o for pipe to std::cin\n";
         std::cout << "just give a filename to count from a file\n";
         std::cout << "use -h to get this menu\n";
         return( EXIT_SUCCESS );
      }
      /** example reading input from a string **/
      else
      {
         /** assume string, prod code, use stat to check **/
         std::string S=argv[1];
         driver.parse( S );
      }
   }
   else
   {
      /** exit with failure condition **/
      return ( EXIT_FAILURE );
   }
   return( EXIT_SUCCESS );
}
