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
#include <map>

/* include for all driver functions */
#include "calc_driver.h"

#undef yylex
#define yylex scanner.yylex

#ifndef SEC_TOOLS
#define SEC_TOOLS
/**
 * Fonction pour trouver les tautologies.
 * */
bool find_tautologies(std::vector<std::string> var);

/**
 * Fonction pour normaliser les field
 * */
std::string normalize_field(std::string field);

/**
 * Base de donnée de signatures pour les tautologies.
 * */
std::vector<std::vector<std::string>> DB = {
	{"1=1"},{"'l'='l'"},{"A=A"},{"B=B"},{"C=C"},{"D=D"},{"E=E"},{"F=F"},{"I=I"},{"J=J"},{"K=K"},{"L=L"}
};

/**
 * Dictionnaires des noms normaliés déjà utilisés.
 * */
std::map<std::string , std::string> dic_field_used;

/**
 * Premier nom normalisé a utiliser.
 * */
char abstraction = 'A';
/**
 * dictionnaire on l'on stocke le nombre de fois qu'un type de 
 * barème est déjà utilisé.
 * */
std::map<std::string, int> dic_recurrence_bareme = {
	{"commentaire",0},
	{"union",0},
	{"vide",0},
	{"sous",0}
	};
	
/**
 * Notre barème.
 * */
std::map<std::string,std::map<int, int>> dic_bareme={
	{"commentaire" , { 
		{1,100},
		{2,100},
		{3,100},
		{4,100},
	}},
	{"union" , { 
		{1,30},
		{2,50},
		{3,100},
		{4,100},
	}},
	{"vide" , { 
		{1,10},
		{2,20},
		{3,35},
		{4,50},
	}},
	{"sous" , { 
		{1,50},
		{2,80},
		{3,100},
		{4,100},
	}}
		
};

/**
 * Variablre stockant notre niveau d'alerte au fur et a mesure 
 * du parsing.
 * */
int level;

/**
 * Fonction utilisé pour incrémenter le niveau d'alerte. 
 * */
bool increase_level(std::string type);
#endif
}

%define api.value.type variant
%define parse.assert


%token <std::string> SELECT
%token <std::string> WILD
%token <std::string> NB
%token <std::string> FIELD
%token <std::string> CHAR
%token <std::string> FROM
%token <std::string> WHERE
%token <std::string> GROUP
%token <std::string> ORDER
%token <std::string> COMPARAISON
%token <std::string> LOGIQUE
%token <std::string> AS
%token <std::string> UNION
%token <std::string> TRI
%token <std::string> HAVING
%token <std::string> LIMIT
%token END
%token COMMENT
%token FORBIDDEN

%type <std::string> command
%type <std::string> selection
%type <std::string> ssrecherche
%type <std::string> provenance
%type <std::string> condition_close
%type <std::string> condition
%type <std::string> colonne
%type <std::string> colonne_ou_char
%type <std::string> colonne_ou_char_ou_NB_ou_command
%type <std::string> group_close
%type <std::string> colonne_tri 
%type <std::string> having_close
%type <std::string> order_close
%type <std::string> limit_close

%locations

%%
initialize:	{
				/**
				 * It is an Action in Mid-Rule. We need it to reset variables.  
				 * */
				level =0;
				dic_recurrence_bareme["commentaire"]=0;
				dic_recurrence_bareme["union"]=0;
				dic_recurrence_bareme["vide"]=0;
				dic_recurrence_bareme["sous"]=0;
			}
			commands
			;
			
commands:command END
        {
			std::cout << $1 << std::endl;
			YYACCEPT;
        }
        | command COMMENT
        {
			std::cout << "commentaire" << std::endl;
			if(!increase_level("commentaire")){
				YYABORT;
			}
			YYACCEPT;
		}
        ;

