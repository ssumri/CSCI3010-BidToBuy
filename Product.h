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
    Games
};
class Product
{
private:
    double price;
    double highestBid;
    string name;

public:
    Product();
    Product(int p, int hb, string n_);
    // ~Product(); // not sure why we would need this
    double getCurrentBid();        // returns the current highest bid for this product
    void setCurrentBid(double nb); // sets a bid for this product, if the bid is higher than the current bid, the current bid is updated
    double getProductPrice();      // returns the price of the product
    string getProductName();       // returns the name of the product
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

#endif