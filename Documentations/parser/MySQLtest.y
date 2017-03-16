%{
#include <stdio.h>
#include <string.h>

// yacc -d MySQLtest.y
%}

%token SELECT FIELD CHAR FROM WHERE COMPARAISON AS END

%%
commands:  | commands command END 
		{
			printf("commande valide\n");
			YYACCEPT;
		}
		;

command: SELECT selection FROM provenance condition
		;

selection: ssrecherche ',' selection | ssrecherche
		;
		
ssrecherche: '(' command ')' | FIELD AS FIELD | FIELD
		;
		
provenance:	'(' command ')' AS FIELD | FIELD
		;

condition: | WHERE FIELD COMPARAISON FIELD
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


main()
{
		yyparse();
} 
