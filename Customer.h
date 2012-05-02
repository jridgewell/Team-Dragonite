#ifndef CUSTOMER_H
#define CUSTOMER_H
/*
 * =====================================================================================
 *
 *       Filename:  Customer.h
 *
 *    Description:  Header file for Customer class
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
#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>

//TODO: javadocs

class Customer {
	private:
		int myCustomerID;
		std::string myUsername;
		std::string myPassword;
		std::string myFullName;
		std::string myAddress;
		std::string myCity;
		std::string myState;
		int myZip;
		int myMoney;
	public:
		Customer();
		Customer(const int customerID, const std::string& username, const std::string& password, const std::string& fullName, const std::string& address, const std::string& city, const std::string& state, const int zip, const int money);
		Customer(const Customer& customer);
		Customer(const YAML::Node& node);
		virtual ~Customer() {}
		int getCustomerID() const;
		const std::string& getUsername() const;
		const std::string& getPassword() const;
		const std::string& getFullName() const;
		const std::string& getAddress() const;
		const std::string& getCity() const;
		const std::string& getState() const;
		int getZip() const;
		int getMoney() const;
		void parseYaml(const YAML::Node& node);
		void setCustomerID(const int customerID);
		void setUsername(const std::string& username);
		void setPassword(const std::string& password);
		void setFullName(const std::string& fullName);
		void setAddress(const std::string& address);
		void setCity(const std::string& city);
		void setState(const std::string& state);
		void setZip(const int zip);
		void setMoney(const int money);
};
#endif
