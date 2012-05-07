#include "Controller.h"

Controller::Controller()
{
	isCustomer = false;
	isMerchant = false;
	File::parseFileToMap<std::string, Category, categoryKeyExtractor>("data/Category.yaml", myCategories);
	File::parseFileToMap<std::string, Merchant, merchantKeyExtractor>("data/Merchant.yaml", myMerchants);
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

void Controller::saveFiles()
{
	File::outputMapToFile("data/Category.yaml", myCategories);
	File::outputMapToFile("data/Merchant.yaml", myMerchants);
	File::outputVectorToFile("data/Customer.yaml", myCustomers);
	File::outputVectorToFile("data/Inventory.yaml", myInventories);
	File::outputVectorToFile("data/Order.yaml", myOrders);
}

#pragma mark -----------------------------------------------------------------
#pragma mark Login Methods

void Controller::displayLogin()
{
	std::string input;
	bool cont = true;
	char c;
	std::cout << "Are you a [C]ustomer or a [M]erchant? ";
	while(cont)
	{
		Input::getLine(input);
		c = input[0];
		switch(c)
		{
			case 'c':
			case 'C':
				cont = false;
				this -> customerLogin();
				break;
			case 'm':
			case 'M':
				cont = false;
				this -> merchantLogin();
				break;
			default:
				std::cout << "Please type either [C] or [M]." << std::endl;
		}
	}
}

void Controller::customerLogin()
{
	std::string input;
	std::string username, password;
	bool cont = true;
	char c;
	while(cont)
	{
		std::cout << "Are you a [N]ew or [R]eturning User? ";
		Input::getLine(input);
		c = input[0];
		switch(c)
		{
			case'r':
			case'R':
				std::cout << "Username: ";
				Input::getLine(username);
				std::cout << "Password: ";
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
				std::cout << "Please type either [N] or [R]." << std::endl;
		}
	}
	if (isCustomer) {
		this->customerInterface();
	}
}

void Controller::merchantLogin() {
	std::string username;
	std::string password;
	while (true) {
		std::cout << "Username: ";
		Input::getLine(username);
		std::cout << "Password: ";
		Input::getLine(password);
		if (this->checkMerchantLogin(username, password)) {
			myMerchant = this->getMerchant(username);
			isMerchant = true;
			break;
		}
		std::cout << "Invalid username or password" << std::endl;
	}
	if (isMerchant) {
		this->merchantInterface();
	}
}

bool Controller::checkCustomerLogin(const std::string& username, const std::string& password)
{
	Customer* customer = this -> getCustomer(username);
	if (customer != NULL) {
		if (password == customer->getPassword()) {
			return true;
		}
	}
	return false;
}

bool Controller::checkMerchantLogin(const std::string& username, const std::string& password) {
	Merchant* m = this->getMerchant(username);
	if (m != NULL) {
		if (password == m->getPassword()) {
			return true;
		}
	}
	return false;
}

#pragma mark -----------------------------------------------------------------
#pragma mark Interface

void Controller::customerInterface()
{
	char c;
	bool cont = true;
	std::string input;
	std::string sku, quantity, change;
	while(cont)
	{
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "1. Place an order." << std::endl;
		std::cout << "2. View order history." << std::endl;
		std::cout << "3. Change balance." << std::endl;
		std::cout << "4. Display inventory." << std::endl;
		std::cout << "5. Exit." << std::endl;
		Input::getLine(input);
		c = input[0];
		switch (c) {
			case '1':
				cont = false;
				this->makePurchase();
				break;
			case '2':
				cont = false;
				this->displayOrders();
				break;
			case '3':
				cont = false;
				this->changeCustomerBalance();
				break;
			case '4':
				cont = false;
				this->displayInventory();
				break;
			case '5':
				cont = false;
				break;
			default:
				std::cout << "Invalid input. Please enter 1, 2, 3, 4, or 5." << std:: endl;
		}
	}
}

void Controller::merchantInterface() {
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
				this->displayOrders();
				cont = false;
				break;
			case '6':
				cont = false;
				break;
			default:
				std::cout << "Invalid input, please enter 1, 2, 3, 4, 5, or 6." << std::endl;
		}
	}
}

#pragma mark -----------------------------------------------------------------
#pragma mark Customer Actions

