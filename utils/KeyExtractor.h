#ifndef KEY_EXTRACTOR_H
#define KEY_EXTRACTOR_H

/**
* KeyExtractor
* @date May 5, 2012
* @author Justin Ridgewell
*/
#include <string>
#include "../Category.h"
#include "../Merchant.h"
#include <string>

struct categoryKeyExtractor {
	std::string operator()(const Category* c) {
		return c->getCategoryName();
	}
};

struct merchantKeyExtractor {
	std::string operator()(const Merchant* m) {
		return m->getUsername();
	}
};

#endif
