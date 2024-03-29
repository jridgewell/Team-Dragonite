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
 *	 Comments:  Andrew Wagenheim
 *   Organization:  Team Dragonite
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>

/*
* Outlines the Customer class and the features contained therein.
* Customers consist of a username, password, full name, address, city, state, zip code, and account balance
* Creates customers through one of the following:
* 1) A default constructor
* 2) A constructor with passed in values
* 3) An existing customer object, copying its values
* 4) Customer data retrieved from a node on the YAML
* In addition, the class is able to set/get the merchant's username and password
*/

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

		int purchase(const int money);
		int updateBalance(const int money);

		int getCustomerID() const;
		const std::string& getUsername() const;
		const std::string& getPassword() const;
		const std::string& getFullName() const;
		const std::string& getAddress() const;
		const std::string& getCity() const;
		const std::string& getState() const;
		int getZip() const;
		int getMoney() const;

		void setCustomerID(const int customerID);
		void setUsername(const std::string& username);
		void setPassword(const std::string& password);
		void setFullName(const std::string& fullName);
		void setAddress(const std::string& address);
		void setCity(const std::string& city);
		void setState(const std::string& state);
		void setZip(const int zip);
		void setMoney(const int money);

		YAML::Emitter& emitYaml(YAML::Emitter& out) const;
		void parseYaml(const YAML::Node& node);
};
#endif