command: SELECT selection FROM provenance condition_close group_close order_close limit_close
		{
			$$ = $1 + $2 + $3 + $4 + $5;
		}
		| SELECT CHAR
		{
			if($2 == "" && !increase_level("vide")){
				YYABORT;
			}
			$$ = $1 + $2;
		}
		| SELECT NB
		{
			$$ = $1 + $2;
		}
		| command UNION command
		{
			if(!increase_level("union")){
				YYABORT;
			}
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

ssrecherche: '(' command ')' AS colonne_ou_char
		{
			if(!increase_level("sous")){
				YYABORT;
			}
			$$ = "(" + $2 + ")" + $4 + $5;
		}
        | '(' command ')'
        {
			if(!increase_level("sous")){
				YYABORT;
			}
			$$ = "(" + $2 + ")";
		}
        | colonne AS colonne_ou_char
        {
			$$ = $1 + $2 + $3;
		}
        | colonne
        {
			$$ = $1;
		}
        | WILD
        {
			$$ = $1;
		}
        ;

provenance:	'(' command ')' AS colonne
		{
			if(!increase_level("sous")){
				YYABORT;
			}
			$$ = "(" + $2 + ")" + $4 + $5;
		}
        | colonne AS colonne
        {
			$$ = $1 + $2 + $3;
		}
        | colonne
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

condition: colonne COMPARAISON colonne_ou_char_ou_NB_ou_command LOGIQUE condition
		{
			$$ = $1 + $2 + $3 + $4 + $5;
			if(!find_tautologies({$1,$2,$3,$4})){
				YYABORT;
			}
		}
        | colonne COMPARAISON colonne_ou_char_ou_NB_ou_command
        {
			$$ = $1 + $2 + $3;
			if(!find_tautologies({$1,$2,$3,""})){
				YYABORT;
			}
		}
        ;

colonne: FIELD
		{
			$$ = normalize_field($1);
		}

colonne_ou_char: colonne 
		{
			$$ = $1;
		}
        | CHAR 
        {
			if($1 == "" && !increase_level("vide")){
				YYABORT;
			}
			$$ = $1;
		}
        ;

colonne_ou_char_ou_NB_ou_command: colonne_ou_char
		{
			$$ = $1;
		}
		| NB
		{
			$$ = $1;
		}
        | '(' command ')'
        {
			if(!increase_level("sous")){
				YYABORT;
			}
			$$ = "(" + $2 + ")";
		}
        ;
        
group_close:
		{
			$$="";
		}
		| GROUP colonne_tri having_close
		{
			$$ = $1 + $2;
		}
		;
		
colonne_tri: colonne
		{
			$$ = $1;
		}
		| colonne TRI
		{
			$$ = $1 + $2;
		}
		
having_close:
		{
			$$ = "";
		}
		| HAVING condition
		{
			$$ = $1 + $2;
		}
	
order_close:
		{
			$$ = "";
		}
		| ORDER colonne_tri
		{
			$$ = $1 + $2;
		}
		
limit_close:
		{
			$$ = "";
		}
		| LIMIT NB
		{
			$$ = $1 + $2;
		}
%%


bool find_tautologies(std::vector<std::string> var){
	std::string buffer;
	std::vector<std::string> T;
	if(var.size()!=4){
		return false;
	}
	if(var[0] == var[2]){
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

std::string normalize_field(std::string field){
	if(dic_field_used.find(field) == dic_field_used.end()){
		/* Si mot pas déjà vu. */
		dic_field_used[field] = abstraction;
		abstraction++;
	}
	return dic_field_used[field];
}

bool increase_level(std::string type){
	std::cout << "coucou" << std::endl;
	if(dic_bareme.find(type) == dic_bareme.end()){
		return false; // Cas impossible.
	}
	
	if(dic_recurrence_bareme[type] < 4){
		dic_recurrence_bareme[type] += 1;
	}
	
	if(dic_recurrence_bareme.find(type) == dic_recurrence_bareme.end()){
		return false;
	}
	std::cout << "coucou" << std::endl;
	if(dic_bareme[type].find(dic_recurrence_bareme[type]) == dic_bareme[type].end()){
		return false;
	}
	std::cout << "!!!" << level << "!!!" << std::endl;
	level += dic_bareme[type][dic_recurrence_bareme[type]];
	std::cout << "!!!" << level << "!!!" << std::endl;
	return(level<100);
}

void
CALC::CALC_Parser::error( const location_type &l, const std::string &err_message )
{
    std::cerr << "Error: " << err_message << " at " << l << "\n";
}
