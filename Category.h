#ifndef CATEGORY_H
#define CATEGORY_H

/**
 * Category
 *
 * @date May 2, 2012
 * @author Jure Jumalon
 * 
 * Comments: Andrew Wagenheim
 */

#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>


/*
* Outlines the Category class and the features contained therein.
* Categories consist of a category ID and a category name
* Creates Categories through one of the following:
* 1) A default constructor
* 2) A constructor with passed in values
* 3) An existing category object, copying its values
* 4) Category data retrieved from a node on the YAML
* In addition, the class is able to set/get the category's values using accessor methods
*/

class Category
{
	private:
		int myCategoryID;
		std::string myCategoryName;

	public:
		Category();
		Category(const int categoryID, const std::string& categoryName)
			: myCategoryID(categoryID), myCategoryName(categoryName) {}		
		Category(const Category& category);
		Category(const YAML::Node& node);
		virtual ~Category() {}
		void parseYaml(const YAML::Node& node);
		YAML::Emitter& emitYaml(YAML::Emitter& out) const;

		int getCategoryID() const;
		const std::string& getCategoryName() const;

		void setCategoryID(const int categoryID);
		void setCategoryName(const std::string& categoryName);
};

#endif
