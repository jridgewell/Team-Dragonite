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
using namespace std;

int main() {
	vector<Customer*> Customers;

	std::ifstream fin("data/Customer.yaml");
	YAML::Parser parser(fin);
	fin.close();
	YAML::Node doc;
	parser.GetNextDocument(doc);
	for(unsigned i = 0; i < doc.size(); ++i) {
		Customer *c = new Customer(doc[i]);
		cout << c << endl;
 		// c->parseYaml(doc[i]);
		Customers.push_back(c);
	}

	for (unsigned i = 0; i < Customers.size(); ++i) {
		cout << Customers[i]->getUsername() << endl;
		delete Customers[i];
	}
}