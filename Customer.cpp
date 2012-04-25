/*
 * =====================================================================================
 *
 *       Filename:  Customer.cpp
 *
 *    Description:  Class implementation for Customer
 *
 *        Version:  1.0
 *        Created:  04/20/2012 20:11:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Justin Ridgewell
 *   Organization:  Team Dragonite
 *
 * =====================================================================================
 */
#include "Customer.h"

//TODO: javadocs

Customer::Customer() {
	this->setCustomerID(0);
	this->setUsername("username");
	this->setPassword("password");
	this->setFullName("First Last");
	this->setAddress("123 Street Dr.");
	this->setCity("City");
	this->setState("State");
	this->setZip(12345);
	this->setMoney(0);
}

Customer::Customer(const int customerID, const std::string &username, const std::string &password, const std::string &fullName, const std::string &address, const std::string &city, const std::string &state, const int zip, const int money) {
	this->setCustomerID(customerID);
	this->setUsername(username);
	this->setPassword(password);
	this->setFullName(fullName);
	this->setAddress(address);
	this->setCity(city);
	this->setState(state);
	this->setZip(zip);
	this->setMoney(money);
}

Customer::Customer(const Customer& customer) {
	this->setCustomerID(customer.myCustomerID);
	this->setUsername(customer.myUsername);
	this->setPassword(customer.myPassword);
	this->setFullName(customer.myFullName);
	this->setAddress(customer.myAddress);
	this->setCity(customer.myCity);
	this->setState(customer.myState);
	this->setZip(customer.myZip);
	this->setMoney(customer.myMoney);
}

Customer::Customer(const YAML::Node& node) {
	this->parseYaml(node);
}

int Customer::getCustomerID() const{
	return myCustomerID;
}

const std::string& Customer::getUsername() const{
	return myUsername;
}

const std::string& Customer::getPassword() const{
	return myPassword;
}

const std::string& Customer::getFullName() const{
	return myFullName;
}

const std::string& Customer::getAddress() const{
	return myAddress;
}

const std::string& Customer::getCity() const{
	return myCity;
}

const std::string& Customer::getState() const{
	return myState;
}

int Customer::getZip() const{
	return myZip;
}

int Customer::getMoney() const{
	return myMoney;
}

void Customer::parseYaml(const YAML::Node& node) {
	node["myCustomerID"] >> this->myCustomerID;
	node["myUsername"] >> this->myUsername;
	node["myPassword"] >> this->myPassword;
	node["myFullName"] >> this->myFullName;
	node["myAddress"] >> this->myAddress;
	node["myCity"] >> this->myCity;
	node["myState"] >> this->myState;
	node["myZip"] >> this->myZip;
	node["myMoney"] >> this->myMoney;
}

void Customer::setCustomerID(const int customerID){
	myCustomerID = customerID;
}

void Customer::setUsername(const std::string &username){
	myUsername = username;
}

void Customer::setPassword(const std::string &password){
	myPassword = password;
}

void Customer::setFullName(const std::string &fullName){
	myFullName = fullName;
}

void Customer::setAddress(const std::string &address){
	myAddress = address;
}

void Customer::setCity(const std::string &city){
	myCity = city;
}

void Customer::setState(const std::string &state){
	myState = state;
}

void Customer::setZip(const int zip){
	myZip = zip;
}

void Customer::setMoney(const int money){
	myMoney = money;
}