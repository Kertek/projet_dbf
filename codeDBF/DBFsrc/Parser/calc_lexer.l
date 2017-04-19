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
"select"					{return token::SELECT;}
"FROM" 	 |
"from" 						{return token::FROM;}
"WHERE"  |
"where"						{return token::WHERE;}
"AS"     |
"as"						{return token::AS;}
"and"	 |
"AND"	 |
"or"	 |
"OR"	 					{return token::LOGIQUE;}
"information_schema.tables"	|
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
[a-zA-Z1-9$_]+				{return token::FIELD;}
"`"[a-zA-Z1-9]+"`"			{; /** pour les charset etendu **/}
"*"                         {return token::WILD;}
"\'"[a-zA-Z1-9]+"\'"		{return token::CHAR;}
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
"<>"    {return token::COMPARAISON;}
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


