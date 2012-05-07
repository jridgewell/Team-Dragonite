#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
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
#include "Date.h"

class Controller
{
private:
	bool isCustomer;
	bool isMerchant;
	Merchant* myMerchant;
	Customer* myCustomer;
	std::map<std::string, Category*> myCategories;
	std::map<std::string, Merchant*> myMerchants;
	std::vector<Customer*> myCustomers;
	std::vector<Inventory*> myInventories;
	std::vector<Order*> myOrders;

public:
	Controller();
	virtual ~Controller();

	void displayLogin();
	void customerInterface();

	void displayCustomerLogin();
	void displayInventory();
	bool checkCustomerLogin(const std::string& username, const std::string& password);
	Customer* createCustomer();

	void merchantLogin();
	void displayMerchantInterface();
	bool checkMerchantLogin(const std::string& username, const std::string& password);
	void addInventory();
	void removeInventory();
	void modifyInventory();
	void modifyInventoryItem(const int sku);

	int placePurchase();
	int placeOrder(int sku, int quantity);
	int inInventory(int sku);
	void displayCustomerOrders();

	Date getDate();
	void saveFiles();

	Customer* getCustomer(const std::string& username);
	Merchant* getMerchant(const std::string& username);
};

#endif
