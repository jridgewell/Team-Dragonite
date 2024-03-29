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
* Test the regular constructor for the Inventory class
*/
TEST(Inventory, Constructor)
{
        const Inventory i(0, "Item Description", 0, 0, 0.0, 0);
        EXPECT_EQ(i.getSKU(), 0);
        EXPECT_EQ(i.getItemDesc(), "Item Description");
        EXPECT_EQ(i.getCategoryID(), 0);
        EXPECT_EQ(i.getMerchantID(), 0);
        EXPECT_EQ(i.getPrice(), 0.0);
        EXPECT_EQ(i.getQuantity(), 0);

}

/*
* Test the default constructor
*/
TEST(Inventory, DefaultConstructor)
{
        const Inventory i;
        EXPECT_EQ(i.getSKU(), 0);
        EXPECT_EQ(i.getItemDesc(), "Item Description");
        EXPECT_EQ(i.getCategoryID(), 0);
        EXPECT_EQ(i.getMerchantID(), 0);
        EXPECT_EQ(i.getPrice(), 0.0);
        EXPECT_EQ(i.getQuantity(), 0);
}

/*
* Test the copy constructor
*/
TEST(Inventory, CopyConstructor)
{
        const Inventory i;
        const Inventory i2 = i;
        EXPECT_EQ(i.getSKU(), i2.getSKU());
        EXPECT_EQ(i.getItemDesc(), i2.getItemDesc());
        EXPECT_EQ(i.getCategoryID(), i2.getCategoryID());
        EXPECT_EQ(i.getMerchantID(), i2.getMerchantID());
        EXPECT_EQ(i.getPrice(), i2.getPrice());
        EXPECT_EQ(i.getQuantity(), i2.getQuantity());
}
