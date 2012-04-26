#include "../Order.h"
#include "../Date.h"
#include <gtest/gtest.h>

TEST(Order, Construotor) {
	const Order o(1, 1, 1, 1, 1, Date());
	EXPECT_EQ(o.getOrderID(), 1);
	EXPECT_EQ(o.getCustomerID(), 1);
	EXPECT_EQ(o.getSKU(), 1);
	EXPECT_EQ(o.getQuantity(), 1);
	EXPECT_EQ(o.getPrice(), 1);
	// EXPECT_EQ(o.getDate().serializeDate(), Date().serializeDate());
}

TEST(Order, DefaultConstruotor) {
	const Order o;
	EXPECT_EQ(o.getOrderID(), 0);
	EXPECT_EQ(o.getCustomerID(), 0);
	EXPECT_EQ(o.getSKU(), 0);
	EXPECT_EQ(o.getQuantity(), 0);
	EXPECT_EQ(o.getPrice(), 0);
	// EXPECT_EQ(o.getDate().serializeDate(), Date().serializeDate());
}

TEST(Order, CopyConstruotor) {
	const Order o;
	const Order o2 = o;
	EXPECT_EQ(o.getOrderID(), o2.getOrderID());
	EXPECT_EQ(o.getCustomerID(), o2.getCustomerID());
	EXPECT_EQ(o.getSKU(), o2.getSKU());
	EXPECT_EQ(o.getQuantity(), o2.getQuantity());
	EXPECT_EQ(o.getPrice(), o2.getPrice());
	// EXPECT_EQ(o.getDate().serializeDate(), o2.getDate().serializeDate());
}