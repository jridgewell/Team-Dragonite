#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include "Customer.h"
#include "Merchant.h"

class Controller
{
private:
	int myUserID;

public:
	Controller();
	virtual ~Controller();

	void displayCustomerLogin() const;
	const Customer::Customer& customerLogin(const std::string& username, const std::string& password);
	const Customer::Customer& createCustomer(const std::string& username, const std::string& password);

	void displayMerchantLogin() const;
	const Merchant::Merchant& merchantLogin(const std::string& username, const std::string& password) const;

	void setUserID(int id);
	const int getUserID() const;
};

#endif
