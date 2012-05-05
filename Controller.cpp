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

const Customer::Customer& Controller::customerLogin(const std::string& username, const std::string& password)
{
}

const Customer::Customer& Controller::createCustomer(const std::string& username, const std::string& password)
{
}

void Controller::displayMerchantLogin() const
{
}

const Merchant::Merchant& Controller::merchantLogin(const std::string& username, const std::string& password) const
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

