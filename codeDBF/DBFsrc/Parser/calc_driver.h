//
// Created by menguy on 21/03/17.
//

#ifndef PROJET_DBF_CALC_DRIVER_H
#define PROJET_DBF_CALC_DRIVER_H 1

#include <string>
#include <cstddef>
#include <istream>

#include "calc_scanner.h"
#include "calc_parser.tab.hh"

namespace CALC{

    class CALC_Driver{
    public:
        CALC_Driver() = default;

        virtual ~CALC_Driver();

        /**
         * parse - parse from a std::string
         * @param String - A std::string
         */

        bool parse(std::string string);

        //std::ostream& print(std::ostream &stream);
    private:

        bool parse_helper( std::istream &stream );

        CALC::CALC_Parser  *parser  = nullptr;
        CALC::CALC_Scanner *scanner = nullptr;

    };

} /* end namespace CALC */


class calc_driver {

};


#endif //PROJET_DBF_CALC_DRIVER_H
