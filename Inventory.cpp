/**
* Invenctory
* @date May 2, 2012
* @authoer Jure Jumalon
*/

#include "Inventory.h"

Inventory::Inventory()
/**
 * Purpose: Inventory constructor
 * Post: Inventory object created
 * 			SKU = 0
 * 			Item Description = "Item Description"
 * 			Category ID = 0
 * 			Price = 0.0
 * 			Quantity = 0
 */
{
	this -> setSKU(0);
	this -> setItemDesc("Item Description");
	this -> setCategoryID(0);
	this -> setPrice(0.0);
	this -> setQuantity(0);
}

Inventory::Inventory(const Inventory& inventory)
/**
 * Purpose: Copy Inventory constructor
 * Post: Inventory object created as a copy of inventory
 */
{
	this -> setSKU(inventory.mySKU);
	this -> setItemDesc(inventory.myItemDesc);
	this -> setCategoryID(inventory.myCategoryID);
	this -> setPrice(inventory.myPrice);
	this -> setQuantity(inventory.myQuantity);
}

Inventory::Inventory(const YAML::Node& node)
{
	this -> parseYaml(node);
}

void Inventory::parseYaml(const YAML::Node& node)
{
	node["mySKU"] >> this->mySKU;
	node["myItemDesc"] >> this->myItemDesc;
	node["myCategoryID"] >> this->myCategoryID;
	node["myPrice"] >> this->myPrice;
	node["myQuantity"] >> this->myQuantity;
}


/*
 * Accessors and Mutators
 */

int Inventory::getSKU() const
{
   return mySKU;
}

const std::string& Inventory::getItemDesc() const
{
   return myItemDesc; 
}

int Inventory::getCategoryID() const
{
   return myCategoryID;
}

float Inventory::getPrice() const
{
   return myPrice;
}

int Inventory::getQuantity() const
{
   return myQuantity;
}

void Inventory::setSKU(const int sku)
{
	mySKU = sku;
}

void Inventory::setItemDesc(const std::string& itemDesc)
{
	myItemDesc = itemDesc;
}

void Inventory::setCategoryID(int categoryID)
{
	myCategoryID = categoryID;
}

void Inventory::setPrice(const float price)
{
   myPrice = price;
}

void Inventory::setQuantity(const int quantity)
{
   myQuantity = quantity;
}







