//
// Created by menguy on 03/04/17.
//

#include "gtest/gtest.h"
#include "../../DBFsrc/Parser/calc_driver.h"
/*
################
# Doit marcher #
################
*/

TEST( TestParserSimpleSelect , simplePositiveSelect1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT 'coucou'"));
}


TEST( TestParserSimpleSelect , simplePositiveSelect2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select 'coucou'"));
}

TEST( TestParserSimpleSelectFrom , simplePositiveSelectFrom1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles"));
}

TEST( TestParserSimpleSelectFrom , simplePositiveSelectFrom2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT id FROM Articles"));
}

TEST( TestParserSimpleSelectFrom , simplePositiveSelectFrom3){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select db.id from Articles"));
}

TEST( TestParserSimpleSelectFrom , simplePositiveSelectFromWithExtendedCharset1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select `id+-*/()@` from Articles"));
}

TEST( TestParserSelectAsFrom , PositiveSelectAsFrom1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id as i from Articles"));
}

TEST( TestParserSelectAsFrom , PositiveSelectAsFrom2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id as 'i' from Articles"));
}

TEST( TestParserSelectAsFrom , PositiveSelectAsFrom3){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT id AS i FROM Articles"));
}

TEST( TestParserSelectAsFrom , PositiveSelectAsFrom4){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id as i,date from Articles"));
}

TEST( TestParserSelectFromAs , PositiveSelectFromAs1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles as a"));
}

TEST( TestParserSelectFromWhere , PositiveSelectFromWhere1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles where id=1"));
}

TEST( TestParserSelectFromWhere , PositiveSelectFromWhere2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles where id='1'"));
}


TEST( TestParserComplexRequest , PositiveComplexRequest1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select (select id from Articles where id=1) from Articles"));
}

TEST( TestParserComplexRequest , PositiveComplexRequest2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select (select id from Articles where id=1) as l from Articles"));
}

TEST( TestParserComplexRequest , PositiveComplexRequest3){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from (select * from Articles) as l"));
}

TEST( TestParserComplexRequest , PositiveComplexRequest4){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles where id=(select id from Articles where id=1)"));
}


TEST( TestParserUNION , PositiveUNION1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles UNION SELECT 'lala'"));
}
/*
 * Charactère vide.
 */
TEST( TestParserCharVide , PositiveCharVide1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles WHERE char=''"));
}

TEST( TestParserGroupBy , PositiveGroupBy1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles WHERE name='toto' GROUP BY age"));
}

TEST( TestParserGroupBy , PositiveGroupBy2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles WHERE name='toto' GROUP BY age ASC"));
}

TEST( TestParserGroupBy , PositiveGroupBy3){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles WHERE name='toto' GROUP BY age DESC"));
}

TEST( TestParserGroupByHaving , PositiveGroupByHaving1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles WHERE name='toto' GROUP BY age HAVING id = 50"));
}

TEST( TestParserGroupByHaving , PositiveGroupByHaving2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles WHERE name='toto' GROUP BY age HAVING id = (select a from Articles WHERE a=2)"));
}

TEST( TestParserOrderBy , PositiveOrderBy1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles WHERE id<10 ORDER BY name"));
}

TEST( TestParserOrderBy , PositiveOrderBy2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles WHERE id<10 ORDER BY name ASC"));
}

TEST( TestParserOrderBy , PositiveOrderBy3){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles WHERE id<10 ORDER BY name DESC"));
}

TEST( TestParserLimit , PositiveLimit1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles WHERE id<10 LIMIT 3"));
}

TEST( TestParserLimit , PositiveLimit2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles WHERE id<10 ORDER BY name LIMIT 9"));
}

TEST( TestParserOFFSET , PositiveOFFSET1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT host,user FROM user ORDER BY host LIMIT 1 OFFSET 1"));
}

TEST( TestParserFunction , PositiveFunction1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT MAX(id) FROM user"));
}

TEST( TestParserFunction , PositiveFunction2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT MIN(id) FROM user"));
}

TEST( TestParserFunction , PositiveFunction3){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT id FROM user WHERE ABS(nb)=1"));
}

TEST( TestParserFunction , PositiveFunction4){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT id FROM user WHERE id=ABS(nb)"));
}

TEST( TestParserFunction , PositiveFunction5){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT id FROM user WHERE id=ABS(5)"));
}

