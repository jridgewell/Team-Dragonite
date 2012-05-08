/**
 * Category
 *
 * @date May 2, 2012
 * @author Jure Jumalon
 */

#include "Category.h"

Category::Category()
/**
 * Purpose: Category constructor
 * Post: Category object created
 * 			Category ID = 0
 * 			Category Name = "Category Name"
 */
{
	this -> setCategoryID(0);
	this -> setCategoryName("Category Name");
}

Category::Category(const Category& category)
/**
 * Purpose: Copy Category constructor
 * Post: Category object created as a copy of category
 */
{
	this -> setCategoryID(category.myCategoryID);
	this -> setCategoryName(category.myCategoryName);
}

/**
* Pushes data from a category onto a node for storage
* Pre: A node from the YAML is passed in
* Post: The data from the category is stored on the input node
*/
Category::Category(const YAML::Node& node)
{
	this -> parseYaml(node);
}

/**
* Creates a new category from data stored on the YAML
* Pre: A node from the YAML is passed in
* Post: A category is created from the input node
*/
void Category::parseYaml(const YAML::Node& node)
{
	node["myCategoryID"] >> this -> myCategoryID;
	node["myCategoryName"] >> this -> myCategoryName;
}

/**
* Stores data on the YAML as categories are created
* Pre: An emitter is passed in to track changes
* Post: The newly made categories are stored on the YAML
*/
YAML::Emitter& Category::emitYaml(YAML::Emitter& out) const
{
	out << YAML::BeginMap;
	out << YAML::Key << "myCategoryID";
	out << YAML::Value << this->myCategoryID;
	out << YAML::Key << "myCategoryName";
	out << YAML::Value << this->myCategoryName;
	out << YAML::EndMap;
	return out;
}


/*
 * Accessors and Mutators
 */

int Category::getCategoryID() const
{
	return myCategoryID;
}

const std::string& Category::getCategoryName() const
{
	return myCategoryName;
}

void Category::setCategoryID(const int categoryID)
{
	myCategoryID = categoryID;
}

void Category::setCategoryName(const std::string& categoryName)
{
	myCategoryName = categoryName;
}
