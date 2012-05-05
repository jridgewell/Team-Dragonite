#include "Controller.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::displayCustomerLogin() const
{
}

Customer::Customer* Controller::customerLogin(const std::string& username, const std::string& password)
{
	Customer* customer = this -> getCustomer(username);
	this -> setUsername(customer -> getUsername());
}

Customer::Customer* Controller::createCustomer(const std::string& username, const std::string& password)
{
}

void Controller::displayMerchantLogin() const
{
}

Merchant::Merchant* Controller::merchantLogin(const std::string& username, const std::string& password)
{
}

Customer::Customer* Controller::getCustomer(const std::string& username)
{
	for(int i = 0; i < myCustomers.size(); i++)
	{
		if(myCustomers.at(i) -> getUsername() == username)
			return myCustomers.at(i);
	}
	return NULL;
}

Merchant::Merchant* Controller::getMerchant(const std::string& username)
{
}

void Controller::setUsername(const std::string& username)
{
	myUsername = username;
}

const std::string& Controller::getUsername() const
{
	return myUsername;
}

