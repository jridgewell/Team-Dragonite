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
      double myPrice;
      int myQuantity;

   public:
      Inventory();
      Inventory(const int sku, const std::string& itemDesc, const int categoryID, const double price, const int quantity)
      	  : mySKU(sku), myItemDesc(itemDesc), myCategoryID(categoryID), myPrice(price), myQuantity(quantity) {}
      Inventory(const Inventory& inventory);
      Inventory(const YAML::Node& node);
      virtual ~Inventory() {}
      void parseYaml(const YAML::Node& node);

      int getSKU() const;
      const std::string& getItemDesc() const;
      int getCategoryID() const;
      double getPrice() const;
      int getQuantity() const;

      void setSKU(const int sku);
      void setItemDesc(const std::string& itemDesc);
      void setCategoryID(int categoryID);
      void setPrice(const double price);
      void setQuantity(const int quantity); 
};

#endif
