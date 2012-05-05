#include "Controller.h"

Controller::Controller()
{
	File::parseFileToMap<std::string, Category::Category, categoryKeyExtractor>("data/Category.yaml", myCategories);
	File::parseFileToMap<std::string, Merchant::Merchant, merchantKeyExtractor>("data/Merchant.yaml", myMerchants);
	File::parseFileToVector("data/Customer.yaml", myCustomers);
	File::parseFileToVector("data/Inventory.yaml", myInventories);
	File::parseFileToVector("data/Order.yaml", myOrders);
}

Controller::~Controller()
{
	File::deleteMap(myCategories);
	File::deleteMap(myMerchants);
	File::deleteVector(myCustomers);
	File::deleteVector(myInventories);
	File::deleteVector(myOrders);
}

void Controller::displayLogin()
{
	std::string input;
	bool cont = true;
	std::cout << "Are you a Customer or a Merchant? [CM]" << std::endl;
	Input::getLine(input);
	char c = input[0];
	while(cont)
	{
		switch(c)
		{
			case 'c':
			case 'C':
				cont = false; 
				this -> displayCustomerLogin();
				break;
			case 'm':
			case 'M':
				cont = false; 
				this -> displayMerchantLogin();
				break;
			default:
				std::cout << "Please type either C or M." << std::endl;
				Input::getLine(input);
				c = input[0];	
				break;
		}
	}
}

void Controller::displayCustomerLogin()
{
	std::string input;
	std::string username, password;
	bool cont = true; 
	std::cout << "New or Returning User? [NR]" << std::endl;
	Input::getLine(input);
	char c = input[0];
	while(cont)
	{
		switch(c)
		{
			case'r':
			case'R':
				cont = false;
				std::cout << "Enter your username: ";
				Input::getLine(username);
				std::cout << "Enter your password: ";
				Input::getLine(password); 
				if(this -> customerLogin(username, password) == NULL)
				{
					cont = true;
					std::cout << "Invalid username or password." << std::endl;
					std::cout << "New or Returning User? [NR]" << std::endl;
					Input::getLine(input);
					c = input[0]; 
				}
				break;
			case 'n':
			case 'N':
				cont = true;
				this -> createCustomer();
				std::cout << "New or Returning User? [NR]" << std::endl;
				Input::getLine(input);
				c = input[0];
				break;
			default:
				std::cout << "Please type either N or R." << std::endl;
				Input::getLine(input);
				c = input[0];
				break;
		}
	}
}

Customer::Customer* Controller::customerLogin(const std::string& username, const std::string& password)
{
	Customer* customer = this -> getCustomer(username);

	if(customer == NULL || customer -> getPassword() != password)
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
	std::string username, password, fullName, address, city, state, zipStr, moneyStr;

	id = myCustomers.size();

	std::cout << "Username: ";
	Input::getLine(username);
	while(this -> getCustomer(username) != NULL)
	{
		std::cout << "Username already in use. Please enter another username: ";
		Input::getLine(username);
	}
	std::cout << "Password: ";
	Input::getLine(password);
	std::cout << "Full name: ";
	Input::getLine(fullName);
	std::cout << "Address: ";
	Input::getLine(address);
	std::cout << "City: ";
	Input::getLine(city);
	std::cout << "State: ";
	Input::getLine(state);
	std::cout << "Zip code: ";
	Input::getLine(zipStr);
	std::cout << "Starting balance: ";
	Input::getLine(moneyStr);

	zip = atoi(zipStr.c_str());
	money = atoi(moneyStr.c_str());

	Customer::Customer* customer = new Customer(id, username, password, fullName, address, city, state, zip, money);
	myCustomers.push_back(customer);
}

void Controller::displayMerchantLogin()
{
        std::string input;
        bool cont = true;
        std::cout << "Enter Username" << std::endl;
        std::cin >> input;
        std::map<std::string, Merchant*>::const_iterator itr;
        itr = myMerchants.find(input);
        if (itr == myMerchants.end()) {
                std::cout << "Invalid Username" << std::endl;
        } else {
                std::string input2;
                Merchant::Merchant m = *(itr->second);
                std::string password = m.getPassword();
                std::cout << "Enter Password" << std::endl;
                std::cin >> input2;
                if( input2 == password) {
                        std::cout << "Welcome back, " << input << "You can Add/change inventory price, List inventory, Remover inventory, Display orders by customer ID, or show inventory Categories.[ALRDC]" << std::endl;
                } else {
                        std::cout << "Invalid Password" << std::endl;
                }

        }
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

