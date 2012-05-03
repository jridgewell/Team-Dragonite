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


Customer::Customer() 
/*
* Default constructor, creates a new customer with default values
* Pre: None
* Post: A new customer is created with the default values
*/
{
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


/*
* Creates a new customer with the passed in values
* Pre: Int values for the customer ID, zip code, and money are passed in. String values for the username, password, full name, address, city and state are passed in
* Post: A new customer is created with the input values
*/
Customer::Customer(const int customerID, const std::string& username, const std::string& password, const std::string& fullName, const std::string& address, const std::string& city, const std::string& state, const int zip, const int money) {
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


/*
* Clones an existing customer object
* Pre: An existing customer object is passed in
* Post: A new customer is made using the same values
*/
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


/*
* Pushes customer data onto the YAML for storage
* Pre: The node from the YAML is passed in on which the data will be stored
* Post: The data of the customer is stored on the YAML
*/
Customer::Customer(const YAML::Node& node) {
	this->parseYaml(node);
}


/*
* Retrieves the customer's ID
* Pre: None
* Post: Returns the customer's ID
*/
int Customer::getCustomerID() const{
	return myCustomerID;
}


/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
const std::string& Customer::getUsername() const{
	return myUsername;
}


/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
const std::string& Customer::getPassword() const{
	return myPassword;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
const std::string& Customer::getFullName() const{
	return myFullName;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
const std::string& Customer::getAddress() const{
	return myAddress;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
const std::string& Customer::getCity() const{
	return myCity;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
const std::string& Customer::getState() const{
	return myState;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
int Customer::getZip() const{
	return myZip;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
int Customer::getMoney() const{
	return myMoney;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
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

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
void Customer::setCustomerID(const int customerID){
	myCustomerID = customerID;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
void Customer::setUsername(const std::string& username){
	myUsername = username;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
void Customer::setPassword(const std::string& password){
	myPassword = password;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
void Customer::setFullName(const std::string& fullName){
	myFullName = fullName;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
void Customer::setAddress(const std::string& address){
	myAddress = address;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
void Customer::setCity(const std::string& city){
	myCity = city;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
void Customer::setState(const std::string& state){
	myState = state;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
void Customer::setZip(const int zip){
	myZip = zip;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
void Customer::setMoney(const int money){
	myMoney = money;
}
