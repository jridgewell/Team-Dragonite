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
 * 	 Comments:  Andrew Wagenheim
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
* Gets the customer's ID
* Pre: None
* Post: Returns the customer's ID
*/
int Customer::getCustomerID() const{
	return myCustomerID;
}


/*
* Gets the customer's username
* Pre: None
* Post: Returns the customers's username
*/
const std::string& Customer::getUsername() const{
	return myUsername;
}


/*
* Gets the customer's password
* Pre: None
* Post: Returns the customers's password
*/
const std::string& Customer::getPassword() const{
	return myPassword;
}

/*
* Gets the customer's full name
* Pre: None
* Post: Returns the customer's full name
*/
const std::string& Customer::getFullName() const{
	return myFullName;
}

/*
* Gets the customer's address
* Pre: None
* Post: Returns the customer's address
*/
const std::string& Customer::getAddress() const{
	return myAddress;
}

/*
* Gets the customer's city
* Pre: None
* Post: Returns the customer's city
*/
const std::string& Customer::getCity() const{
	return myCity;
}

/*
* Gets the customer's state
* Pre: None
* Post: Returns the customer's state
*/
const std::string& Customer::getState() const{
	return myState;
}

/*
* Gets the customer's zip code
* Pre: None
* Post: Returns the customer's zip code
*/
int Customer::getZip() const{
	return myZip;
}

/*
* Gets the account balance
* Pre: None
* Post: Returns the customer's account balance
*/
int Customer::getMoney() const{
	return myMoney;
}

/*
* Set's a customer's information to the information stored on the YAML
* Pre: A node with customer data from the YAML is passed in
* Post: The customer's values are set to the contained in the node
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
* Sets the customer id
* Pre: A customer id value is passed in as an int
* Post: The myCustomerID value becomes the input value
*/
void Customer::setCustomerID(const int customerID){
	myCustomerID = customerID;
}

/*
* Sets the customer's username
* Pre: A customer username value is passed in as a string
* Post: The myUsername value is set to the input value
*/
void Customer::setUsername(const std::string& username){
	myUsername = username;
}

/*
* Sets the customer's password
* Pre: A customer password value is passed in as an int
* Post: The myPassword value is set to the input value
*/
void Customer::setPassword(const std::string& password){
	myPassword = password;
}


/*
* Sets the customer's full name
* Pre: A customer full name value is passed in as a string
* Post: The myFullName value is set to the input value
*/
void Customer::setFullName(const std::string& fullName){
	myFullName = fullName;
}


/*
* Sets the customer's address
* Pre: A customer address value is passed in as a string
* Post: The myAddress value is set to the input value
*/
void Customer::setAddress(const std::string& address){
	myAddress = address;
}


/*
* Sets the customer's city
* Pre: A customer city value is passed in as a string
* Post: The myCity value is set to the input value
*/
void Customer::setCity(const std::string& city){
	myCity = city;
}

/*
* Sets the customer's state
* Pre: A customer state value is passed in as a string
* Post: The myState value is set to the input value
*/
void Customer::setState(const std::string& state){
	myState = state;
}


/*
* Sets the customer's zip code
* Pre: A customer zip code value is passed in as an int
* Post: The myZipCode value is set to the input value
*/
void Customer::setZip(const int zip){
	myZip = zip;
}

/*
* Sets the customer's account balance
* Pre: A customer account balnce  value is passed in as an int
* Post: The myMoney value is set to the input value
*/
void Customer::setMoney(const int money){
	myMoney = money;
}
