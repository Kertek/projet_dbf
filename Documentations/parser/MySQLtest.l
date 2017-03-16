%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

%}

%%
"SELECT" | 
"select"					{return SELECT;}
"FROM" 	 | 
"from" 						{return FROM;}
"WHERE"  | 
"where"						{return WHERE;}
"AS"     |
"as"						{return AS;}
[a-zA-Z1-9]+				{return FIELD;}
"\'"[a-zA-Z1-9]+"\'"		{return CHAR;}
";"							{return END;} 
","							{return *yytext;}
"("							{return *yytext;}
")"							{return *yytext;}

"==" 	|
"<=" 	|
">="	| 
"<" 	|
">"							{return COMPARAISON;}

%%
