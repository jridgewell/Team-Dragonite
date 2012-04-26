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

Order::Order() {
	this->setOrderID(0);
	this->setCustomerID(0);
	this->setSKU(0);
	this->setQuantity(0);
	this->setPrice(0);
	this->setDate(Date());
}

Order::Order(int orderID, int customerID, int SKU, int quantity, int price, const Date& date) {
	this->setOrderID(orderID);
	this->setCustomerID(customerID);
	this->setSKU(SKU);
	this->setQuantity(quantity);
	this->setPrice(price);
	this->setDate(date);
}

Order::Order(const Order& order) {
	this->setOrderID(order.myOrderID);
	this->setCustomerID(order.myCustomerID);
	this->setSKU(order.mySKU);
	this->setQuantity(order.myQuantity);
	this->setPrice(order.myPrice);
	this->setDate(order.myDate);
}

Order::Order(const YAML::Node& node) {
	this->parseYaml(node);
}

int Order::getOrderID() const {
	return myOrderID;
}

int Order::getCustomerID() const {
	return myCustomerID;
}

int Order::getSKU() const {
	return mySKU;
}

int Order::getQuantity() const {
	return myQuantity;
}

int Order::getPrice() const {
	return myPrice;
}

const Date& Order::getDate() const {
	return myDate;
}

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