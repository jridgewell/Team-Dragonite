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
#include "Customer.h"

#include <iostream>
#include <vector>
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
	// cout << c << endl;
}

int main() {
	vector<Customer*> Customers;

	parseFile("data/Customer.yaml", Customers);
	deleteVector(Customers);
	login();
}