void Controller::createCustomer()
{
	int id, zip, money;
	std::string username, password, fullName, address, city, state;

	id = myCustomers.size() + 1;

	std::cout << "Username: ";
	Input::getLine(username);
	while (username == "") {
		std::cout << "Cannot have blank username. Please enter another username." << std::endl;
	}
	while(this -> getCustomer(username) != NULL)
	{
		std::cout << "Username already in use. Please enter another username." << std::endl;
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
	while (!Input::getInteger(zip)) {
		std::cout << "Invalid zip code. Please try again." << std::endl;
	}
	std::cout << "Starting balance: ";
	while (!Input::getInteger(money)) {
		std::cout << "Invalid sum. Please try again. " << std::endl;
	}

	Customer* customer = new Customer(id, username, password, fullName, address, city, state, zip, money);
	myCustomers.push_back(customer);
	std::cout << "New customer created." << std::endl;
	Input::wait("Press enter to go to login screen.");
}

void Controller::changeCustomerBalance() {
	int change;
	std::cout << "Current balance: " << myCustomer -> getMoney() << std::endl;
	std::cout << "Change balance by: ";
	while (!Input::getInteger(change)) {
		std::cout << "Invalid amount. Please try again." << std::endl;
	}
	myCustomer -> updateBalance(change);
	std::cout << "Balance updated." << std::endl;
	
	Input::wait();
	if (isCustomer) {
		this->customerInterface();
	}
}

void Controller::makePurchase()
{
	int sku, quantity, cost;

	while (true) {
		std::cout << "Please select a SKU:" << std::endl;
		for(unsigned i = 0; i < myInventories.size(); ++i) {
			std::cout << std::left << std::setw(5) << myInventories[i] -> getSKU()
				  << std::left << std::setw(20) << myInventories[i] -> getItemDesc()
			<< std::endl;
		}
		if (Input::getIntegerInRange(sku, myInventories.size(), 1)) {
			break;
		}
		std::cout << "Invalid SKU. Please try again." << std::endl;
	}

	std::cout << "Quantity: ";
	while (true) {
		if (Input::getPositiveInteger(quantity)) {
			if (quantity < 1) {
				std::cout << "Invalid quantity. You have to buy at least 1." << std::endl;
			} else if (quantity > myInventories[sku]->getQuantity()) {
				std::cout << "Invalid quantity. We only have " << myInventories[sku]->getQuantity() << "." << std::endl;
			} else {
				break;
			}
		} else {
			std::cout << "Invalid quantity. Please try again." << std::endl;
		}
	}

	cost = quantity * (myInventories[sku]->getPrice());
	if (cost > myCustomer->getMoney()) {
		std::cout << "I'm sorry, you don't have enough money." << std::endl;
		std::cout << "You need " << cost << " and you only have " << myCustomer->getMoney() << std::endl;
	} else {
		myCustomer->updateBalance(-1 * cost);
		myInventories[sku]->purchase(quantity);
		std::cout << "Purchase completed." << std::endl;

		this->placeOrder(sku, quantity);
	}
	
	Input::wait();
	if (isCustomer) {
		this->customerInterface();
	}
}

#pragma mark -----------------------------------------------------------------
#pragma mark Merchant Actions

void Controller::addInventory() {
	int sku, categoryID, price, quantity, merchantID;
	std::string description;

	sku = myInventories.size() + 1;
	merchantID = myMerchant->getMerchantID();
	std::cout << "Item's description: ";
	Input::getLine(description);

	std::map<std::string, Category*>::const_iterator it;
	while (true) {
		std::cout << "Please select a category:" << std::endl;
		for (it = myCategories.begin(); it != myCategories.end(); ++it) {
			std::cout << std::left << std::setw(5) << (it->second)->getCategoryID()
				  << std::left << std::setw(15) << (it->second)->getCategoryName()
			<< std::endl;
		}
		if (Input::getIntegerInRange(categoryID, myCategories.size())) {
			break;
		}
		std::cout << "Invalid input. Please enter an integer between 1 and " << myCategories.size() << std::endl;
	}
	std::cout << "Price (cents): ";
	while (!Input::getPositiveInteger(price)) {
		std::cout << "Invalid price. Please try again: ";
	}
	std::cout << "Quanity: ";
	while (!Input::getPositiveInteger(quantity)) {
		std::cout << "Invalid quantity. Please try again: ";
	}
	Inventory* i = new Inventory(sku, description, categoryID, merchantID, price, quantity);
	myInventories.push_back(i);

	std::cout << "Item has been added." << std::endl;

	Input::wait();
	if (isMerchant) {
		this->merchantInterface();
	}
}

void Controller::removeInventory() {
	int sel;

	while (true) {
		std::cout << "Please select a SKU:" << std::endl;
		for(unsigned i = 0; i < myInventories.size(); ++i) {
			if (myInventories[i]->getMerchantID() == myMerchant->getMerchantID()) {
				if (myInventories[i]->getQuantity() > -1) {
					std::cout << std::left << std::setw(5) << myInventories[i] -> getSKU()
						  << std::left << std::setw(20) << myInventories[i] -> getItemDesc()
					<< std::endl;
				}
			}
		}
		if (Input::getPositiveInteger(sel)) {
			if (myInventories[sel]->getMerchantID() == myMerchant->getMerchantID()) {
				break;
			}
		}
		std::cout << "Invalid SKU, please try again." << std::endl;
	}

	myInventories[sel]->setQuantity(-1);
	std::cout << "Item removed." << std::endl;

	Input::wait();
	if (isMerchant) {
		this->merchantInterface();
	}
}

void Controller::modifyInventory() {
	int sel;
	std::vector<Inventory*> old;

	while (true) {
		std::cout << "Please select a SKU:" << std::endl;
		for(unsigned i = 0; i < myInventories.size(); ++i) {
			if (myInventories[i]->getMerchantID() == myMerchant->getMerchantID()) {
				if (myInventories[i]->getQuantity() > -1) {
					std::cout << std::left << std::setw(5) << myInventories[i] -> getSKU()
						  << std::left << std::setw(20) << myInventories[i] -> getItemDesc()
					<< std::endl;
				} else {
					old.push_back(myInventories[i]);
				}
			}
		}
		std::cout << "Old Items -------------------" << std::endl;
		for(unsigned i = 0; i < old.size(); ++i) {
			std::cout << std::left << std::setw(5) << myInventories[i] -> getSKU()
				  << std::left << std::setw(20) << myInventories[i] -> getItemDesc()
			<< std::endl;
		}
		if (Input::getPositiveInteger(sel)) {
			if (myInventories[sel]->getMerchantID() == myMerchant->getMerchantID()) {
				break;
			}
		}
		std::cout << "Invalid SKU, please try again." << std::endl;
	}

	this->modifyInventoryItem(sel);

	Input::wait();
	if (isMerchant) {
		this->merchantInterface();
	}
}

void Controller::modifyInventoryItem(const int sku) {
	bool cont = true;
	std::string input;
	std::string newValue;
	char c;

	std::cout << std::left << std::setw(10) << "SKU" 
		<< std::left << std::setw(20) << "Item Description"
		<< std::right << std::setw(10) << "Price"
		<< std::right << std::setw(10) << "Quantity"
	<< std::endl;
	std::cout << std::left << std::setw(10) << myInventories[sku] -> getSKU()
		<< std::left << std::setw(20) << myInventories[sku] -> getItemDesc()
		<< std::right <<  std::setw(10) << myInventories[sku] -> getPrice()
		<< std::right << std::setw(10) << ((myInventories[sku] -> getQuantity() > -1) ? myInventories[sku] -> getQuantity() : 0)
	<< std::endl;
	while(cont) {
		std::cout << "What would you like to edit about " << myInventories[sku]->getItemDesc() << "?" << std::endl;
		std::cout << "1. Price"<< std::endl;
		std::cout << "2. Quantity"<< std::endl;
		Input::getLine(input);
		c = input[0];
		switch (c) {
			case '1':
				cont = false;
				this->modifyInventoryPrice(sku);
				break;
			case '2':
				cont = false;
				this->modifyInventoryQuantity(sku);
				break;
			default:
				std::cout << "Invalid input. Please select either 1 or 2." << std::endl;
		}
	}
}

void Controller::modifyInventoryPrice(const int sku) {
	int price;
	std::cout << "New price: " << std::endl;
	while (!Input::getPositiveInteger(price)) {
		std::cout << "Invalid input. Please enter an integer >= 0." << std::endl;
	}
	myInventories[sku]->setPrice(price);
	std::cout << "Price updated." << std::endl;	
}

void Controller::modifyInventoryQuantity(const int sku) {
	int quantity;
	std::cout << "New quantity: " << std::endl;
	while (!Input::getPositiveInteger(quantity)) {
		std::cout << "Invalid quantity. Please enter an integer >= 0." << std::endl;
	}
	myInventories[sku]->setQuantity(quantity);
	std::cout << "Quantity updated." << std::endl;
}

Date Controller::getOrderFilterDate() {
	Date d;
	int year, month, day;
	std::cout << "Year: " << std::endl;
	while (true) {
		if (Input::getIntegerInRange(year, 9999)) {
			break;
		}
		std::cout << "Invalid year. Please enter an integer between 0 and 9999." << std::endl;
	}
	std::cout << "Month: " << std::endl;
	while (true) {
		if (Input::getIntegerInRange(month, 1, 12)) {
			break;
		}
		std::cout << "Invalid month. Please enter an integer between 1 and 12." << std::endl;
	}
	d.setYear(year);
	d.setMonth(month);
	std::cout << "Day: " << std::endl;
	while (true) {
		if (Input::getIntegerInRange(day, 1, d.getDaysInMonth())) {
			break;
		}
		std::cout << "Invalid month. Please enter an integer between 1 and " << d.getDaysInMonth() << "." << std::endl;
	}
	d.setDay(day);
	return d;
}

int Controller::getOrderFilterID() {
	int id;
	std::cout << "Customer ID: " << std::endl;
	while (true) {
		if (Input::getIntegerInRange(id, 0, myCustomers.size())) {
			break;
		}
	}
	return id;
}

bool Controller::isMyInventory(const int sku) {
	return (myInventories[sku]->getMerchantID() == myMerchant->getMerchantID());
};


#pragma mark -----------------------------------------------------------------
#pragma mark Customer/Merchant Actions

void Controller::displayInventory()
{
	std::map<std::string, Category*>::iterator it;

	std::cout << std::left << std::setw(10) << "SKU"
		<< std::left << std::setw(20) << "Item Description"
		<< std::right << std::setw(10) << "Price"
		<< std::right << std::setw(10) << "Quantity"
	<< std::endl;
	for(unsigned i = 0; i < myInventories.size(); ++i) {
		if (myInventories[i]->getQuantity() > -1) {
			if (isCustomer || (isMerchant && this->isMyInventory(i))) {
				std::cout << std::left << std::setw(10) << myInventories[i] -> getSKU()
					  << std::left << std::setw(20) << myInventories[i] -> getItemDesc()
					  << std::right <<  std::setw(10) << myInventories[i] -> getPrice()
					  << std::right << std::setw(10) << myInventories[i] -> getQuantity()
				<< std::endl;
			}
		}
	}
	
	Input::wait();
	if (isMerchant) {
		this->merchantInterface();
	} else if (isCustomer) {
		this->customerInterface();
	}
}

void Controller::displayOrders()
{
	Date filterDate;
	filterDate.setNull();
	int filterID = -1;
	if (isMerchant) {
		bool cont = true;
		std::string input;
		char c;
		std::cout << "What orders would you like to dispaly?" << std::endl;
		std::cout << "1. All orders." << std::endl;
		std::cout << "2. Orders on date..." << std::endl;
		std::cout << "3. Orders made by customer ID..." << std::endl;
		Input::getLine(input);
		c = input[0];
		switch (c) {
			case '1':
				cont = false;
				break;
			case '2':
				cont = false;
				filterDate = this->getOrderFilterDate();
				break;
			case '3':
				cont = false;
				filterID = this->getOrderFilterID();
				break;
			default:
				std::cout << "Invalid input. Please enter 1, 2, or 3." << std::endl;
		}
	}
	std::cout << std::left << std::setw(10) << "Order ID"
		<< std::left << std::setw(10) << "SKU"
		<< std::left << std::setw(20) << "Item Description"
		<< std::right << std::setw(10) << "Quantity"
		<< std::right << std::setw(10) << "Price"
		<< std::right << std::setw(10) << "Date"
	<< std::endl;
	for(unsigned i = 0; i < myOrders.size(); ++i) {
		if (
			(isMerchant && this->isMyInventory(myOrders[i]->getSKU()) &&
				(filterDate.isNull() || filterDate == myOrders[i]->getDate()) &&
				(filterID == -1 || filterID == myOrders[i]->getCustomerID())
			) || (isCustomer && myOrders[i]->getCustomerID() == myCustomer->getCustomerID())
		) {
			int orderSKU = myOrders[i] -> getSKU();
			std::cout << std::left << std::setw(10) << myOrders[i] -> getOrderID()
				<< std::left << std::setw(10) << myOrders[i] -> getSKU()
				<< std::left << std::setw(20) << myInventories[orderSKU - 1] -> getItemDesc()
				<< std::right << std::setw(10) << myOrders[i] -> getQuantity()
				<< std::right << std::setw(10) << myOrders[i] -> getPrice()
				<< std::right << std::setw(15) << (myOrders[i]->getDate()).serializeDate()
			<< std::endl;
		}
	}

	Input::wait();
	if (isMerchant) {
		this->merchantInterface();
	} else if (isCustomer) {
		this->customerInterface();
	}
}

#pragma mark -----------------------------------------------------------------
#pragma mark Helper Functions

void Controller::placeOrder(int sku, int quantity)
{
	int orderID, customerID, price;
	Date date;

	orderID = myOrders.size() + 1;
	customerID = myCustomer->getCustomerID();
	price = myInventories[sku]->getPrice();
	date = this->getDate();

	Order* order = new Order(orderID, customerID, sku, quantity, price, date);
	myOrders.push_back(order);
}

Date Controller::getDate()
{
	Date d = (myOrders.back())->getDate();
	d.setDay(d.getDay() + 1);
	return d;
}

Customer* Controller::getCustomer(const std::string& username)
{
	for(unsigned i = 0; i < myCustomers.size(); ++i)
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
