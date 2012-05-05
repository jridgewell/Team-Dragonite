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
	if(this -> getCustomer(username) == NULL)
	{
		return NULL;
	}
	else
	{
		Customer* customer = this -> getCustomer(username);
		this -> setUsername(customer -> getUsername());
	}
}

Customer::Customer* Controller::createCustomer()
{
	int id, zip, money;
	std::string username, password, fullName, address, city, state;

	id = myCustomers.size() + 1;

	std::cout << "Username: ";
	std::cin >> username;
	std::cout << "Password: ";
	std::cin >> password;
	std::cout << "Full name: ";
	std::cin >> fullName;
	std::cout << "Address: ";
	std::cin >> address;
	std::cout << "City: ";
	std::cin >> city;
	std::cout << "State: ";
	std::cin >> state;
	std::cout << "Zip code: ";
	std::cin >> zip;
	std::cout << "Starting balance: ";
	std::cin >> money;

	Customer::Customer* customer = new Customer(id, username, password, fullName, address, city, state, zip, money);
	myCustomers.push_back(customer);
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

