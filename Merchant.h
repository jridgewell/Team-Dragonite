#ifndef Merchant_H
#define Merchant_H
/*
 * =====================================================================================
 *
 *       Filename:  Merchant.h
 *
 *    Description:  Header file for Merchant class
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
#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>
#include "Merchant.h"

//TODO javadocs

class Merchant {
	private:
		string myUserName;
		string myPassword;
	public:
		Merchant();
		Merchant(string userName, string password);
		Merchant(const Merchant& Merchant);
		Merchant(const YAML::Node& node);
		virtual ~Merchant() {}
		string getUserName() const;
		string getPassword() const;
		const Merchant& getMerchant() const;
		void parseYAML(const YAML::Node node);
		void setUserName(string userName) const;
		void setPassword(string password) const;
};
#endif
