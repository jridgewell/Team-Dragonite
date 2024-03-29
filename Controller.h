#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <map>
#include <vector>
#include <cstdlib>
#include <iomanip>

#include "utils/File.h"
#include "utils/Input.h"
#include "utils/MapHelpers.h"
#include "Category.h"
#include "Customer.h"
#include "Inventory.h"
#include "Merchant.h"
#include "Order.h"
#include "Date.h"


/**
* Outlines the Controller class and the features contained therein
* The controller class ties all of the other classes together, forming the backbone of the program
*/

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
	void saveFiles();

	/* Login Methods */
	void displayLogin();
	void customerLogin();
	void merchantLogin();
	bool checkCustomerLogin(const std::string& username, const std::string& password);
	bool checkMerchantLogin(const std::string& username, const std::string& password);

	/* Interface */
	void customerInterface();
	void merchantInterface();

	/* Customer Actions */
	void createCustomer();
	void displayInventory();
	void makePurchase();
	void displayOrders();
	void changeCustomerBalance();
	
	/* Merchant Actions */
	void addInventory();
	void removeInventory();
	void modifyInventory();
	void modifyInventoryItem(const int sku);
	void modifyInventoryPrice(const int sku);
	void modifyInventoryQuantity(const int sku);
	Date getOrderFilterDate();
	int getOrderFilterID();
	bool isMyInventory(const int sku);

	/* Helper Functions */
	void placeOrder(int sku, int quantity);
	Date getLastDate();
	Customer* getCustomer(const std::string& username);
	Merchant* getMerchant(const std::string& username);
};

#endif
