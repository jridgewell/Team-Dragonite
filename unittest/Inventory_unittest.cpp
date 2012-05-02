/*
 * =====================================================================================
 *
 *       Filename:  Inventory_unittest.cpp
 *
 *    Description:  Header file for Inventory test class
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

#include "../Inventory.h"
#include <gtest/gtest.h>

/*
* Test the regular constructor for the merchant class
*/
TEST(Inventory, Constructor)
{
        const Inventory i("merchant", "pass");
        EXPECT_EQ(i.getUsername(), "merchant");
        EXPECT_EQ(i.getPassword(), "pass");
}

/*
* Test the default constructor 
*/
TEST(Inventory, DefaultConstructor)
{
        const Inventory i;
        EXPECT_EQ(i.getUsername(), "username");
        EXPECT_EQ(i.getPassword(), "password");
}

/*
* Test the copy constructor
*/
TEST(Inventory, CopyConstructor)
{
        const Inventory i;
        const Inventory i2 = i;
        EXPECT_EQ(m.getUsername(), m2.getUsername());
        EXPECT_EQ(m.getPassword(), m2.getPassword());
}
