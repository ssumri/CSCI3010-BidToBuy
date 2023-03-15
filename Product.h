#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>

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
    static int pid;
    static string oid;

protected:
    double price;
    double highestBid;
    string prodName;
    int productID;
    int ownerID;
    string condition;
    ProductCategory category;
    bool open;
    bool onHold;

public:
    Product();
    Product(string prodName, ProductCategory category_, string cond_, double price_, double highestb_);
    // ~Product(); // not sure why we would need this
    double getCurrentBid();        // returns the current highest bid for this product
    bool setCurrentBid(double nb); // sets a bid for this product, if the bid is higher than the current bid, the current bid is updated
    double getProductPrice();      // returns the price of the product
    string getProductName();       // returns the name of the product
    void setProductCategory(ProductCategory category_);
    void setNewOwner(int userID);
    static string getOID();
    static int getPID();
    void setOID(string oid_);
    bool getOpen();
    string getCondition();

    void setInitialProducts(vector<Product> *stock);
    void addProduct();

    string productDetails();
};

class Electronics : public Product
{
public:
    Electronics();

private:
    ProductCategory category = ProductCategory::Electronics;
    string electronicType;
};

class Furniture : public Product
{
public:
    Furniture();

private:
    ProductCategory category = ProductCategory::Furniture;
    string furnitureType;
};

class Clothing : public Product
{
public:
    Clothing();

private:
    ProductCategory category = ProductCategory::Clothing;
    int size;
};

class Jewelry : public Product
{
public:
    Jewelry();

private:
    ProductCategory category = ProductCategory::Jewelry;
    string metal;
};

class Games : public Product
{
public:
    Games();

private:
    ProductCategory category = ProductCategory::Games;
    string console;
};

class Other : public Product
{
public:
    Other();

private:
    ProductCategory category = ProductCategory::Other;
};

#endif