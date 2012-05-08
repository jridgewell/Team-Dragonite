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
 *       Comments:  Andrew Wagenheim
 *   Organization:  Team Dragonite
 *
 * =====================================================================================
 */
#include "Order.h"

/*
* Default constructor, creates a new order with the default values
* Pre: None
* Post: Order is created with default value
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
* Creates a new order with the input values
* Pre: Values for the order id, customer id, SKY, quantity, price and date are input
* Post: A new order is created with the passed in values
*/
Order::Order(const int orderID, const int customerID, const int SKU, const int quantity, const int price, const Date& date) {
	this->setOrderID(orderID);
	this->setCustomerID(customerID);
	this->setSKU(SKU);
	this->setQuantity(quantity);
	this->setPrice(price);
	this->setDate(date);
}

/*
* Clones an order object
* Pre: An order is passed in
* Post: A new order is created with the same values as the passed in one
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
* Pushes an order's data on the YAML
* Pre: The node where the data will be stored is passed in
* Post: The order's information is stored on the node
*/
Order::Order(const YAML::Node& node) {
	this->parseYaml(node);
}

/*
* Retrieves the order's ID number
* Pre: None
* Post: Returns the order's ID number
*/
int Order::getOrderID() const {
	return myOrderID;
}

/*
* Retrieves the customer's ID number
* Pre: None
* Post: Returns the customer's ID number
*/
int Order::getCustomerID() const {
	return myCustomerID;
}

/*
* Retrieves the SKU of the order
* Pre: None
* Post: Returns the SKU
*/
int Order::getSKU() const {
	return mySKU;
}

/*
* Retrieves the quantity of the ordered item
* Pre: None
* Post: Returns the quantity of the item
*/
int Order::getQuantity() const {
	return myQuantity;
}

/*
* Retrieves the price of the ordered item
* Pre: None
* Post: Returns the price of the item
*/
int Order::getPrice() const {
	return myPrice;
}

/*
* Retrieves the date the order was placed
* Pre: None
* Post: Returns the date of the order
*/
const Date& Order::getDate() const {
	return myDate;
}

/*
* Sets the data of an order to that of the information stored on a node in the YAML
* Pre: A node is passed in with the order's information
* Post: And order's values are set to the information passed in
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

/**
* Stores newly created Orders on the YAML
* Pre: An emitter is passed in to store data on
* Post: The new order is placed in the YAML
*/
YAML::Emitter& Order::emitYaml(YAML::Emitter& out) const {
        out << YAML::BeginMap;
        out << YAML::Key << "myOrderID";
        out << YAML::Value << this->myOrderID;
        out << YAML::Key << "myCustomerID";
        out << YAML::Value << this->myCustomerID;
        out << YAML::Key << "mySKU";
        out << YAML::Value << this->mySKU;
        out << YAML::Key << "myQuantity";
        out << YAML::Value << this->myQuantity;
        out << YAML::Key << "myPrice";
        out << YAML::Value << this->myPrice;
        out << YAML::Key << "myDate";
        out << YAML::Value << (this->myDate).serializeDate();
        out << YAML::EndMap;
        return out;
}

/*
* Sets an order's ID number to a passed in integer
* Pre: An integer is passed in
* Post: The Order's ID is set to the passed in value
*/
void Order::setOrderID(const int orderID) {
	myOrderID = orderID;
}

/*
* Sets the customer's ID number of an associated order to a passed in integer
* Pre: An integer is passed in
* Post: The Customer's ID is set to the passed in value
*/
void Order::setCustomerID(const int customerID) {
	myCustomerID = customerID;
}

/*
* Sets the SKU of an order to a passed in value
* Pre: An integer is passed in
* Post: The SKU of the order is set to the passed in value
*/
void Order::setSKU(const int SKU) {
	mySKU = SKU;
}

/*
* Sets the quantity of items ordered to a passed in value
* Pre: An integer is passed in
* Post: The quantity of items ordered is set to the passed in value
*/
void Order::setQuantity(const int quantity) {
	myQuantity = quantity;
}

/*
* Sets the price of an item in an order to a passed in value
* Pre: An integer is passed in
* Post: The price of the item ordered is set to the passed in value
*/
void Order::setPrice(const int price) {
	myPrice = price;
}

/*
* Sets the date of the order to a passed in date
* Pre: A date object is passed in
* Post: The date of the order is set to the values inherited from the date object
*/
void Order::setDate(const Date& date) {
	myDate = date;
}
