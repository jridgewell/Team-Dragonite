#ifndef CATEGORY_H
#define CATEGORY_H

/**
 * Category
 *
 * @date May 2, 2012
 * @author Jure Jumalon
 */

#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>

class Category
{
	private:
		int myCategoryID;
		std::string myCategoryName;

	public:
		Category();
		Category(const int categoryID, const std::string& categoryName);
		Category(const Category& category);
		Category(const YAML::Node& node);
		virtual ~Category() {}
		void parseYaml(const YAML::Node& node);

		int getCategoryID() const;
		const std::string& getCategoryName() const;

		void setCategoryID(const int categoryID);
		void setCategoryName(const std::string& categoryName);
};

#endif
