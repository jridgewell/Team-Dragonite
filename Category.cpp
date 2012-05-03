/**
 * Category
 *
 * @date May 2, 2012
 * @author Jure Jumalon
 */

#include <"Category.h">

Category::Category()
{
	this -> setCategoryID(0);
	this -> setCategoryName("Category Name");
}

Category::Category(const int categoryID, const std::string& categoryName);

Category::Category(Category category)
{
	this -> setCategoryID(category.myCategoryID);
	this -> setCategoryName(category.myCategoryName);
}

Category::Category(const YAML::Node& node)
{
	this -> parseYaml(node);
}

void Category::parseYaml(const YAML::Node& node)
{
	node["myCategoryID"] >> this -> myCategoryID;
	node["myCategoryName"] >> this -> myCategoryName;
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
	myCategory = categoryID;
}

void Category::setCategoryName(const std::string& categoryName)
{
	myCategoryName = categoryName;
}
