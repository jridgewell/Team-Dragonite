#ifndef CUSTOMERCONTROLLER_H
#define CUSTOMERCONTROLLER_H
/*
* Customer Controller
*
* Author: Jure Jumalon
* Date: May 5, 2012
*/

#include <iostream>

class CustomerController
{
private:
	int customerID;

	bool isInStock(int sku) const;
	bool canPurchase(int sku, int amount);	
public:
	CustomerController();
	virtual ~CustomerController();

	const Customer& logIn(std::string name, std::string password);
	float purchase(const int sku, const int amount);
	displayOrders() const;
	displaySale() const;

	const Customer::Customer& getCustomer() const;
	const int getCustomerID() const;
	setCustomer(const Customer::Customer& customer);
	setCustomer(int customerID);
};

#endif
