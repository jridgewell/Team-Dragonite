#ifndef MERCHANT_H
#define MERCHANT_H
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

/*
* Outlines the Merchant class and the features contained therein. 
* Merchants consist of a username and password
* Creates merchants through one of the following:
* 1) A default constructor
* 2) A constructor with passed in values
* 3) An existing merchant object, copying its values
* 4) Merchant data retrieved from a node on the YAML
* In addition, the class is able to set/get the merchant's username and password
*/

class Merchant {
	private:
		int myMerchantID;
		std::string myUsername;
		std::string myPassword;
	public:
		Merchant();
		Merchant(const int merchantID, const std::string& username, const std::string& password);
		Merchant(const Merchant& Merchant);
		Merchant(const YAML::Node& node);
		virtual ~Merchant() {}
		int getMerchantID() const;
		const std::string& getUsername() const;
		const std::string& getPassword() const;
		YAML::Emitter& emitYaml(YAML::Emitter& out) const;
		void parseYaml(const YAML::Node& node);
		void setMerchantID(const int merchantID);
		void setUsername(const std::string& username);
		void setPassword(const std::string& password);
};
#endif
