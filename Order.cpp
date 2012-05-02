/*
 * =====================================================================================
 *
 *       Filename:  Order.cpp
 *
 *    Description:  Class implementation for Order
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
#include "Order.h"

//TODO: javadocs

/*
/Default constructor, creates a new order with the default values
/Pre: None
/Post: Order is created with default value
*/
Order::Order() {
	this->setOrderID(0);
	this->setCustomerID(0);
	this->setSKU(0);
	this->setQuantity(0);
	this->setPrice(0);
	this->setDate(Date());
}

/*
/Creates a new order with the input values
/Pre: Values for the order id, customer id, SKY, quantity, price and date are input
/Post: A new order is created with the passed in values
*/
Order::Order(int orderID, int customerID, int SKU, int quantity, int price, const Date& date) {
	this->setOrderID(orderID);
	this->setCustomerID(customerID);
	this->setSKU(SKU);
	this->setQuantity(quantity);
	this->setPrice(price);
	this->setDate(date);
}

/*
/Clones an order object
/Pre: An order is passed in
/Post: A new order is created with the same values as the passed in one
*/
Order::Order(const Order& order) {
	this->setOrderID(order.myOrderID);
	this->setCustomerID(order.myCustomerID);
	this->setSKU(order.mySKU);
	this->setQuantity(order.myQuantity);
	this->setPrice(order.myPrice);
	this->setDate(order.myDate);
}

/*
/Pushes an order's data on the YAML 
/Pre: The node where the data will be stored is passed in
/Post: The order's information is stored on the node
*/
Order::Order(const YAML::Node& node) {
	this->parseYaml(node);
}

/*
/Retrieves the order's ID number
/Pre: None
/Post: Returns the order's ID number
*/
int Order::getOrderID() const {
	return myOrderID;
}

/*
/Retrieves the customer's ID number
/Pre: None
/Post: Returns the customer's ID number
*/
int Order::getCustomerID() const {
	return myCustomerID;
}

/*
/Retrieves the SKU of the order
/Pre: None
/Post: Returns the SKU
*/
int Order::getSKU() const {
	return mySKU;
}

/*
/Retrieves the quantity of the ordered item
/Pre: None
/Post: Returns the quantity of the item
*/
int Order::getQuantity() const {
	return myQuantity;
}

/*
/Retrieves the price of the ordered item
/Pre: None
/Post: Returns the price of the item
*/
int Order::getPrice() const {
	return myPrice;
}

/*
/Retrieves the date the order was placed
/Pre: None
/Post: Returns the date of the order
*/
const Date& Order::getDate() const {
	return myDate;
}

/*
/Sets the data of an order to that of the information stored on a node in the YAML
/Pre: A node is passed in with the order's information
/Post: And order's values are set to the information passed in
*/
void Order::parseYaml(const YAML::Node& node) {
	node["myOrderID"] >> this->myOrderID;
	node["myCustomerID"] >> this->myCustomerID;
	node["mySKU"] >> this->mySKU;
	node["myQuantity"] >> this->myQuantity;
	node["myPrice"] >> this->myPrice;
	std::string temp;
	node["myDate"] >> temp;
	this->setDate(Date(temp));
}

/*
/Sets an order's ID to the passed in integer
/Pre: A 
/Post:
*/
void Order::setOrderID(int orderID) {
	myOrderID = orderID;
}

void Order::setCustomerID(int customerID) {
	myCustomerID = customerID;
}

void Order::setSKU(int SKU) {
	mySKU = SKU;
}

void Order::setQuantity(int quantity) {
	myQuantity = quantity;
}

void Order::setPrice(int price) {
	myPrice = price;
}

void Order::setDate(const Date& date) {
	myDate = date;
}
