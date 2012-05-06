#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <ios>
#include <iomanip>

#include "utils/File.h"
#include "utils/Input.h"
#include "utils/KeyExtractor.h"
#include "Category.h"
#include "Customer.h"
#include "Inventory.h"
#include "Merchant.h"
#include "Order.h"

class Controller
{
private:
	std::string myUsername;
	bool isCustomer;
	bool isMerchant;
	Customer* myCustomer;
	std::map<std::string, Category::Category*> myCategories;
	std::map<std::string, Merchant::Merchant*> myMerchants;
	std::vector<Customer::Customer*> myCustomers;
	std::vector<Inventory::Inventory*> myInventories;
	std::vector<Order::Order*> myOrders;

public:
	Controller();
	virtual ~Controller();

	void displayLogin();
	void customerInterface();
	
	void displayCustomerLogin();
	void displayInventory();
	bool checkCustomerLogin(const std::string& username, const std::string& password);
	Customer::Customer* createCustomer();

	void displayMerchantLogin();
	Merchant::Merchant* merchantLogin(const std::string& username, const std::string& password);

	int purchase(int sku, int quantity);
	int inInventory(int sku);	
	void displayCustomerOrders();

	Customer::Customer* getCustomer(const std::string& username);
	Merchant::Merchant* getMerchant(const std::string& username);

	void setUsername(const std::string& username);
	const std::string& getUsername() const;
};

#endif
