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

//TODO: javadocs

Merchant::Merchant() {
	this->setUsername("username");
	this->setPassword("password");
}

Merchant::Merchant(const std::string& username, const std::string& password) {
	this->setUsername(username);
	this->setPassword(password);
}

Merchant::Merchant(const Merchant& merchant) {
	this->setUsername(merchant.myUsername);
	this->setPassword(merchant.myPassword);
}

Merchant::Merchant(const YAML::Node& node) {
	this->parseYaml(node);
}

const std::string& Merchant::getUsername() const {
	return myUsername;
}

const std::string& Merchant::getPassword() const {
	return myPassword;
}

void Merchant::parseYaml(const YAML::Node& node) {
	node["myUsername"] >> this->myUsername;
	node["myPassword"] >> this->myPassword;
}

void Merchant::setUsername(const std::string& username) {
	myUsername = username;
}

void Merchant::setPassword(const std::string& password) {
	myPassword = password;
}
