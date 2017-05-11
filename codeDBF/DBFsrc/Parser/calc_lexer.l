%{
/* C++ string header, for string ops below */
#include <string>
/* Implementation of yyFlexScanner */
#include "calc_scanner.h"
#undef  YY_DECL
#define YY_DECL int CALC::CALC_Scanner::yylex( CALC::CALC_Parser::semantic_type * const lval, CALC::CALC_Parser::location_type *loc )
/* typedef to make the returns for the tokens shorter */
using token = CALC::CALC_Parser::token;
/* define yyterminate as this instead of NULL */
#define yyterminate() return( token::END )
/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H
/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);
void comment();
%}

%option debug
%option nodefault
%option yyclass="CALC::CALC_Scanner"
%option noyywrap
%option c++


%%
%{          /** Code executed at the beginning of yylex **/
yylval = lval;
%}
"SELECT" |
"select"					{yylval->build<std::string>( yytext ); return token::SELECT;}
"FROM" 	 |
"from" 						{yylval->build<std::string>( yytext );return token::FROM;}
"WHERE"  |
"where"						{yylval->build<std::string>( yytext );return token::WHERE;}
"group by" |
"GROUP BY"					{yylval->build<std::string>( "GROUP BY" );return token::GROUP;}
"order by" |
"ORDER BY" 					{yylval->build<std::string>( "ORDER BY" ); return token::ORDER;}
"having" |
"HAVING"					{yylval->build<std::string>( "HAVING" ); return token::HAVING;}
"limit"  |
"LIMIT"						{yylval->build<std::string>( "LIMIT" ); return token::LIMIT;}
"offset" |
"OFFSET" 					{yylval->build<std::string>( "OFFSET" ); return token::OFFSET;}
"AS"     |
"as"						{yylval->build<std::string>( yytext );return token::AS;}
"and"	 |
"AND"	 					{yylval->build<std::string>( "AND" );return token::LOGIQUE;}
"or"	 |
"OR"	 					{yylval->build<std::string>( "OR" );return token::LOGIQUE;}
"UNION"	 |
"union"  					{yylval->build<std::string>( "UNION" );return token::UNION;}
"asc"	|
"ASC"						{yylval->build<std::string>( "ASC" );return token::TRI;}
"desc"	|
"DESC"						{yylval->build<std::string>( "DESC" );return token::TRI;}
"min"	|
"MIN"						{yylval->build<std::string>( "MIN" );return token::FUNC;}
"max"	|
"MAX"						{yylval->build<std::string>( "MAX" );return token::FUNC;}
"abs"	|
"ABS"						{yylval->build<std::string>( "ABS" );return token::FUNC;}
"upper"	|
"UPPER"						{yylval->build<std::string>( "UPPER" );return token::FUNC;}
"information_schema.tables"	|
"user()"					|
"version()"					|
"drop"						|
"DROP"						|
"sleep()"					|
"SLEEP()"					|
"sleep("[1-9]+")"			|
"SLEEP("[1-9]+")"			|
"create function"			|
"CREATE FUNCTION"			|
"into dumpfile"				|
"INTO DUMPFILE"				{return token::FORBIDDEN;}
"--"						{	/* Commentaire:
                                 * On retourne END pour dire
                                 * que la suite ne compte pas.
                                 * */
                                return token::COMMENT;
                            }
                        
[0-9]+						{yylval->build<std::string>( yytext );return token::NB;}
[a-zA-Z1-9$_]+				{yylval->build<std::string>( yytext );return token::FIELD;}
"`"[\x01-\x7F]+"`"			{yylval->build<std::string>( yytext );return token::FIELD; /** pour les charset etendu **/}
"*"                         {yylval->build<std::string>( yytext );return token::WILD;}
"\'"[a-zA-Z1-9@]*"\'"		{yylval->build<std::string>( yytext );return token::CHAR;}
'\0'                        {
                                /*Il faudra verifier que cela 
                                 * n'introduit pas une faille injection 
                                 * Null byte*/
                                return token::END;
                            }
","							{return *yytext;}
"("							{return *yytext;}
")"							{return *yytext;}

"=" 	|
"<=" 	|
">="	|
"<" 	|
">"		|
"!="    |
"<>"    {yylval->build<std::string>( yytext );return token::COMPARAISON;}
[ ]						 {;}

.		{/* Used for all the other characters */
			std::cout << "Forbbiden char" << std::endl;
			return token::FORBIDDEN;
		}

%%

void comment(){
    std::cout << "Il y a un commentaire" << std::endl;
}