TEST( TestParserFunction , PositiveFunction6){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT id FROM user WHERE id=UPPER('lala')"));
}

TEST( TestParserFunction , PositiveFunction7){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT id FROM user WHERE id=POW(5,2)"));
}

TEST( TestParserSymfony , PositiveSymfony1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT a0_.id AS id_0, a0_.date AS date_1, a0_.title AS title_2, a0_.body AS body_3 FROM Articles a0_ ORDER BY a0_.id DESC LIMIT 1 OFFSET 0 "));
    
}

TEST( TestParserSymfony , PositiveSymfony2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT a0_.id AS id_0, a0_.date AS date_1, a0_.title AS title_2, a0_.body AS body_3 FROM Articles a0_ WHERE a0_.id LIKE '%1%' OR a0_.title LIKE '%1%' OR a0_.body LIKE '%1%' ORDER BY a0_.id DESC"));

}

TEST( TestExceptionDVWA , PositiveExceptionDVWA1){

    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("DROP DATABASE IF EXISTS dvwa"));

}

TEST( TestExceptionDVWA , PositiveExceptionDVWA2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("CREATE DATABASE dvwa"));

}

TEST( TestExceptionDVWA , PositiveExceptionDVWA3){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("USE dvwa"));

}

TEST( TestInsertion , PositiveInsertion1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("INSERT INTO lala (toto, titi) VALUES (1 , 'gtr')"));
}

TEST( TestInsertion , PositiveInsertion2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("INSERT INTO `lala` (toto, titi) VALUES (1 , 'gtr')"));
}

TEST( TestInsertion , PositiveInsertion3){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("INSERT INTO `lala` (lala.toto, lala.titi) VALUES (1 , 'gtr')"));
}

TEST( TestTrue , PositiveTrue1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select * from Articles where id <10 order by name DESC"));
}

TEST( TestTrue , PositiveTrue2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT user,password from users WHERE user='toto' and password='pass'"));
}

TEST( TestTrue , PositiveTrue3){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT fz.ta from fz where za<8 GROUP BY name HAVING zb>10 UNION SELECT toto from ri"));
}

TEST( TestTrue , PositiveTrue4){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT MIN(tr),MAX(te) from hgfd"));
}

TEST( TestTrue , PositiveTrue5){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT if(1=2,col1,col2) from trez"));
}

TEST( TestTrue , PositiveTrue6){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT COUNT(*) from trez"));
}

TEST( TestTrue , PositiveTrue7){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT aze, grez,hgf,hger from rterzb where fzeffzfz = 1"));
}

TEST( TestTrue , PositiveTrue8){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT (select id from gfd UNION select lala from toto) AS id from hgfd"));
}

TEST( TestTrue , PositiveTrue9){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT ABS(x) from u where x < 10"));
}

TEST( TestTrue , PositiveTrue10){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select user from users where user=UPPER('lala')"));
}

TEST( TestTrue , PositiveTrue11){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select user from users where user=LOWER('LaLa')"));
}

TEST( TestTrue , PositiveTrue12){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT gf, bfe from gre group by gf having toto<'gfd'"));
}

TEST( TestTrue , PositiveTrue13){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select user from users where user='lala'+'user'"));
}

TEST( TestTrue , PositiveTrue14){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select pow(fdds,gfd) from gfs"));
}

TEST( TestTrue , PositiveTrue15){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select users.data from users where user=UPPER('name')"));
}

TEST( TestTrue , PositiveTrue16){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select users.data from users where note < 10 and note > -10"));
}

TEST( TestTrue , PositiveTrue17){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select COUNT(DISTINCT user) from users"));
}

TEST( TestTrue , PositiveTrue18){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select ll, re,gfd from tre where hgf = fds"));
}

TEST( TestTrue , PositiveTrue19){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select users from lala where i = 1+2"));
}

TEST( TestTrue , PositiveTrue20){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from users where POW(id,2)<19"));
}

TEST( TestTrue , PositiveTrue21){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from users where id<POW(5,2)"));
}

TEST( TestTrue , PositiveTrue22){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT AVG(user_editcount) FROM wiki1_user;"));
}

TEST( TestTrue , PositiveTrue23){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT SUM(user_editcount) FROM wiki1_user;"));
}

TEST( TestTrue , PositiveTrue24){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT CAST(20130101 AS date);"));
}

