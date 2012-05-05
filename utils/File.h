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

struct File {
	void outputToFile(const std::string& file, const std::string& str);

	template <typename key, typename val>
	static void deleteMap(std::map<key, val*>& m);
	template <typename key, typename val>
	static void outputMapToFile(const std::string& file, std::map<key, val*>& m);
	template <typename key, typename val, typename keyExtractor>
	static void parseFileToMap(const std::string& file, std::map<key, val*>& m);
	template <typename object>
	static void deleteVector(std::vector<object*>& vect);
	template <typename object>
	static void outputVectorToFile(const std::string& file, std::vector<object*>& vect);
	template <typename object>
	static void parseFileToVector(const std::string& file, std::vector<object*>& vect);
};

#endif
