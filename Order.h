#ifndef Order_H
#define Order_H
/*
 * =====================================================================================
 *
 *       Filename:  Order.h
 *
 *    Description:  Header file for Order class
 *
 *        Version:  1.0
 *        Created:  04/25/2012 19:40:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Justin Ridgewell
 *   Organization:  Team Dragonite
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>
#include "Date.h"

//TODO: javadocs

class Order {
	private:
		int myOrderID;
		int myCustomerID;
		int mySKU;
		int myQuantity;
		int myPrice;
		Date myDate;
	public:
		Order();
		Order(int orderID, int customerID, int SKU, int quantity, int price, const Date& date);
		Order(const Order& Order);
		Order(const YAML::Node& node);
		virtual ~Order() {}
		int getOrderID() const;
		int getCustomerID() const;
		int getSKU() const;
		int getQuantity() const;
		int getPrice() const;
		const Date& getDate() const;
		void parseYaml(const YAML::Node& node);
		void setOrderID(int orderID);
		void setCustomerID(int customerID);
		void setSKU(int SKU);
		void setQuantity(int quantity);
		void setPrice(int price);
		void setDate(const Date& date);
};
#endif