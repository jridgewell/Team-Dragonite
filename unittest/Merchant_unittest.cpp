/*
 * =====================================================================================
 *
 *       Filename:  Merchant_unittest.cpp
 *
 *    Description:  Header file for Merchant test class
 *
 *        Version:  1.0
 *        Created:  05/02/2012
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Scott Kieronski
 *   Organization:  Team Dragonite
 *
 * =====================================================================================
*/

#include "../Merchant.h"
#include <gtest/gtest.h>

/*
* Test the regular constructor for the merchant class
*/
TEST(Merchant, Constructor)
{
        const Merchant m("merchant", "pass");
        EXPECT_EQ(m.getUsername(), "merchant");
        EXPECT_EQ(m.getPassword(), "pass");
}

/*
* Test the default constructor 
*/
TEST(Merchant, DefaultConstructor)
{
        const Merchant m;
        EXPECT_EQ(m.getUsername(), "username");
        EXPECT_EQ(m.getPassword(), "password");
}

/*
* Test the copy constructor
*/
TEST(Merchant, CopyConstructor)
{
        const Merchant m;
        const Merchant m2 = m;
        EXPECT_EQ(c.getUsername(), c2.getUsername());
        EXPECT_EQ(c.getPassword(), c2.getPassword());
}
