#include "Controller.h"

Controller::Controller()
{
}

virtual Controller::~Controller()
{
}

Controller::displayCustomerLogin() const
{
}

const Customer::Customer& customer Controller::customerLogin(const std::string& username, const std::string& password)
{
}

const Customer::Customer& customer Controller::createCustomer(const std::string& username, const std::string& password)
{
}

Controller::displayMerchantLogin() const
{
}

const Customer::Merchant& merchant Controller::merchantLogin(const std::string& username, const std::string& password) const
{
}

Controller::setUserID(int id)
{
	myUserID = id;
}

const int getUserID() const
{
	return myUserID;
}

