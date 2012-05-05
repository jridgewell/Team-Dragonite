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
map<key, obj*> parseFileToMap(const string& file, map<key, obj*>& m) {
	std::ifstream fin(file.c_str());
	YAML::Parser parser(fin);
	fin.close();
	YAML::Node doc;
	parser.GetNextDocument(doc);
	keyExtractor keyExtract;
	for(unsigned i = 0; i < doc.size(); ++i) {
		obj *o = new obj(doc[i]);
		m[keyExtract(o)] = o;
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

template <typename key, typename deleteObject>
void deleteMap(map<key, deleteObject*>& obj) {
	for (typename map<key, deleteObject*>::iterator it = obj.begin(); it != obj.end(); ++it) {
		delete (*it).second;
		obj.erase(it);
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

	deleteMap(categories);
	deleteMap(merchants);
	deleteVector(customers);
	deleteVector(invetories);
	deleteVector(orders);
}