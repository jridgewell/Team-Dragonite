#include "../Customer.h"
#include <gtest/gtest.h>

TEST(Customer, Constructor) {
	const Customer c(1, "user", "pass", "My Name", "Street", "Cityname", "Statename", 11111, 1000000);
	EXPECT_EQ(c.getCustomerID(), 1);
	EXPECT_EQ(c.getUsername(), "user");
	EXPECT_EQ(c.getPassword(), "pass");
	EXPECT_EQ(c.getFullName(), "My Name");
	EXPECT_EQ(c.getAddress(), "Street");
	EXPECT_EQ(c.getCity(), "Cityname");
	EXPECT_EQ(c.getState(), "Statename");
	EXPECT_EQ(c.getZip(), 11111);
	EXPECT_EQ(c.getMoney(), 1000000);
}

TEST(Customer, DefaultConstructor) {
	const Customer c;
	EXPECT_EQ(c.getCustomerID(), 0);
	EXPECT_EQ(c.getUsername(), "username");
	EXPECT_EQ(c.getPassword(), "password");
	EXPECT_EQ(c.getFullName(), "First Last");
	EXPECT_EQ(c.getAddress(), "123 Street Dr.");
	EXPECT_EQ(c.getCity(), "City");
	EXPECT_EQ(c.getState(), "State");
	EXPECT_EQ(c.getZip(), 12345);
	EXPECT_EQ(c.getMoney(), 0);
}

TEST(Customer, CopyConstructor) {
	const Customer c;
	const Customer c2 = c;
	EXPECT_EQ(c.getCustomerID(), c2.getCustomerID());
	EXPECT_EQ(c.getUsername(), c2.getUsername());
	EXPECT_EQ(c.getPassword(), c2.getPassword());
	EXPECT_EQ(c.getFullName(), c2.getFullName());
	EXPECT_EQ(c.getAddress(), c2.getAddress());
	EXPECT_EQ(c.getCity(), c2.getCity());
	EXPECT_EQ(c.getState(), c2.getState());
	EXPECT_EQ(c.getZip(), c2.getZip());
	EXPECT_EQ(c.getMoney(), c2.getMoney());
}