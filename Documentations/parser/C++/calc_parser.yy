%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {CALC}
%define parser_class_name {CALC_Parser}

%code requires{
   namespace CALC {
      class CALC_Driver;
      class CALC_Scanner;
   }

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { CALC_Scanner  &scanner  }
%parse-param { CALC_Driver  &driver  }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for all driver functions */
   #include "calc_driver.hpp"

#undef yylex
#define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert

%token SELECT 
%token FIELD 
%token CHAR 
%token FROM 
%token WHERE 
%token COMPARAISON 
%token LOGIQUE 
%token AS 
%token END 
%token COMMENT
%token FORBBIDEN

%locations

%%
commands: command END
		{
			printf("commande valide\n");
			YYACCEPT;
		}
		| command END COMMENT
		{
			printf("commande valide\n");
			YYACCEPT;
		}
		;

command: SELECT selection FROM provenance condition_close | SELECT CHAR
		;

selection: ssrecherche ',' selection | ssrecherche
		;
		
ssrecherche: '(' command ')' 
		| FIELD AS field_ou_char 
		| FIELD
		;
		
provenance:	'(' command ')' AS FIELD 
		| FIELD AS FIELD
		| FIELD
		;
		
condition_close: 
		| WHERE condition
		;

condition: field_ou_char_ou_command COMPARAISON field_ou_char_ou_command LOGIQUE condition
		| field_ou_char_ou_command COMPARAISON field_ou_char_ou_command
		;

field_ou_char: FIELD 
		| CHAR
		;

field_ou_char_ou_command: field_ou_char
		| '(' command ')'
		;
%%


void 
CALC::CALC_Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}
