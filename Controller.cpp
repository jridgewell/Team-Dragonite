#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

class Controller
{
private:
	int myUserID;
	map<string, Category*> myCategories;
	map<string, Merchant*> myMerchants;
	vector<Customer*> myCustomers;
	vector<inventory*> myInventories;
	vector<Order*> myOrder;

public:
	Controller();
	virtual ~Controller();

	displayCustomerLogin() const;
	const Customer::Customer& customer customerLogin(const std::string& username, const std::string& password) const;
	const Customer::Customer& customer createCustomer(const std::string& username, const std::string& password) const;

	displayMerchantLogin() const;
	const Customer::Merchant& merchant merchantLogin(const std::string& username, const std::string& password) const;

	setUserID(int id);
	const int getUserID() const;
};

#endif
