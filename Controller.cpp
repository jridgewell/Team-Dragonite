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

Customer::Customer& Controller::customerLogin(const std::string& username, const std::string& password)
{
}

Customer::Customer& Controller::createCustomer(const std::string& username, const std::string& password)
{
}

void Controller::displayMerchantLogin() const
{
}

Merchant::Merchant& Controller::merchantLogin(const std::string& username, const std::string& password)
{
}

Customer::Customer& getCustomer(int customerID)
{
}

Merchant::Merchant& getMerchant(int merchantID)
{
}

void Controller::setUserID(int id)
{
	myUserID = id;
}

const int Controller::getUserID() const
{
	return myUserID;
}

