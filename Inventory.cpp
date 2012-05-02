/**
* Invenctory
* @date May 2, 2012
* @authoer Jure Jumalon
*/

#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::Inventory(const int sku, const std::string& itemDesc, const int categoryID, const float price, const int quantity);

Inventory::Inventory(const Inventory & inventory)
{
}

Inventory::Inventory(const YAML::Node& node);
{
}

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

void Inventory::setPrice(const float price)
{
   myPrice = price;
}

void Inventory::setQuantity(const int quantity)
{
   myQuantity = quantity;
}







