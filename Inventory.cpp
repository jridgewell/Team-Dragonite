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
	this -> setMerchantID(0);
	this -> setPrice(0);
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
	this -> setMerchantID(inventory.myMerchantID);
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
	node["myMerchantID"] >> this->myMerchantID;
	node["myPrice"] >> this->myPrice;
	node["myQuantity"] >> this->myQuantity;
}

YAML::Emitter& Inventory::emitYaml(YAML::Emitter& out) const
{
	out << YAML::BeginMap;
	out << YAML::Key << "mySKU";
	out << YAML::Value << this->mySKU;
	out << YAML::Key << "myItemDesc";
	out << YAML::Value << this->myItemDesc;
	out << YAML::Key << "myCategoryID";
	out << YAML::Value << this->myCategoryID;
	out << YAML::Key << "myMerchantID";
	out << YAML::Value << this->myMerchantID;
	out << YAML::Key << "myPrice";
	out << YAML::Value << this->myPrice;
	out << YAML::Key << "myQuantity";
	out << YAML::Value << this->myQuantity;
	out << YAML::EndMap;
	return out;
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

int Inventory::getMerchantID() const
{
   return myMerchantID;
}

int Inventory::getPrice() const
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

void Inventory::setMerchantID(int merchantID)
{
	myMerchantID = merchantID;
}

void Inventory::setPrice(const int price)
{
   myPrice = price;
}

void Inventory::setQuantity(const int quantity)
{
   myQuantity = quantity;
}

