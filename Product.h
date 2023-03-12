#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <vector>
#include <string>
using namespace std;
// Electronics, Furniture, Clothing, Jewelry, Games
enum class ProductCategory
{
    Electronics,
    Furniture,
    Clothing,
    Jewelry,
    Games,
    Other
};

class Product
{
private:
    double price;
    double highestBid;
    string prodName;
    int productID;
    int ownerID;
    string condition;
    ProductCategory category;

public:
    Product();
    Product(int pid_, int owner_id, string prodName, ProductCategory category_, string cond_, double price_, double highestb_);
    // ~Product(); // not sure why we would need this
    double getCurrentBid();        // returns the current highest bid for this product
    void setCurrentBid(double nb); // sets a bid for this product, if the bid is higher than the current bid, the current bid is updated
    double getProductPrice();      // returns the price of the product
    string getProductName();       // returns the name of the product
    void setProductCategory(ProductCategory category_);
    void setNewOwner(int userID);
};

class Electronics : public Product
{
private:
    ProductCategory category = ProductCategory::Electronics;
    string electronicType;
};

class Furniture : public Product
{
private:
    ProductCategory category = ProductCategory::Furniture;
    string furnitureType;
};

class Clothing : public Product
{
private:
    ProductCategory category = ProductCategory::Clothing;
    int size;
};

class Jewelry : public Product
{
private:
    ProductCategory category = ProductCategory::Jewelry;
    string metal;
};

class Games : public Product
{
private:
    ProductCategory category = ProductCategory::Games;
    string console;
};

class Other : public Product
{
private:
    ProductCategory category = ProductCategory::Other;
};

#endif