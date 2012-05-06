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
				this -> merchantLogin();
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
	int skuInt, quantityInt, changeInt;
	bool cont = true;
	std::string input;
	std::string sku, quantity, change;
	while(cont)
	{
		std::cout << "Enter 1 to place an order. Enter 2 to view past orders. Enter 3 to change amount in account. Enter 4 to display inventory. Enter 5 to exit" << std::endl;
		Input::getLine(input);
		c = input[0];
		if(c == '1')
		{
			std::cout << "Enter the SKU for your purchase." << std::endl;
			Input::getLine(sku);
			skuInt = atoi(sku.c_str());

			std::cout << "Enter the quantity for your purchase." << std::endl;
			Input::getLine(quantity);
			while(!Input::isNumeric(quantity))
			{
				std::cout << "Invalid quantity. Please try again: ";
				Input::getLine(quantity);
			}
			quantityInt = atoi(quantity.c_str());
			std::cout << "SKU: " << skuInt << "   Quantity: " << quantityInt << std::endl;
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
	for(int i = 0; i < myInventories.size(); i++) {
		if (myInventories[i]->getQuantity() > -1) {
			if (!isMerchant) {
				std::cout << std::left << std::setw(10) << myInventories[i] -> getSKU() << std::left << std::setw(20) << myInventories[i] -> getItemDesc()<< std::right <<  std::setw(10) << myInventories[i] -> getPrice() << std::right << std::setw(10) << myInventories[i] -> getQuantity() << std::endl;
			} else if (myInventories[i]->getMerchantID() == myMerchant->getMerchantID()) {
				std::cout << std::left << std::setw(10) << myInventories[i] -> getSKU() << std::left << std::setw(20) << myInventories[i] -> getItemDesc()<< std::right <<  std::setw(10) << myInventories[i] -> getPrice() << std::right << std::setw(10) << myInventories[i] -> getQuantity() << std::endl;
			}
		}
	}
	Input::wait();
	if (isMerchant) {
		this->displayMerchantInterface();
	}
}

void Controller::displayCustomerOrders()
{
	std::cout << std::left << std::setw(10) << "Order ID" << std::left << std::setw(10) << "SKU" << std::left << std::setw(20) << "Item Description" << std::right << std::setw(10) << "Quantity" << std::right << std::setw(10) << "Price" << std::right << std::setw(10) << "Date" << std::endl;

 for(int i = 0; i < myOrders.size(); i++)
        {
                const int orderSKU = myOrders[i] -> getSKU();
                Date orderDate = myOrders[i] -> getDate();
                 std::cout << std::left << std::setw(10) << myOrders[i] -> getOrderID() << std::left << std::setw(10) << myOrders[i] -> getSKU() << std::left << std::setw(20) << myInventories[orderSKU] -> getItemDesc() << std::right << std::setw(10) << myOrders[i] -> getQuantity() << std::right << std::setw(10) << myOrders[i] -> getPrice() << std::right << std::setw(15) << (myOrders[i]->getDate()).serializeDate() << std::endl;


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

void Controller::displayMerchantInterface() {
	bool cont = true;
	std::string input;
	char c;
	while (cont) {
		std::cout << "What would you like to do?"<< std::endl;
		std::cout << "1. List current inventory" << std::endl;
		std::cout << "2. Add an inventory item" << std::endl;
		std::cout << "3. Modify current inventory" << std::endl;
		std::cout << "4. Remove an inventory item" << std::endl;
		std::cout << "5. Display past orders" << std::endl;
		std::cout << "6. Exit" << std::endl;
		Input::getLine(input);
		c = input[0];
		switch (c) {
			case '1':
				this->displayInventory();
				cont = false;
				break;
			case '2':
				this->addInventory();
				cont = false;
				break;
			case '3':
				this->modifyInventory();
				cont = false;
				break;
			case '4':
				this->removeInventory();
				cont = false;
				break;
			case '5':
				this->displayInventory();
				cont = false;
				break;
			case '6':
				cont = false;
				break;
			default:
				std::cout << "Invalid input, please enter 1, 2, 3, 4, 5, or 6." << std::endl << std::endl;
				break;
		}
	}
}

void Controller::addInventory() {
	int sku, categoryID, price, quantity, merchantID;
	std::string description, categoryIDStr, priceStr, quantityStr;
	bool cont = true;

	sku = myInventories.size();
	merchantID = myMerchant->getMerchantID();
	std::cout << "Item's Description: ";
	Input::getLine(description);

	std::map<std::string, Category*>::const_iterator it;
	while (cont) {
		std::cout << "Please select a category:" << std::endl;
		for (it = myCategories.begin(); it != myCategories.end(); ++it) {
			std::cout << ((it->second)->getCategoryID() + 1) << ". " << (it->second)->getCategoryName() << std::endl;
		}
		Input::getLine(categoryIDStr);
		if (Input::isNumeric(categoryIDStr)) {
			categoryID = atoi(categoryIDStr.c_str());
			if (categoryID > 0 && categoryID <= myCategories.size()) {
				cont = false;
				break;
			}
		}
		std::cout << "Invalid Input. Please enter an integer between 1 and " << myCategories.size() << std::endl;
	}
	std::cout << "Price (cents): ";
	Input::getLine(priceStr);
	while(!Input::isNumeric(priceStr)) {
		std::cout << "Invalid price. Please try again: ";
		Input::getLine(priceStr);
	}
	std::cout << "Quanity: ";
	Input::getLine(quantityStr);
	while(!Input::isNumeric(quantityStr)) {
		std::cout << "Invalid quantity. Please try again: ";
		Input::getLine(quantityStr);
	}
	// categoryID = atoi(categoryIDStr);
	price = atoi(priceStr.c_str());
	quantity = atoi(quantityStr.c_str());
	Inventory* i = new Inventory(sku, description, categoryID, merchantID, price, quantity);
	myInventories.push_back(i);

	std::cout << "Item has been added." << std::endl;
	Input::wait();

	if (isMerchant) {
		this->displayMerchantInterface();
	}
}

void Controller::removeInventory() {
	bool cont = true;
	int sel;
	std::string selection;

	while (cont) {
		std::cout << "Please select a SKU:" << std::endl;
		for(int i = 0; i < myInventories.size(); ++i) {
			if (myInventories[i]->getMerchantID() == myMerchant->getMerchantID()) {
				if (myInventories[i]->getQuantity() > -1) {
					std::cout << myInventories[i] -> getSKU() << ". " << myInventories[i] -> getItemDesc() << std::endl;
				}
			}
		}
		Input::getLine(selection);
		if (Input::isNumeric(selection)) {
			sel = atoi(selection.c_str());
			if (myInventories[sel]->getMerchantID() == myMerchant->getMerchantID()) {
				cont = false;
				break;
			}
		}
		std::cout << "Invalid SKU, please try again." << std::endl;
	}
	myInventories[sel]->setQuantity(-1);

	std::cout << "Item removed." << std::endl;
	Input::wait();
	if (isMerchant) {
		this->displayMerchantInterface();
	}
}

void Controller::modifyInventory() {
	bool cont = true;
	int sel;
	std::string selection;
	std::vector<Inventory*> old;

	while (cont) {
		std::cout << "Please select a SKU:" << std::endl;
		for(int i = 0; i < myInventories.size(); ++i) {
			if (myInventories[i]->getMerchantID() == myMerchant->getMerchantID()) {
				if (myInventories[i]->getQuantity() > -1) {
					std::cout << myInventories[i] -> getSKU() << ". " << myInventories[i] -> getItemDesc() << std::endl;
				} else {
					old.push_back(myInventories[i]);
				}
			}
		}
		std::cout << "Old Items -------------------" << std::endl;
		for(int i = 0; i < old.size(); ++i) {
			std::cout << old[i] -> getSKU() << ". " << old[i] -> getItemDesc() << std::endl;
		}
		Input::getLine(selection);
		if (Input::isNumeric(selection)) {
			sel = atoi(selection.c_str());
			if (myInventories[sel]->getMerchantID() == myMerchant->getMerchantID()) {
				cont = false;
				break;
			}
		}
		std::cout << "Invalid SKU, please try again." << std::endl;
	}

	this->modifyInventoryItem(sel);
	Input::wait();

	if (isMerchant) {
		this->displayMerchantInterface();
	}
}

void Controller::modifyInventoryItem(const int sku) {
	bool cont = true;
	std::string input;
	std::string newValue;
	char c;

	std::cout << std::left << std::setw(10) << "SKU" << std::left << std::setw(20) << "Item Description" << std::right << std::setw(10) << "Price" << std::right << std::setw(10) << "Quantity" << std::endl;
	std::cout << std::left << std::setw(10) << myInventories[sku] -> getSKU() << std::left << std::setw(20) << myInventories[sku] -> getItemDesc()<< std::right <<  std::setw(10) << myInventories[sku] -> getPrice() << std::right << std::setw(10) << myInventories[sku] -> getQuantity() << std::endl;
	while(cont) {
		std::cout << "What would you like to edit about " << myInventories[sku]->getItemDesc() << "?" << std::endl;
		std::cout << "1. Price"<< std::endl;
		std::cout << "2. Quantity"<< std::endl;
		Input::getLine(input);
		c = input[0];
		switch (c) {
			case '1':
				std::cout << "New Price: " << std::endl;
				Input::getLine(newValue);
				if (Input::isNumeric(newValue)) {
					cont = false;
					myInventories[sku]->setPrice(atoi(newValue.c_str()));
					std::cout << "Price Updated." << std::endl;
				}
				break;
			case '2':
				std::cout << "New Quantity: " << std::endl;
				Input::getLine(newValue);
				if (Input::isNumeric(newValue)) {
					cont = false;
					myInventories[sku]->setQuantity(atoi(newValue.c_str()));
					std::cout << "Quantity Updated." << std::endl;
				}
				break;
			default:
				std::cout << "Invalid input." << std::endl;
				break;
		}
	}
}

int Controller::purchase(int sku, int quantity)
{
	std::cout << "Purchase: ";
        Customer* customer = getCustomer(myUsername);
	
	if(this -> inInventory(sku) == -1)
	{
		std::cout << "Inventory item does not exist" << std::endl;
		return -1;
	}
	else
	{
	/*	Inventory* inventory = myInventories.at(this -> inInventory(sku));
		
		if(inventory -> getQuantity() < quantity)
			return -2;
		else if(customer -> getMoney() < (inventory -> getPrice() * quantity))
			return -3;
		else
		{
			customer -> balance(-(inventory -> getPrice() * quantity));	
			return inventory -> purchase(quantity);
		}*/

		return 0;
	}
}

int Controller::inInventory(int sku)
{
	int it = 0;

	while((myInventories.at(it) -> getSKU() != sku) && it < myInventories.size())
	//while(it < myInventories.size())
	{
		std::cout << (myInventories.at(it) -> getSKU() != sku) << " ";
		it++;
	}

	if (it == myInventories.size())
		return -1;
	else
		return it;
}

void Controller::merchantLogin() {
    std::string username;
    std::string password;
	bool cont = true;
	while (cont) {
		std::cout << "Username: ";
		Input::getLine(username);
		std::cout << "Password: ";
		Input::getLine(password);
		if (this->checkMerchantLogin(username, password)) {
			myMerchant = this->getMerchant(username);
			isMerchant = true;
			break;
		} else {
			std::cout << "Wrong Username/Password" << std::endl << std::endl;
		}
	}
	if (isMerchant) {
		this->displayMerchantInterface();
	}
}

bool Controller::checkMerchantLogin(const std::string& username, const std::string& password) {
	Merchant* m = this->getMerchant(username);
	if (m != NULL) {
		if (password == m->getPassword()) {
			return true;
		}
	}
	return NULL;
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

Merchant* Controller::getMerchant(const std::string& username)
{
	std::map<std::string, Merchant*>::const_iterator itr;
    itr = myMerchants.find(username);
    if (itr != myMerchants.end()) {
		return itr->second;
	}
	return NULL;
}

void Controller::setUsername(const std::string& username)
{
	myUsername = username;
}

const std::string& Controller::getUsername() const
{
	return myUsername;
}
