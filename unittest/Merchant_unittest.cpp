#include "../Merchant.h"
#include <gtest/gtest.h>

TEST(Merchant, Constructor)
{
        const Merchant m("merchant", "pass");
        EXPECT_EQ(m.getUsername(), "merchant");
        EXPECT_EQ(m.getPassword(), "pass");
}

TEST(Merchant, DefaultConstructor)
{
        const Merchant m;
        EXPECT_EQ(m.getUsername(), "username");
        EXPECT_EQ(m.getPassword(), "password");
}

TEST(Merchant, CopyConstructor)
{
        const Merchant m;
        const Merchant m2 = m;
        EXPECT_EQ(c.getUsername(), c2.getUsername());
        EXPECT_EQ(c.getPassword(), c2.getPassword());
}
