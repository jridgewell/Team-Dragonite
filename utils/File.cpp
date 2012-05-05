#include "File.h"

void File::outputToFile(const std::string& file, const std::string& str) {
	std::ofstream of(file.c_str(), std::ios::out | std::ios::trunc);
	of << str;
	of.close();
}

template <typename key, typename val>
void File::deleteMap(std::map<key, val*>& m) {
	for (typename std::map<key, val*>::iterator it = m.begin(); it != m.end(); ++it) {
		delete it->second;
		m.erase(it);
	}
}

template <typename key, typename val>
void File::outputMapToFile(const std::string& file, std::map<key, val*>& m) {
	YAML::Emitter out;
	out << YAML::BeginSeq;
	for (typename std::map<key, val*>::iterator it = m.begin(); it != m.end(); ++it) {
		(it->second)->emitYaml(out);
	}
	out << YAML::EndSeq;
	std::string str = out.c_str();
	File::outputToFile(file, str);
}

template <typename key, typename val, typename keyExtractor>
void File::parseFileToMap(const std::string& file, std::map<key, val*>& m) {
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
void File::deleteVector(std::vector<object*>& vect) {
	for (unsigned i = 0; i < vect.size(); ++i) {
		delete vect[i];
	}
}

template <typename object>
void File::outputVectorToFile(const std::string& file, std::vector<object*>& vect) {
	YAML::Emitter out;
	out << YAML::BeginSeq;
	for (unsigned i = 0; i < vect.size(); ++i) {
		vect[i]->emitYaml(out);
	}
	out << YAML::EndSeq;
	std::string str = out.c_str();
	File::outputToFile(file, str);
}

template <typename object>
void File::parseFileToVector(const std::string& file, std::vector<object*>& vect) {
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


template void File::deleteMap<std::string, Category>(std::map<std::string, Category*>& m);
template void File::deleteMap<std::string, Merchant>(std::map<std::string, Merchant*>& m);
template void File::deleteVector<Customer>(std::vector<Customer*>& vect);
template void File::deleteVector<Inventory>(std::vector<Inventory*>& vect);
template void File::deleteVector<Order>(std::vector<Order*>& vect);
template void File::outputMapToFile<std::string, Category>(const std::string& file, std::map<std::string, Category*>& m);
template void File::outputMapToFile<std::string, Merchant>(const std::string& file, std::map<std::string, Merchant*>& m);
template void File::outputVectorToFile<Customer>(const std::string& file, std::vector<Customer*>& vect);
template void File::outputVectorToFile<Inventory>(const std::string& file, std::vector<Inventory*>& vect);
template void File::outputVectorToFile<Order>(const std::string& file, std::vector<Order*>& vect);
template void File::parseFileToMap<std::string, Category, categoryKeyExtractor>(const std::string& file, std::map<std::string, Category*>& m);
template void File::parseFileToMap<std::string, Merchant, merchantKeyExtractor>(const std::string& file, std::map<std::string, Merchant*>& m);
template void File::parseFileToVector<Customer>(const std::string& file, std::vector<Customer*>& vect);
template void File::parseFileToVector<Inventory>(const std::string& file, std::vector<Inventory*>& vect);
template void File::parseFileToVector<Order>(const std::string& file, std::vector<Order*>& vect);
