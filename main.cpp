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

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <cstring>
using namespace std;

template <typename parseObject>
void parseFile(const string& file, vector<parseObject*>& obj) {
	std::ifstream fin(file.c_str());
	YAML::Parser parser(fin);
	fin.close();
	YAML::Node doc;
	parser.GetNextDocument(doc);
	for(unsigned i = 0; i < doc.size(); ++i) {
		parseObject *o = new parseObject(doc[i]);
		obj.push_back(o);
	}
}

template <typename key, typename obj, typename keyExtractor>
map<key, obj> convertToMap(const vector<obj>& v) {
	map<key, obj> m;
	typename vector<obj>::const_iterator it;
	keyExtractor ke;
	for (it = v.begin(); it < v.end(); ++it) {
		m[ke(*it)] = *it;
	}
	return m;
}

struct categoryKeyExtractor {
	string operator()(const Category* c) {
		return c->getCategoryName();
	}
};

struct merchantKeyExtractor {
	string operator()(const Merchant* m) {
		return m->getUsername();
	}
};

template <typename deleteObject>
void deleteVector(vector<deleteObject*>& obj) {
	for (unsigned i = 0; i < obj.size(); ++i) {
		delete obj[i];
	}
}

void merchantLogin() {
	cout << endl;
}

void customerLogin() {
	cout << endl;
}

void login() {
	char c;
	bool cont = true;
	cout << "Are you a Customer or a Merchant? [CM]" << endl;
	cin.get(c);
	while (cont) {
		cin.get(c);
		switch (c) {
			case 'c':
				cont = false;
				customerLogin();
				break;
			case 'C':
				cont = false;
				customerLogin();
				break;
			case 'm':
				cont = false;
				merchantLogin();
				break;
			case 'M':
				cont = false;
				merchantLogin();
				break;
			default:
				cout << "Please type either C or M." << endl;
				break;
		}
	}
}

int main() {
	vector<Category*> categories;
	vector<Customer*> customers;
	vector<Inventory*> invetories;
	vector<Merchant*> merchants;
	vector<Order*> orders;
	parseFile("data/Category.yaml", categories);
	parseFile("data/Customer.yaml", customers);
	parseFile("data/Inventory.yaml", invetories);
	parseFile("data/Merchant.yaml", merchants);
	parseFile("data/Order.yaml", orders);

	map<string, Category*> categoriesMap = convertToMap<string, Category*, categoryKeyExtractor>(categories);
	for (map<string, Category*>::const_iterator it = categoriesMap.begin(); it != categoriesMap.end(); ++it) {
		cout << (*it).first << " => " << ((*it).second)->getCategoryID() << endl;
	}
	map<string, Merchant*> merchantsMap = convertToMap<string, Merchant*, merchantKeyExtractor>(merchants);
	for (map<string, Merchant*>::const_iterator it = merchantsMap.begin(); it != merchantsMap.end(); ++it) {
		cout << (*it).first << " => " << ((*it).second)->getPassword() << endl;
	}

	login();

	deleteVector(categories);
	deleteVector(customers);
	deleteVector(invetories);
	deleteVector(merchants);
	deleteVector(orders);
}