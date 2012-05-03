#ifndef INVENTORY_H
#define INVENTORY_H

/**
* Inventory
* @date May 2, 2012
* @author Jure Jumalon
*
* TODO: Javadocs
*
*/

#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>

class Inventory
{
   private:
      int mySKU;
      std::string myItemDesc;
      int myCategoryID;
      float myPrice;
      int myQuantity;

   public:
      Inventory();
      Inventory(const int sku, const std::string& itemDesc, const int categoryID, const float price, const int quantity)
      	  : mySKU(sky), myItemDesc(itemDesc), myCategoryID(categoryID), myPrice(price), myQuantity(quantity) {}
      Inventory(const Inventory & inventory);
      Inventory(const YAML::Node& node);
      virtual ~Inventory();

      int getSKU() const;
      const std::string& getItemDesc() const;
      int getCategoryID() const;
      float getPrice() const;
      int getQuantity() const;

      void setPrice(const float price);
      void setQuantity(const int quantity); 
};

#endif
