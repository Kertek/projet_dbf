//
// Created by menguy on 03/04/17.
//

#include "gtest/gtest.h"
#include "../../DBFsrc/Message.h"
#include "../../DBFsrc/Parser/calc_driver.h"

TEST( test1 , testFonction ){
    Message * m = new Message();
    ASSERT_STREQ(m->getContent()->data(), nullptr);
}

TEST(test2,testParse){
    CALC::CALC_Driver driver;
    driver.parse("SELECT");
    EXPECT_EQ(0,0);
}