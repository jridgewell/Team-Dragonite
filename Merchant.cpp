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

//TODO: javadocs

Merchant::Merchant() {
	this->setUserName(0);
	this->setPassword(0);
}

Merchant::Merchant(string userName, string password) {
	this->setUserName(userName);
	this->setpassword(password);
}

Merchant::Merchant(const Merchant& merchant) {
	this->setUserName(merchant.myUserName);
	this->setPassword(merchant.myPassword);
}

Merchant::Merchant(const YAML::Node& node) {
	this->parseYaml(node);
}

string Merchant::getUserName() const {
	return myUserName();
}

string Merchant::getPassword() const {
	return myPassword();
}

void Merchant::parseYaml(const YAML::Node& node) {
	node["myUserName"] >> this->myUserName;
	node["myPassword"] >> this->myPassword;
}

void Merchant::setUserName(string username) {
	myUserName = username;
}

void Merchant::setPassword(string password) {
	myPassword = password;
}
