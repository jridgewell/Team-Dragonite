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

////////////////////////////////////////////////////////////////////////////////////////
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

template <typename object>
void parseFile(const string& file, vector<object*>& vect) {
	std::ifstream fin(file.c_str());
	YAML::Parser parser(fin);
	fin.close();
	YAML::Node doc;
	parser.GetNextDocument(doc);
	for(unsigned i = 0; i < doc.size(); ++i) {
		object *o = new object(doc[i]);
		vect.push_back(o);
	}
}

template <typename key, typename val, typename keyExtractor>
map<key, val*> parseFileToMap(const string& file, map<key, val*>& m) {
	std::ifstream fin(file.c_str());
	YAML::Parser parser(fin);
	fin.close();
	YAML::Node doc;
	parser.GetNextDocument(doc);
	keyExtractor keyExtract;
	for(unsigned i = 0; i < doc.size(); ++i) {
		val *o = new val(doc[i]);
		m[keyExtract(o)] = o;
	}
	return m;
}

template <typename deleteObject>
void deleteVector(vector<deleteObject*>& vect) {
	for (unsigned i = 0; i < vect.size(); ++i) {
		delete vect[i];
	}
}

template <typename key, typename val>
void deleteMap(map<key, val*>& m) {
	for (typename map<key, val*>::iterator it = m.begin(); it != m.end(); ++it) {
		delete (*it).second;
		m.erase(it);
	}
}

void outputToFile(const string& file, const string& str) {
	ofstream of(file.c_str(), ios::out | ios::trunc);
	of << str;
	of.close();
}

template <typename object>
void outputVectorToFile(const string& file, vector<object*>& vect) {
	YAML::Emitter out;
	out << YAML::BeginSeq;
	for (unsigned i = 0; i < vect.size(); ++i) {
		vect[i]->emitYaml(out);
	}
	out << YAML::EndSeq;
	string str = out.c_str();
	outputToFile(file, str);
}

template <typename key, typename val>
void outputMapToFile(const string& file, map<key, val*>& m) {
	YAML::Emitter out;
	out << YAML::BeginSeq;
	for (typename map<key, val*>::iterator it = m.begin(); it != m.end(); ++it) {
		((*it).second)->emitYaml(out);
	}
	out << YAML::EndSeq;
	string str = out.c_str();
	outputToFile(file, str);
}



////////////////////////////////////////////////////////////////////////////////////////

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
		//cin.get(c);
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
			cin.get(c);
			cout << "Please type either C or M." << endl;
			cin.get(c);
			
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
	outputMapToFile("data/Category.yaml", categories);
	outputVectorToFile("data/Customer.yaml", customers);

	deleteMap(categories);
	deleteMap(merchants);
	deleteVector(customers);
	deleteVector(invetories);
	deleteVector(orders);
}
