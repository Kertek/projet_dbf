//
// Created by menguy on 21/03/17.
//

#ifndef PROJET_DBF_CALC_SCANNER_H
#define PROJET_DBF_CALC_SCANNER_H 1

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "calc_parser.tab.hh"
#include "location.hh"

namespace CALC{

    class CALC_Scanner : public yyFlexLexer{
    public:

        CALC_Scanner(std::istream *in) : yyFlexLexer(in)
        {
            loc = new CALC::CALC_Parser::location_type();
        };
        virtual ~CALC_Scanner() {
            delete loc;
        };

        //get rid of override virtual function warning
        using FlexLexer::yylex;

        virtual
        int yylex( CALC::CALC_Parser::semantic_type * const lval,
                   CALC::CALC_Parser::location_type *location );
        // YY_DECL defined in mc_lexer.l
        // Method body created by flex in mc_lexer.yy.cc


    private:
        /* yyval ptr */
        CALC::CALC_Parser::semantic_type *yylval = nullptr;
        /* location ptr */
        CALC::CALC_Parser::location_type *loc    = nullptr;
    };

} /* end namespace CALC */

#endif //PROJET_DBF_CALC_SCANNER_H
