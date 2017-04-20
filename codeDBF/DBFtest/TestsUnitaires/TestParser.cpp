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
    EXPECT_TRUE(driver.parse("select id from Articles where (select id from Articles where id=1)=1"));
}

TEST( TestParserComplexRequest , PositiveComplexRequest5){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles where id=(select id from Articles where id=1)"));
}

TEST( TestParserCommentary , PositiveCommentary1){
    CALC::CALC_Driver driver;
    EXPECT_TRUE(driver.parse("select id from Articles -- nimporte quoi apres"));
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

TEST( TestParserCommentary, NegativeCommentary1){
    CALC::CALC_Driver driver;
    EXPECT_FALSE(driver.parse("select -- id from Articles"));
}