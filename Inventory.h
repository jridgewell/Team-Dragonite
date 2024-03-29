#ifndef INVENTORY_H
#define INVENTORY_H

/**
* Inventory
* @date May 2, 2012
* @author Jure Jumalon
*
*
* Comments: Andrew Wagenheim
*/

#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>


/*
* Outlines the Inventory class and the features contained therein.
* Inventories consist of a SKU, Item Description, Category ID, Price and Quantity of item.
* Creates inventories through one of the following:
* 1) A default constructor
* 2) A constructor with passed in values
* 3) An existing inventory object, copying its values
* 4) Inventory data retrieved from a node on the YAML
* In addition, the class is able to set/get the inventories's values
*/
class Inventory
{
   private:
      int mySKU;
      std::string myItemDesc;
      int myCategoryID;
      int myMerchantID;
      int myPrice;
      int myQuantity;

   public:
      Inventory();
      Inventory(const int sku, const std::string& itemDesc, const int categoryID, const int merchantID, const int price, const int quantity)
		: mySKU(sku), myItemDesc(itemDesc), myCategoryID(categoryID), myMerchantID(merchantID), myPrice(price), myQuantity(quantity) {}
      Inventory(const Inventory& inventory);
      Inventory(const YAML::Node& node);
      virtual ~Inventory() {}
      void parseYaml(const YAML::Node& node);
      YAML::Emitter& emitYaml(YAML::Emitter& out) const;

      int purchase(const int quantity);

      int getSKU() const;
      const std::string& getItemDesc() const;
      int getCategoryID() const;
      int getMerchantID() const;
      int getPrice() const;
      int getQuantity() const;

      void setSKU(const int sku);
      void setItemDesc(const std::string& itemDesc);
      void setCategoryID(const int categoryID);
      void setMerchantID(const int merchantID);
      void setPrice(const int price);
      void setQuantity(const int quantity);
};

#endif
