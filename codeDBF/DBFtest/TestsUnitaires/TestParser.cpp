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

TEST( TestExceptionDVWA , PositiveExceptionDVWA1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("DROP DATABASE IF EXISTS dvwa"));

}

TEST( TestExceptionDVWA , PositiveExceptionDVWA2){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("CREATE DATABASE dvwa"));

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