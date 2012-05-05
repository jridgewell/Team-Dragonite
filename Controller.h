#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <map>
#include <vector>

#include "Category.h"
#include "Customer.h"
#include "Inventory.h"
#include "Merchant.h"
#include "Order.h"

class Controller
{
private:
	int myUserID;
	std::map<std::string, Category::Category*> myCategories;
	std::map<std::string, Merchant::Merchant*> myMerchants;
	std::vector<Customer::Customer*> myCustomers;
	std::vector<Inventory::Inventory*> myInventories;
	std::vector<Order::Order*> myOrders;

public:
	Controller();
	virtual ~Controller();

	void displayCustomerLogin() const;
	const Customer::Customer& customerLogin(const std::string& username, const std::string& password);
	const Customer::Customer& createCustomer(const std::string& username, const std::string& password);

	void displayMerchantLogin() const;
	const Merchant::Merchant& merchantLogin(const std::string& username, const std::string& password) const;

	void setUserID(int id);
	const int getUserID() const;
};

#endif
