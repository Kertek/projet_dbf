%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

void comment();

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
"--"						{/* Commentaire */
								comment();
								/*
								 * On retourne NEWLINE pour dire 
								 * que la suite ne compte pas.
								 * */
								return NEWLINE; 
							}

"=" 	|
"<=" 	|
">="	| 
"<" 	|
">"							{return COMPARAISON;}
[\n]						{
								/*
								 * NEWLINE signifie la fin de la requete.
								 * */
								return NEWLINE;
							}

%%


void comment(){
	printf("Il y a un commentaire\n");
}
