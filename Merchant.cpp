/*
 * =====================================================================================
 *
 *       Filename:  Merchant.cpp
 *
 *    Description:  Class implementation for Merchant
 *

 *        Version:  1.0
 *        Created:  04/29/2012
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew Wagenheim
 *   Organization:  Team Dragonite
 *
 * =====================================================================================
 */
#include "Merchant.h"


/*
* Default constructor, creates a new merchant with default values
* Pre: None
* Post: Merchant created with default values
*/
Merchant::Merchant() {
	this->setMerchantID(0);
	this->setUsername("username");
	this->setPassword("password");
}

/*
* Creates a new merchant passed in values
* Pre: Values for username and password are passed in as strings
* Post: Merchant created with input values
*/
Merchant::Merchant(const int merchantID, const std::string& username, const std::string& password) {
	this->setMerchantID(merchantID);
	this->setUsername(username);
	this->setPassword(password);
}

/*
* Clones an existing merchant
* Pre: An existing merchant object is passed in
* Post: A new merchant is made using the same values
*/
Merchant::Merchant(const Merchant& merchant) {
	this->setMerchantID(merchant.myMerchantID);
	this->setUsername(merchant.myUsername);
	this->setPassword(merchant.myPassword);
}

/*
* Pushes merchant data onto the YAML for storage
* Pre: The YAML is passed in on which the data will be stored
* Post: The data of the merchant is stored on the YAML
*/
Merchant::Merchant(const YAML::Node& node) {
	this->parseYaml(node);
}

YAML::Emitter& Merchant::emitYaml(YAML::Emitter& out) const {
        out << YAML::BeginMap;
        out << YAML::Key << "myMerchantID";
        out << YAML::Value << this->myMerchantID;
        out << YAML::Key << "myUsername";
        out << YAML::Value << this->myUsername;
        out << YAML::Key << "myPassword";
        out << YAML::Value << this->myPassword;
        out << YAML::EndMap;
        return out;
}

/*
* Gets the Merchant's ID
* Pre: None
* Post: Returns the merchant's ID
*/
int Merchant::getMerchantID() const {
	return myMerchantID;
}

/*
* Gets the Merchant's username
* Pre: None
* Post: Returns the merchant's username
*/
const std::string& Merchant::getUsername() const {
	return myUsername;
}

/*
* Gets the password of the Merchant
* Pre: None
* Post: Returns the merchant's password
*/
const std::string& Merchant::getPassword() const {
	return myPassword;
}

/*
* Sets a merchants information to the information stored on the YAML
* Pre: A node from the YAML is passed in
* Post: The merchant's values are set to that contained in the node
*/
void Merchant::parseYaml(const YAML::Node& node) {
	node["myMerchantID"] >> this->myMerchantID;
	node["myUsername"] >> this->myUsername;
	node["myPassword"] >> this->myPassword;
}

/*
* Sets merchant's ID to the input value
* Pre: A ID integer is passed in
* Post: The merchant's ID is changed to the new value
*/
void Merchant::setMerchantID(const int merchantID) {
	myMerchantID = merchantID;
}

/*
* Sets merchant's username to the input value
* Pre: A username string is passed in
* Post: The merchant's username is changed to the new value
*/
void Merchant::setUsername(const std::string& username) {
	myUsername = username;
}

/*
* Set merchant's password to the input value
* Pre: A password string is passed in
* Post: The merchant's password is changed to the new value
*/
void Merchant::setPassword(const std::string& password) {
	myPassword = password;
}
