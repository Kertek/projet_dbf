////
//// Created by baptiste on 18/04/17.
////
//#include "gtest/gtest.h"
//#include "../../DBFsrc/Parser/calc_driver.h"
//
////Tautologie
//TEST( TestInjectionTautologies , falseTautologie1){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT toto FROM tata WHERE 1=1"));
//}
//
//TEST( TestInjectionTautologies , falseTautologie2){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where 'l'='l'"));
//}
//
//TEST( TestInjectionTautologies , falseTautologie3){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='toto' OR 1=1"));
//}
//
//TEST( TestInjectionTautologies , falseTautologie4){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' OR 'l'='l'"));
//}
//
//TEST( TestInjectionTautologies , falseTautologie5){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' AND id=1 OR 1=1"));
//}
//
//TEST( TestInjectionTautologies , falseTautologie6){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' OR 125>1"));
//}
//
//TEST( TestInjectionTautologies , falseTautologie7){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' OR 125>=1"));
//}
//
//TEST( TestInjectionTautologies , falseTautologie8){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' OR 1<25"));
//}
//
//TEST( TestInjectionTautologies , falseTautologie9){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' OR 1<=251"));
//}
//
//TEST( TestInjectionTautologies , falseTautologie10){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' OR 125!=1"));
//}
//
//TEST( TestInjectionTautologies , falseTautologie11){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name='a' OR 125<>1"));
//}
//
//TEST( TestInjectionTautologies , falseTautologie12){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name=name"));
//}
//
//TEST( TestInjectionVoidChar , falseVoidChar2){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select id from Articles where name=' '"));
//}
//
////Bases de données interdites
//TEST( TestInjectionBaseForbidden , falseBaseForbidden){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select * from information_schema.tables"));
//}
//
////Interdictions de fonctions
//TEST( TestInjectionFunction , falseRand){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select rand(0) from lala"));
//}
//
//TEST( TestInjectionFunction , falseSleep){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select sleep(1) from lala"));
//}
//
//TEST( TestInjectionFunction , falseLoadFile){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select LOAD_FILE('/home/chemin/') from lala"));
//}
//
//TEST( TestInjectionFunction , falseIntoDumpFile){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("select 'lala' INTO DUMPFILE '/home/chemin/lala.txt'"));
//}
//
//TEST( TestInjectionFunction , falseCreateFunction){
//    CALC::CALC_Driver driver;
//    EXPECT_FALSE(driver.parse("SELECT lala FROM toto WHERE id=5 UNION CREATE FUNCTION tests RETURNS STRING SONAME libtest.so"));
//}
//
