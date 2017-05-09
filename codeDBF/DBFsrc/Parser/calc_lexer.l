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
"AS"     |
"as"						{yylval->build<std::string>( yytext );return token::AS;}
"and"	 |
"AND"	 					{yylval->build<std::string>( "AND" );return token::LOGIQUE;}
"or"	 |
"OR"	 					{yylval->build<std::string>( "OR" );return token::LOGIQUE;}
"UNION"	 |
"union"  					{yylval->build<std::string>( "UNION" );return token::UNION;}
"information_schema.tables"	|
"user()"					|
"version()"					|	
"sleep()"					|
"SLEEP()"					|
"sleep("[1-9]+")"			|
"SLEEP("[1-9]+")"			|
"create function"			|
"CREATE FUNCTION"			|
"into dumpfile"				|
"INTO DUMPFILE"				{return token::FORBIDDEN;}
"--"						{/* Commentaire */
                                comment();
                                /*
                                 * On retourne END pour dire
                                 * que la suite ne compte pas.
                                 * */
                                return token::END;
                            }
                        
[1-9]+						{yylval->build<std::string>( yytext );return token::NB;}
[a-zA-Z1-9$_]+				{yylval->build<std::string>( yytext );return token::FIELD;}
"`"[\x01-\x7F]+"`"			{yylval->build<std::string>( yytext );return token::FIELD; /** pour les charset etendu **/}
"*"                         {yylval->build<std::string>( yytext );return token::WILD;}
"\'"[a-zA-Z1-9@]+"\'"		{yylval->build<std::string>( yytext );return token::CHAR;}
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
"''"	{return token::FORBIDDEN;}
[ ]						 {;}

.		{/* Used for all the other characters */
			std::cout << "Forbbiden char" << std::endl;
			return token::FORBIDDEN;
		}

%%

void comment(){
    std::cout << "Il y a un commentaire" << std::endl;
}


