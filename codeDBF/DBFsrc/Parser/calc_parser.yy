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
#include <vector>
#include <algorithm>

/* include for all driver functions */
#include "calc_driver.h"

#undef yylex
#define yylex scanner.yylex

bool find_tautologies(std::vector<std::string> var);
}

%define api.value.type variant
%define parse.assert


%token <std::string> SELECT
%token <std::string> WILD
%token <std::string> FIELD
%token <std::string> CHAR
%token <std::string> FROM
%token <std::string> WHERE
%token <std::string> COMPARAISON
%token <std::string> LOGIQUE
%token <std::string> AS
%token END
%token COMMENT
%token FORBIDDEN

%type <std::string> command
%type <std::string> selection
%type <std::string> ssrecherche
%type <std::string> provenance
%type <std::string> condition_close
%type <std::string> condition
%type <std::string> field_ou_char
%type <std::string> field_ou_char_ou_command

%locations

%%
commands: command END
        {
        YYACCEPT;
        }
        ;

command: SELECT selection FROM provenance condition_close
		{
			$$ = $1 + $2 + $3 + $4 + $5;
		}
		| SELECT CHAR
		{
			$$ = $1 + $2;
		}
        ;

selection: ssrecherche ',' selection 
		{
			$$ = $1 + "," + $3;
		}
		| ssrecherche
		{
			$$ = $1;
		}
        ;

ssrecherche: '(' command ')' AS field_ou_char
		{
			$$ = "(" + $2 + ")" + $4 + $5;
		}
        | '(' command ')'
        {
			$$ = "(" + $2 + ")";
		}
        | FIELD AS field_ou_char
        {
			$$ = $1 + $2 + $3;
		}
        | FIELD
        {
			$$ = $1;
		}
        | WILD
        {
			$$ = $1;
		}
        ;

provenance:	'(' command ')' AS FIELD
		{
			$$ = "(" + $2 + ")" + $4 + $5;
		}
        | FIELD AS FIELD
        {
			$$ = $1 + $2 + $3;
		}
        | FIELD
        {
			$$ = $1;
		}
        ;

condition_close:
		{
			$$ = "";
		}
        | WHERE condition
        {
			$$ = $1 + $2;
		}
        ;

condition: field_ou_char_ou_command COMPARAISON field_ou_char_ou_command LOGIQUE condition
		{
			$$ = $1 + $2 + $3 + $4 + $5;
			if(!find_tautologies({$1,$2,$3,$4})){
				YYABORT;
			}
		}
        | field_ou_char_ou_command COMPARAISON field_ou_char_ou_command
        {
			$$ = $1 + $2 + $3;
			if(!find_tautologies({$1,$2,$3,""})){
				YYABORT;
			}
		}
        ;

field_ou_char: FIELD {$$ = $1;}
        | CHAR {$$ = $1;}
        ;

field_ou_char_ou_command: field_ou_char
		{
			$$ = $1;
		}
        | '(' command ')'
        {
			$$ = "(" + $2 + ")";
		}
        ;
%%


bool find_tautologies(std::vector<std::string> var){
	std::vector<std::vector<std::string>> DB = {{"1=1"},{"'l'='l'"}} ;
	std::string buffer;
	std::vector<std::string> T;
	std::cout << "coucou" << std::endl;
	if(var.size()!=4){
		return false;
	}
	for(int i =0 ; i < DB.size(); i++){
		if(std::find(DB[i].begin(), DB[i].end(), var[0]+var[1]+var[2]) != DB[i].end()){
			return false;
		}
	}
	if(var[3] == "OR"){ // LOGIQUE == OR
		T.push_back(buffer+var[0]+var[1]+var[2]);
		buffer = "";
	}
	else if(var[3] == "AND" || var[3] == ""){ // LOGIQUE == AND ou vide
		 buffer = buffer + var[0]+var[1]+var[2] + var[3];
	}
	else{
		return false;
	}
	for(int i=0; i< DB.size(); i++){
		bool notOrTautologie=false;
		for(int j =0; j< DB[i].size(); j++){
			if(std::find(T.begin(), T.end(), DB[i][j]) == T.end()){
				notOrTautologie=true;
			}
		}
		if(!notOrTautologie){
			return false;
		}
	}
	return true;
}

void
CALC::CALC_Parser::error( const location_type &l, const std::string &err_message )
{
    std::cerr << "Error: " << err_message << " at " << l << "\n";
}
