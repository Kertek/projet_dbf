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
%{
    /**Exception Tests DVWA **/
%}
"DROP DATABASE IF EXISTS dvwa" |
"CREATE DATABASE dvwa"			|
"USE dvwa"					|
"CREATE TABLE users (user_id int(6),first_name varchar(15),last_name varchar(15), user varchar(15), password varchar(32),avatar varchar(70), last_login TIMESTAMP, failed_login INT(3), PRIMARY KEY (user_id))" |
"INSERT INTO users VALUES" |
"CREATE TABLE guestbook (comment_id SMALLINT UNSIGNED NOT NULL AUTO_INCREMENT, comment varchar(300), name varchar(100), PRIMARY KEY (comment_id))" |
"INSERT INTO guestbook VALUES ('1','This is a test comment.','test')" |
"SELECT table_schema, table_name, create_time" {return token::EXCEPTION;}
%{
    /**Exception Tests Performance **/
%}
"DROP SCHEMA IF EXISTS `mysqlslap`" |
"CREATE SCHEMA `mysqlslap`" |
"CREATE TABLE `t1` (intcol1 INT(32) ,charcol1 VARCHAR(128))" |
"INSERT INTO t1 VALUES " |
"SELECT intcol1,charcol1 FROM t1" |
"SELECT table_schema, table_name, create_time" {return token::EXCEPTION;}


"INSERT INTO" |
"insert into" 				{yylval->build<std::string>( "INSERT INTO" ); return token::INSERT;}
"VALUES"	  |
"values"					{yylval->build<std::string>( yytext ); return token::VALUES;}
"delete from"	|
"DELETE FROM"				{yylval->build<std::string>( "DELETE FROM" ); return token::DELETE;}
"delete"	|
"DELETE"					{yylval->build<std::string>( "DELETE" ); return token::DELETE;}
"SELECT" |
"select"					{yylval->build<std::string>( "SELECT" ); return token::SELECT;}
"select distinct" |
"SELECT DISTINCT"			{yylval->build<std::string>( "SELECT DISTINCT" ); return token::SELECT;}
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
"join"	|
"JOIN"	|
"inner join" |
"INNER JOIN" |
"left join" |
"LEFT JOIN" |
"right join" |
"RIGHT JOIN" |
"full join" |
"FULL JOIN" 				{yylval->build<std::string>( yytext );return token::JOIN;}
"on"    |
"ON"						{yylval->build<std::string>( "ON" );return token::ON;}
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
"lower" |
"LOWER"						{yylval->build<std::string>( "LOWER" );return token::FUNC;}
"pow"	|
"POW"						{yylval->build<std::string>( "POW" );return token::FUNC;}
"count" |
"COUNT"						{yylval->build<std::string>( "COUNT" );return token::FUNC;}
"avg"	|
"AVG"						{yylval->build<std::string>( "AVG" );return token::FUNC;}
"sum"	|
"SUM"						{yylval->build<std::string>( "SUM" );return token::FUNC;}
"information_schema".*		|
"user()"					|
"version()"					|
"drop"						|
"DROP"						|
"sleep()"					|
"SLEEP()"					|
"sleep("[0-9]+")"			|
"SLEEP("[0-9]+")"			|
"create function"			|
"CREATE FUNCTION"			|
"into dumpfile"				|
"INTO DUMPFILE"				{return token::FORBIDDEN;}
"--"						|
"#"                         {	/* Commentaire:
                                 * On retourne END pour dire
                                 * que la suite ne compte pas.
                                 * */
                                return token::COMMENT;
                            }

"=" 	|
"<=" 	|
">="	|
"<" 	|
">"		|
"!="    |
"<>"    |                     
"LIKE"	|
"like"	|
'in'	|
"IN"	|
"not in" |
"NOT IN" 					{yylval->build<std::string>( yytext );return token::COMPARAISON;}
                        
[0-9]+ | 
"-"[0-9]+			{yylval->build<std::string>( yytext );return token::NB;}
[a-zA-Z0-9$_]+				|
[a-zA-Z0-9$_]+"."[a-zA-Z0-9$_]+		{yylval->build<std::string>( yytext );return token::FIELD;}
`[\x01-\x7F]+`				{yylval->build<std::string>( yytext );return token::FIELD; /** pour les charset etendu **/}
"*"                         {yylval->build<std::string>( yytext );return token::WILD;}
'[a-zA-Z0-9@%]*'			{yylval->build<std::string>( yytext );return token::CHAR;}

";"							{;}
<<EOF>> 					{
                                /*Il faudra verifier que cela 
                                 * n'introduit pas une faille injection 
                                 * Null byte*/
                                return token::END;
                            }
","							{return *yytext;}
"("							{return *yytext;}
")"							{return *yytext;}
"+" |
"-" |
"*" |
"/" |
"%" 						{yylval->build<std::string>( yytext );return token::OPERATION;}

[ ]						 	{;}

.		{/* Used for all the other characters */
			//std::cout << "Forbbiden char" << std::endl;
			return token::FORBIDDEN;
		}

%%



