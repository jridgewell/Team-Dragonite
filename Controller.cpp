#include "Controller.h"

Controller::Controller()
{
	isCustomer = false;
	isMerchant = false;
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
	char c;
	while(cont)
	{
		std::cout << "New or Returning User? [NR]" << std::endl;
		Input::getLine(input);
		c = input[0];
		switch(c)
		{
			case'r':
			case'R':
				std::cout << "Enter your username: ";
				Input::getLine(username);
				std::cout << "Enter your password: ";
				Input::getLine(password); 
				if(this->checkCustomerLogin(username, password)) 
				{
					cont = false;
					myCustomer = this->getCustomer(username);
					isCustomer = true;
				} 
				else 
				{
					std::cout << "Invalid username or password." << std::endl;
				}
				
				break;
			case 'n':
			case 'N':
				this -> createCustomer();
				break;
			default:
				std::cout << "Please type either N or R." << std::endl;
				break;
		}
	}
	if (isCustomer) {
		this->customerInterface();
	}
}

void Controller::customerInterface()
{
	Customer* customer = this -> getCustomer(myUsername);
	char c;
	char * skuChar;
	int skuInt, quantityInt, changeInt;
	bool cont = true;
	std::string input;
	std::string sku, quantity, change;
	std::cout << "Enter 1 to place an order. Enter 2 to view past orders. Enter 3 to change amount in account. Enter 4 to display inventory. Enter 5 to exit" << std::endl;
	Input::getLine(input);
	c = input[0];
	while(cont)
	{
		std::cout << "Enter 1 to place an order. Enter 2 to view past orders. Enter 3 to change amount in account. Enter 4 to display inventory. Enter 5 to exit" << std::endl;
		Input::getLine(input);
		c = input[0];
		if(c == '1')
		{
			std::cout << "Enter the SKU for your purchase." << std::endl;
			Input::getLine(sku);
			skuChar = &sku[0]; 
			skuInt = atoi(skuChar);

			std::cout << "Enter the quantity for your purchase." << std::endl;
			Input::getLine(quantity);
			while(!Input::isNumeric(quantity))
			{
				std::cout << "Invalid quantity. Please try again: ";
				Input::getLine(quantity);
			}
			quantityInt = atoi(quantity.c_str());
			this -> purchase(skuInt, quantityInt);	
		}

		else if(c == '2')
		{
			this -> displayCustomerOrders();
		}
	
		else if(c == '3')
		{
			std::cout << "Enter amount to change account balance by" << std::endl;
			Input::getLine(change);
			while(!Input::isNumeric(change))
			{
				std::cout << "Invalid amount. Please try again: ";
				Input::getLine(change);
			}
			changeInt = atoi(change.c_str());
			customer -> balance(changeInt);
		}
		
		else if(c == '4')
		{
			this -> displayInventory();
		}
		
		else if(c == '5')
		{
			cont = false;
		}
	}
}
	

void Controller::displayInventory()
{
	std::cout << std::left << std::setw(10) << "SKU" << std::left << std::setw(20) << "Item Description" << std::right << std::setw(10) << "Price" << std::right << std::setw(10) << "Quantity" << std::endl;
	for(int i = 0; i < myInventories.size(); i++)
	{
		std::cout << std::left << std::setw(10) << myInventories[i] -> getSKU() << std::left << std::setw(20) << myInventories[i] -> getItemDesc()<< std::right <<  std::setw(10) << myInventories[i] -> getPrice() << std::right << std::setw(10) << myInventories[i] -> getQuantity() << std::endl;
	}
}

void Controller::displayCustomerOrders()
{
	std::cout << std::left << std::setw(10) << "Order ID" << std::left << std::setw(10) << "SKU" << std::left << std::setw(20) << "Item Description" << std::left << std::setw(10) << "Quantity" << std::left << std::setw(10) << "Price" << std::right << std::setw(10) << "Date" << std::endl;

 for(int i = 0; i < myOrders.size(); i++)
        {
                const int orderSKU = myOrders[i] -> getSKU();
                Date orderDate = myOrders[i] -> getDate();
                 std::cout << std::left << std::setw(10) << myOrders[i] -> getOrderID() << std::left << std::setw(10) << myOrders[i] -> getSKU() << std::left << std::setw(10) << myInventories[orderSKU] -> getItemDesc() << std::left << std::setw(10) << myOrders[i] -> getQuantity() << std::left << std::setw(10) << myOrders[i] -> getPrice() << std::right << std::setw(10) << (myOrders[i]->getDate()).serializeDate() << std::endl;


}
}

bool Controller::checkCustomerLogin(const std::string& username, const std::string& password)
{
	Customer* customer = this -> getCustomer(username);
	if (customer != NULL) {
		if (customer->getPassword() == password) {
			return true;
		}
	}
	return false;
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
	while(!Input::isNumeric(zipStr))
	{
		std::cout << "Invalid zip code. Please try again: ";
		Input::getLine(zipStr);
	}
	std::cout << "Starting balance: ";
	Input::getLine(moneyStr);
	while(!Input::isNumeric(moneyStr))
	{
		std::cout << "Invalid sum. Please try again: ";
		Input::getLine(moneyStr);
	}

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

int Controller::purchase(int sku, int quantity)
{
        Customer* customer = getCustomer(myUsername);
	
	if(this -> inInventory(sku) == -1)
		return -1;
	else
	{
		Inventory* inventory = myInventories.at(this -> inInventory(sku));
		
		if(inventory -> getQuantity() < quantity)
			return -2;
		else if(customer -> getMoney() < (inventory -> getPrice() * quantity))
			return -3;
		else
		{
			customer -> balance(-(inventory -> getPrice() * quantity));	
			return inventory -> purchase(quantity);
		}
	}
}

int Controller::inInventory(int sku)
{
	int it = 0;

	while(myInventories.at(it) -> getSKU() != sku || it < myInventories.size())
		it++;

	if (it == myInventories.size())
		return -1;
	else
		return it;
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

