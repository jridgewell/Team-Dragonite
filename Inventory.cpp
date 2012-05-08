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

/**
* Saves an inventory object's data to the YAML
* Pre: A node from the YAML is entered
* Post: The information from the inventory object is saved onto the input node
*/
Inventory::Inventory(const YAML::Node& node)
{
	this -> parseYaml(node);
}

/*
* Creates an inventory object using the information on the node
* Pre: A YAML with the inventory information on it is passed in
* Post: An inventory is created using the data from the node
*/
void Inventory::parseYaml(const YAML::Node& node)
{
	node["mySKU"] >> this->mySKU;
	node["myItemDesc"] >> this->myItemDesc;
	node["myCategoryID"] >> this->myCategoryID;
	node["myMerchantID"] >> this->myMerchantID;
	node["myPrice"] >> this->myPrice;
	node["myQuantity"] >> this->myQuantity;
}

/*
* Uses an emitter to initialize the YAML to record data for the inventory class
* Pre: An emitter is passed in
* Post: New inventories created are stored on the YAML
*/
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

/* Purchases an object
* Pre: The quantity of the object purchased is passed
* Post: The quantity of the object is changed depending on the amount puchased
*/
int Inventory::purchase(const int quantity)
{
	this -> setQuantity(this -> getQuantity() - quantity);
	return this->getQuantity();
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

void Inventory::setCategoryID(const int categoryID)
{
	myCategoryID = categoryID;
}

void Inventory::setMerchantID(const int merchantID)
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

