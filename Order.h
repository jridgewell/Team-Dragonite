#ifndef ORDER_H
#define ORDER_H
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

/*
* Outlines the Order class and the features contained therein
* Orders consist of an order ID number, a customer ID number, a SKU, the quantity of an item sold, the price of the item, and the date the item is ordered
* Creates orders through one of the following:
* 1) A default constructor
* 2) A constructor with passed in values
* 3) An existing order object, copying its values
* 4) Object data retrieved from a node on the YAML
* In addition, the class is able to set/get the order's values
*/

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
		YAML::Emitter& emitYaml(YAML::Emitter& out) const;
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
