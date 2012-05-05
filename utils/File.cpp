#include "File.h"

void outputToFile(const std::string& file, const std::string& str) {
	std::ofstream of(file.c_str(), std::ios::out | std::ios::trunc);
	of << str;
	of.close();
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
