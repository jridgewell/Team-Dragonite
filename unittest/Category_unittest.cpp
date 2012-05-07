/*
 * =====================================================================================
 *
 *       Filename:  Category_unittest.cpp
 *
 *    Description:  Header file for Category test class
 *
 *        Version:  1.0
 *        Created:  05/04/2012
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Scott Kieronski
 *   Organization:  Team Dragonite
 *
 * =====================================================================================
*/

#include "../Category.h"
#include <gtest/gtest.h>

/*
* Test the regular constructor for the merchant class
*/
TEST(Category, Constructor)
{
        const Category c(0, "Category Name");
        EXPECT_EQ(c.getCategoryID(), 0);
        EXPECT_EQ(c.getCategoryName(), "Category Name");
}

/*
* Test the default constructor
*/
TEST(Category, DefaultConstructor)
{
        const Category c;
        EXPECT_EQ(c.getCategoryID(), 0);
        EXPECT_EQ(c.getCategoryName(), "Category Name");
}

/*
* Test the copy constructor
*/
TEST(Category, CopyConstructor)
{
        const Category c;
        const Category c2 = c;
        EXPECT_EQ(c.getCategoryID(), c2.getCategoryID());
        EXPECT_EQ(c.getCategoryName(), c2.getCategoryName());
}
