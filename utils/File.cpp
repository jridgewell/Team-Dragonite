#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <yaml-cpp/yaml.h>

template <typename object>
void parseFile(const std::string& file, std::vector<object*>& vect) {
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
std::map<key, val*> parseFileToMap(const std::string& file, std::map<key, val*>& m) {
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
void deleteVector(std::vector<deleteObject*>& vect) {
	for (unsigned i = 0; i < vect.size(); ++i) {
		delete vect[i];
	}
}

template <typename key, typename val>
void deleteMap(std::map<key, val*>& m) {
	for (typename std::map<key, val*>::iterator it = m.begin(); it != m.end(); ++it) {
		delete (*it).second;
		m.erase(it);
	}
}

void outputToFile(const std::string& file, const std::string& str) {
	std::ofstream of(file.c_str(), std::ios::out | std::ios::trunc);
	of << str;
	of.close();
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