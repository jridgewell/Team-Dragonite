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

//TODO javadocs

class Merchant {
	private:
		std::string myUsername;
		std::string myPassword;
	public:
		Merchant();
		Merchant(const std::string& username, const std::string& password);
		Merchant(const Merchant& Merchant);
		Merchant(const YAML::Node& node);
		virtual ~Merchant() {}
		const std::string& getUsername() const;
		const std::string& getPassword() const;
		void parseYaml(const YAML::Node& node);
		void setUsername(const std::string& username);
		void setPassword(const std::string& password);
};
#endif