TEST( TestTrue , PositiveTrue25){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT CONVERT (20130101, date)"));
}

TEST( TestTrue , PositiveTrue26){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT id from (select hgf from gfd ORDER BY gre) as gf"));
}

TEST( TestTrue , PositiveTrue27){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z from abcde"));
}

TEST( TestTrue , PositiveTrue28){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select * from (select lala from toto group by name having ABS(id)>15) as l"));
}

TEST( TestTrue , PositiveTrue29){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT 'user','lala'"));
}

TEST( TestTrue , PositiveTrue30){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT lala,'toto' from hgfd"));
}

TEST( TestTrue , PositiveTrue31){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("insert into users (username , password) VALUES ('lala' , 'pass1234')"));
}

TEST( TestTrue , PositiveTrue32){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("insert into users (id, username , password) VALUES (312 ,'lala' , 'pass1234')"));
}

TEST( TestTrue , PositiveTrue33){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("insert into `users` (username , password) VALUES ('lala' , 'pass1234')"));
}

TEST( TestTrue , PositiveTrue34){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("insert into users (`username` , password) VALUES ('lala' , 'pass1234')"));
}

TEST( TestTrue , PositiveTrue35){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("insert into `users` (`username` , `password`) VALUES ('lala' , 'pass1234')"));
}

TEST( TestTrue , PositiveTrue36){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("insert into users (username , password) VALUES ('lala' , 'pass1234')"));
}

TEST( TestTrue , PositiveTrue37){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("insert into users (username , password) VALUES (1 , 2)"));
}

TEST( TestTrue , PositiveTrue38){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("insert into users (a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z) VALUES (1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26)"));
}

TEST( TestTrue , PositiveTrue39){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("INSERT INTO lala (lalajhgf) VALUES ('lala')"));
}

TEST( TestTrue , PositiveTrue40){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("SELECT 1"));
}




/*
#######################
# Ne doit pas marcher #
#######################
*/


TEST( TestParserSimpleSelect , simpleNegativeSelect1){
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("SELECT *"));
}

TEST( TestParserSelectFromAs , NegativeSelectFromAs1){
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("select id from Articles as 'a'"));
}

TEST( TestParserComplexRequest , NegativeComplexRequest1){
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("select id from (select * from Articles)"));
}

TEST( TestParserComplexRequest , NegativeComplexRequest2){
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("select id from Articles where ((select id from Articles where id=1) as l)=1"));
}

TEST( TestParserComplexRequest , NegativeComplexRequest3){
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("select id from Articles where ((select id from Articles where id=1) as 'l')=1"));
}

TEST( TestParserComplexRequest , NegativeComplexRequest4){
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("select id from Articles where id=((select id from Articles where id=1) as l)"));
}

TEST( TestParserComplexRequest , NegativeComplexRequest5){
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("select id from Articles where id=((select id from Articles where id=1) as 'l')"));
}

TEST( TestParserComplexRequest , NegativeComplexRequest6){ //Car on a décidé qu'a gauche d'une comparaison il faut un FIELD
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("select id from Articles where (select id from Articles where id=1)=1"));
}

TEST( TestParserCommentary, NegativeCommentary1){
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("select -- id from Articles"));
}

TEST( TestParserCommentary , NegativeCommentary2){
    /*
     * Car notre barème interdit les commentaires.
     */
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("select id from Articles -- nimporte quoi apres"));
}

TEST( TestParserUNION , NegativeUNION1) {
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("select id ghfd UNION SELECT 'lala'"));
}

/* On n'autorise pas l'indexation des colonnes */
TEST( TestParserOrderBy , NegativeOrderBy1){
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("select id from Articles WHERE id<10 ORDER BY 1"));
}

TEST( TestParserLimit , NegativeLimit1){
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("select id from Articles WHERE id<10 LIMIT lala"));
}

TEST( TestParserFunction , NegativeFunction1) {
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("SELECT MIN(5) FROM user"));
}

TEST( TestParserFunction , NegativeFunction2) {
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("SELECT id FROM user where MIN(5)=5"));
}

TEST( TestParserFunction , NegativeFunction3) {
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("SELECT MIN(id,name) FROM user"));
}

TEST( TestWhiteList, NegativeWhiteList1){
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("DROP DATABASE IF EXISTS dvwa coucou"));
}