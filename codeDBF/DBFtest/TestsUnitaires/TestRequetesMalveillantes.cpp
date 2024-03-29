////
//// Created by baptiste on 30/05/17.
////
//
//#include "gtest/gtest.h"
//#include "../../DBFsrc/Parser/calc_driver.h"
//
////Tautologie
//TEST(TestInjectionTautologies, falseTautologie1) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT toto FROM tata WHERE 1=1"));
//}
//
//TEST(TestInjectionTautologies, falseTautologie2) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where 'l'='l'"));
//}
//
//TEST(TestInjectionTautologies, falseTautologie3) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='toto' OR 1=1"));
//}
//
//TEST(TestInjectionTautologies, falseTautologie4) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' OR 'l'='l'"));
//}
//
//TEST(TestInjectionTautologies, falseTautologie5) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' AND id=1 OR 1=1"));
//}
//
//TEST(TestInjectionTautologies, falseTautologie6) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' OR 125>1"));
//}
//
//TEST(TestInjectionTautologies, falseTautologie7) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' OR 125>=1"));
//}
//
//TEST(TestInjectionTautologies, falseTautologie8) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' OR 1<25"));
//}
//
//TEST(TestInjectionTautologies, falseTautologie9) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' OR 1<=251"));
//}
//
//TEST(TestInjectionTautologies, falseTautologie10) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' OR 125!=1"));
//}
//
//TEST(TestInjectionTautologies, falseTautologie11) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' OR 125<>1"));
//}
//
//TEST(TestInjectionTautologies, falseTautologie12) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name=name"));
//}
//
//TEST(TestInjectionVoidChar, falseVoidChar2) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name=' '"));
//}
//
////Bases de données interdites
//TEST(TestInjectionBaseForbidden, falseBaseForbidden) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select * from information_schema.tables"));
//}
//
////Interdictions de fonctions
//TEST(TestInjectionFunction, falseRand) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select rand(0) from lala"));
//}
//
//TEST(TestInjectionFunction, falseSleep) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select sleep(1) from lala"));
//}
//
//TEST(TestInjectionFunction, falseLoadFile) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select LOAD_FILE('/home/chemin/') from lala"));
//}
//
//TEST(TestInjectionFunction, falseIntoDumpFile) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select 'lala' INTO DUMPFILE '/home/chemin/lala.txt'"));
//}
//
//TEST(TestInjectionFunction, falseCreateFunction) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse(
//            "SELECT lala FROM toto WHERE id=5 UNION CREATE FUNCTION tests RETURNS STRING SONAME libtest.so"));
//}
//
//TEST(TestParserSimpleSelect, simpleNegativeSelect1) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT *"));
//}
//
//TEST(TestParserSelectFromAs, NegativeSelectFromAs1) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles as 'a'"));
//}
//
//TEST(TestParserComplexRequest, NegativeComplexRequest1) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from (select * from Articles)"));
//}
//
//TEST(TestParserComplexRequest, NegativeComplexRequest2) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where ((select id from Articles where id=1) as l)=1"));
//}
//
//TEST(TestParserComplexRequest, NegativeComplexRequest3) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where ((select id from Articles where id=1) as 'l')=1"));
//}
//
//TEST(TestParserComplexRequest, NegativeComplexRequest4) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where id=((select id from Articles where id=1) as l)"));
//}
//
//TEST(TestParserComplexRequest, NegativeComplexRequest5) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where id=((select id from Articles where id=1) as 'l')"));
//}
//
//TEST(TestParserComplexRequest,
//     NegativeComplexRequest6) { //Car on a décidé qu'a gauche d'une comparaison il faut un FIELD
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where (select id from Articles where id=1)=1"));
//}
//
//TEST(TestParserCommentary, NegativeCommentary1) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select -- id from Articles"));
//}
//
//TEST(TestParserCommentary, NegativeCommentary2) {
////     * Car notre barème interdit les commentaires.
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles -- nimporte quoi apres"));
//}
//
//TEST(TestParserUNION, NegativeUNION1) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id ghfd UNION SELECT 'lala'"));
//}
//
//// On n'autorise pas l'indexation des colonnes
//
//TEST(TestParserOrderBy, NegativeOrderBy1) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles WHERE id<10 ORDER BY 1"));
//}
//
//TEST(TestParserLimit, NegativeLimit1) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles WHERE id<10 LIMIT lala"));
//}
//
//TEST(TestParserFunction, NegativeFunction1) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT MIN(5) FROM user"));
//}
//
//TEST(TestParserFunction, NegativeFunction2) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT id FROM user where MIN(5)=5"));
//}
//
//TEST(TestParserFunction, NegativeFunction3) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT MIN(id,name) FROM user"));
//}
//
//TEST(TestWhiteList, NegativeWhiteList1) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("DROP DATABASE IF EXISTS dvwa coucou"));
//}
//
//TEST(TestPerformance, test1) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT @@version"));
//}
//
//TEST(TestPerformance, test2) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT user()"));
//}
//
//TEST(TestPerformance, test3) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT system_user()"));
//}
//
//TEST(TestPerformance, test4) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT user FROM mysql.user"));
//}
//
//TEST(TestPerformance, test5) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT host, user, password FROM mysql.user"));
//}
//
//TEST(TestPerformance, test6) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT grantee, privilege_type, is_grantable FROM information_schema.user_privileges"));
//}
//
//TEST(TestPerformance, test7) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse(
//            "SELECT host, user, Select_priv, Insert_priv, Update_priv, Delete_priv, Create_priv, Drop_priv, Reload_priv, Shutdown_priv, Process_priv, File_priv, Grant_priv, References_priv, Index_priv, Alter_priv, Show_db_priv, Super_priv, Create_tmp_table_priv, Lock_tables_priv, Execute_priv, Repl_slave_priv, Repl_client_priv FROM mysql.user"));
//}
//
//TEST(TestPerformance, test8) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(
//            driver.parse("SELECT grantee, table_schema, privilege_type FROM information_schema.schema_privileges"));
//}
//
//TEST(TestPerformance, test9) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse(
//            "SELECT table_schema, table_name, column_name, privilege_type FROM information_schema.column_privileges"));
//}
//
//TEST(TestPerformance, test10) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse(
//            "SELECT grantee, privilege_type, is_grantable FROM information_schema.user_privileges WHERE privilege_type = ‘SUPER’"));
//}
//
//TEST(TestPerformance, test11) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT host, user FROM mysql.user WHERE Super_priv = ‘Y’"));
//}
//
//TEST(TestPerformance, test12) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT database()"));
//}
//
//TEST(TestPerformance, test13) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT schema_name FROM information_schema.schemata"));
//}
//
//TEST(TestPerformance, test14) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT distinct(db) FROM mysql.db"));
//}
//
//TEST(TestPerformance, test15) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse(
//            "SELECT table_schema, table_name, column_name FROM information_schema.columns WHERE table_schema != ‘mysql’ AND table_schema != ‘information_schema’"));
//}
//
//TEST(TestPerformance, test16) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse(
//            "SELECT table_schema,table_name FROM information_schema.tables WHERE table_schema != ‘mysql’ AND table_schema != ‘information_schema’"));
//}
//
//TEST(TestPerformance, test17) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse(
//            "SELECT table_schema, table_name FROM information_schema.columns WHERE column_name = ‘username’"));
//}
//
//TEST(TestPerformance, test18) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT host,user FROM user ORDER BY host LIMIT 1 OFFSET 0"));
//}
//
//TEST(TestPerformance, test19) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT host,user FROM user ORDER BY host LIMIT 1 OFFSET 1"));
//}
//
//TEST(TestPerformance, test20) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT substr(‘abcd’, 3, 1)"));
//}
//
//TEST(TestPerformance, test21) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT 6 & 2"));
//}
//
//TEST(TestPerformance, test22) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT 6 & 1"));
//}
//
//TEST(TestPerformance, test23) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT char(65)"));
//}
//
//TEST(TestPerformance, test24) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT ascii(‘A’)"));
//}
//
//TEST(TestPerformance, test25) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT cast(’1′ AS unsigned integer)"));
//}
//
//TEST(TestPerformance, test26) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT cast(’123′ AS char)"));
//}
//
//TEST(TestPerformance, test27) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT CONCAT(‘A’,'B’)"));
//}
//
//TEST(TestPerformance, test28) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT CONCAT(‘A’,'B’,'C’)"));
//}
//
//TEST(TestPerformance, test29) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT if(1=1,’foo’,'bar’)"));
//}
//
//TEST(TestPerformance, test30) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT CASE WHEN (1=1) THEN ‘A’ ELSE ‘B’ END"));
//}
//
//TEST(TestPerformance, test31) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT 0×414243"));
//}
//
//TEST(TestPerformance, test32) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT BENCHMARK(1000000,MD5(‘A’))"));
//}
//
//TEST(TestPerformance, test33) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT SLEEP(5)"));
//}
//
//TEST(TestPerformance, test34) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT name WHERE id=1 UNION ALL SELECT LOAD_FILE(‘/etc/passwd’)"));
//}
//
//TEST(TestPerformance, test35) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT * FROM mytable INTO dumpfile ‘/tmp/somefile’"));
//}
//
//TEST(TestPerformance, test36) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT @@hostname"));
//}
//
//TEST(TestPerformance, test37) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("CREATE USER test1 IDENTIFIED BY ‘pass1′"));
//}
//
//TEST(TestPerformance, test38) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("DROP USER test1"));
//}
//
//TEST(TestPerformance, test39) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("GRANT ALL PRIVILEGES ON *.* TO test1@’%'"));
//}
//
//TEST(TestPerformance, test40) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT @@datadir"));
//}
//
//TEST(TestPerformance, test41) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SET DATEFORMAT YMD"));
//}
//
//TEST(TestPerformance, test42) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse(
//            "SELECT * FROM magasin1_client UNION SELECT * FROM magasin2_client UNION SELECT * FROM magasin3_client UNION SELECT * FROM magasin4_client"));
//}
//
//TEST(TestPerformance, test43) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles # nimporte quoi apres"));
//}
//
//TEST(TestPerformance, test44) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles; select rand(0) from lala "));
//}
//
//TEST(TestPerformance, test45) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select (select (select id from lala) from lala) from Articles"));
//}
//
//TEST(TestPerformance, test46) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select version()"));
//}
//
//TEST(TestPerformance, test47) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select system_user()"));
//}
//
//TEST(TestPerformance, test48) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select user_id from  fsb_users where login_id = '';exec master..xp_cmdshell 'ping -n 8 127.0.0.1';--'"));
//}
//
//TEST(TestPerformance, test49) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT user_login FROM user WHERE user_login='inject'='inject' LIMIT 0,1 - fin !'  AND user_password='n'importe quel mot de passe ira très bien de toute façon cette partie de la requête est en commentaire!'"));
//}
//
//TEST(TestPerformance, test50) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT id, email, password FROM users WHERE username = 'rakoto@sample.com' OR 1='1' AND password = 'qsdqdfqdfqsdf'"));
//}
//
//TEST(TestPerformance, test51) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT id, email, password FROM users WHERE username = 'rakoto@sample.com' OR '=' AND password = 'qsdqdfqdfqsdf'"));
//}
//
//TEST(TestPerformance, test52) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT login, password FROM admin WHERE login='' UNION SELECT login, password from admin # ' and password='$password'"));
//}
//
//TEST(TestPerformance, test53) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT login, password FROM admin WHERE login='' OR 'X'='X' INTO OUTFILE '../../www/file.txt' #' AND password='$password';"));
//}
//
//TEST(TestPerformance, test54) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT host, user, password, database() FROM mysql.user"));
//}
//
//TEST(TestPerformance, test55) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT id, username FROM users WHERE id = -1 UNION SELECT 1,2 FROM users WHERE 1=1"));
//}
//
//TEST(TestPerformance, test56) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT articles.id, articles.title, DATE_FORMAT(date, '%d/%m/%Y') AS date, content, categories.title AS title_category FROM articles INNER JOIN categories ON articles.category_id = categories.id WHERE articles.id = -1 UNION SELECT null,'<?php if(!empty($_GET[\"cmd\"])){ echo \"<pre>\".shell_exec($_GET[\"cmd\"]).\"</pre>\"; } ?>',null,null,null INTO OUTFILE '/var/www/html/zds/injections_sql/backdoor.php'"));
//}
//
//TEST(TestPerformance, test57) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("INSERT INTO users (username, password, rank) VALUES ('john', 'doe', 1)#', 'test', 2)"));
//}
//
//TEST(TestPerformance, test58) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("UPDATE usagers SET password=MD5('monmotdepasse')"));
//}
//
//TEST(TestPerformance, test59) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select load_file('/etc/passwd')"));
//}
//
//TEST(TestPerformance, test60) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT * from table where id=1%20OR%20user_id%20%3E0"));
//}
//
//TEST(TestPerformance, test61) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("insert into pg_shadow(usename,usesysid,usesuper,usecatupd,passwd) select 'crack', usesysid, 't','t','crack' from pg_shadow where usename='postgres';"));
//}
//
//TEST(TestPerformance, test62) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT SLEEP()"));
//}
//
//TEST(TestPerformance, test63) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT id, titre, texte FROM articles WHERE id = 1 AND 1=2"));
//}
//
//TEST(TestPerformance, test64) {
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT id,nom,vie,attaque,description FROM monstre WHERE id=1 UNION SELECT 0,login,0,0,password FROM admin"));
//}
