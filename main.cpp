/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  The controller class
 *
 *        Version:  1.0
 *        Created:  04/25/2012 16:11:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Justin Ridgewell
 *   Organization:  Team Dragonite
 *
 * =====================================================================================
 */

#include "Category.h"
#include "Customer.h"
#include "Inventory.h"
#include "Merchant.h"
#include "Order.h"
#include "utils/File.cpp" // I know I shouln't. But it won't work like I want.
#include "utils/KeyExtractor.h"

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

void merchantLogin() {
	cout << endl;
}

void customerLogin() {
	cout << endl;
}

void login() {
	string input;
	bool cont = true;
	cout << "Are you a Customer or a Merchant? [CM]" << endl;
	cin >> input;
	char c = input[0];
	while (cont) {
		switch (c) {
			case 'c':
			case 'C':
				cont = false;
				customerLogin();
				break;
			case 'm':
			case 'M':
				cont = false;
				merchantLogin();
				break;
			default:
				cout << "Please type either C or M." << endl;
				cin >> input;
				c = input[0];
				break;
		}
	}
}

int main() {
	map<string, Category*> categories;
	map<string, Merchant*> merchants;
	vector<Customer*> customers;
	vector<Inventory*> invetories;
	vector<Order*> orders;

	parseFileToMap<string, Category, categoryKeyExtractor>("data/Category.yaml", categories);
	parseFileToMap<string, Merchant, merchantKeyExtractor>("data/Merchant.yaml", merchants);
	parseFile("data/Customer.yaml", customers);
	parseFile("data/Inventory.yaml", invetories);
	parseFile("data/Order.yaml", orders);

	for (map<string, Category*>::const_iterator it = categories.begin(); it != categories.end(); ++it) {
		cout << (*it).first << " => " << ((*it).second)->getCategoryID() << endl;
	}
	for (map<string, Merchant*>::const_iterator it = merchants.begin(); it != merchants.end(); ++it) {
		cout << (*it).first << " => " << ((*it).second)->getPassword() << endl;
	}
	
	login();

	categories["Testing"] = new Category();
	customers.push_back(new Customer());
	// outputMapToFile("data/Category.yaml", categories);
	// outputVectorToFile("data/Customer.yaml", customers);

	deleteMap(categories);
	deleteMap(merchants);
	deleteVector(customers);
	deleteVector(invetories);
	deleteVector(orders);
}
