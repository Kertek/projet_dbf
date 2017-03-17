%{
#include <stdio.h>
#include <string.h>

/* yacc -d MySQLtest.y
 * Ce fichier a pour but de préciser la grammaire MySQL.
 * On définit un requête comme étant correcte si elle est composé 
 * d'une suite de commandes finissant par un ';' toutes correcte. 
 * Une requête se termine par un retour à la ligne. 
 * */
%}

%token SELECT FIELD CHAR FROM WHERE COMPARAISON AS END COMMENT NEWLINE

%%
commands:  | command END commands NEWLINE
		{
			printf("commande valide\n");
			YYACCEPT;
		}
		;

command: SELECT selection FROM provenance condition | SELECT CHAR
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
		
condition: 
		| WHERE field_ou_char_ou_command COMPARAISON field_ou_char_ou_command
		;

field_ou_char: FIELD 
		| CHAR
		;

field_ou_char_ou_command: field_ou_char
		| '(' command ')'
		;
%%

yyerror(s)
char *s;
{
    fprintf(stderr,"error: %s\n",s);
}
 
yywrap()
{
        return 1;
} 

extern char yyin;
main()
{
	yyparse();
} 
