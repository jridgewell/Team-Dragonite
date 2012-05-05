#ifndef FILE_H
#define FILE_H
/*
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <yaml-cpp/yaml.h>
#include "KeyExtractor.h"
#include "../Category.h"
#include "../Customer.h"
#include "../Merchant.h"
#include "../Inventory.h"
#include "../Order.h"

void outputToFile(const std::string& file, const std::string& str) {
	std::ofstream of(file.c_str(), std::ios::out | std::ios::trunc);
	of << str;
	of.close();
}

template <typename key, typename val>
void deleteMap(std::map<key, val*>& m) {
	for (typename std::map<key, val*>::iterator it = m.begin(); it != m.end(); ++it) {
		delete (*it).second;
		m.erase(it);
	}
}

template <typename key, typename val>
void outputMapToFile(const std::string& file, std::map<key, val*>& m) {
	YAML::Emitter out;
	out << YAML::BeginSeq;
	for (typename std::map<key, val*>::iterator it = m.begin(); it != m.end(); ++it) {
		((*it).second)->emitYaml(out);
	}
	out << YAML::EndSeq;
	std::string str = out.c_str();
	outputToFile(file, str);
}

template <typename key, typename val, typename keyExtractor>
void parseFileToMap(const std::string& file, std::map<key, val*>& m) {
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
}

template <typename object>
void deleteVector(std::vector<object*>& vect) {
	for (unsigned i = 0; i < vect.size(); ++i) {
		delete vect[i];
	}
}

template <typename object>
void outputVectorToFile(const std::string& file, std::vector<object*>& vect) {
	YAML::Emitter out;
	out << YAML::BeginSeq;
	for (unsigned i = 0; i < vect.size(); ++i) {
		vect[i]->emitYaml(out);
	}
	out << YAML::EndSeq;
	std::string str = out.c_str();
	outputToFile(file, str);
}

template <typename object>
void parseFileToVector(const std::string& file, std::vector<object*>& vect) {
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

template void deleteMap<std::string, Category>(std::map<std::string, Category*>& m);
template void deleteMap<std::string, Merchant>(std::map<std::string, Merchant*>& m);;
template void deleteVector<Customer>(std::vector<Customer*>& vect);
template void deleteVector<Inventory>(std::vector<Inventory*>& vect);
template void deleteVector<Order>(std::vector<Order*>& vect);
template void outputMapToFile<std::string, Category>(const std::string& file, std::map<std::string, Category*>& m);
template void outputMapToFile<std::string, Merchant>(const std::string& file, std::map<std::string, Merchant*>& m);
template void outputVectorToFile<Customer>(const std::string& file, std::vector<Customer*>& vect);
template void outputVectorToFile<Inventory>(const std::string& file, std::vector<Inventory*>& vect);
template void outputVectorToFile<Order>(const std::string& file, std::vector<Order*>& vect);
template void parseFileToMap<std::string, Category, categoryKeyExtractor>(const std::string& file, std::map<std::string, Category*>& m);
template void parseFileToMap<std::string, Merchant, merchantKeyExtractor>(const std::string& file, std::map<std::string, Merchant*>& m);
template void parseFileToVector<Customer>(const std::string& file, std::vector<Customer*>& vect);
template void parseFileToVector<Inventory>(const std::string& file, std::vector<Inventory*>& vect);
template void parseFileToVector<Order>(const std::string& file, std::vector<Order*>& vect);

#endif
