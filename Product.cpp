// Electronics, Furniture, Clothing, Jewelry, Games
#include "Product.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

Product::Product(string prodName_, ProductCategory category_, string cond_, double price_, double highestb_)
{
    productID = ++this->pid;
    prodName = prodName_;
    category = category_;
    condition = cond_;
    price = price_;
    highestBid = highestb_;
    open = true;
    onHold = false;
}

Product::Product()
{
    productID = ++this->pid;
    prodName = "";
    category = ProductCategory::Other;
    condition = "New";
    price = 0.0;
    highestBid = 0.0;
    open = true;
    onHold = false;
}

void Product::setInitialProducts(vector<Product> *stock)
{
    return;
}

void Product::addProduct()
{
    ofstream outFile;
    outFile.open("productBid.csv", std::ios::app);
    if (!outFile.fail())
    {
        outFile << "875,3.54,9.00,ring,new,1,Jewelry" << endl;
        // outFile << productID << "," << price << "," << highestBid << "," << prodName << "," << condition << "," << ownerID << category << endl;
    }
    else
    {
        cout << "Cannot open file" << endl;
    }
    open = true;
    onHold = false;
}

string Product::productDetails()
{
    string output = "";
    return output;
}

double Product::getCurrentBid()
{
    return highestBid;
}

bool Product::setCurrentBid(double nb)
{
    if (open == true && onHold == false)
    {
        highestBid = nb;
        return true;
    }
    else if (open == true && onHold == true)
    {
        cout << "This product is on hold. You cannot bid on it." << endl;
        return false;
    }
    else
    {
        cout << "This product is closed. You cannot bid on it." << endl;
        return false;
    }
}

bool Product::getOpen()
{
    return open;
}

void Product::setOID(string oid_)
{
    oid = oid_;
}

double Product::getProductPrice()
{
    return price;
}

string Product::getProductName()
{
    return prodName;
}

void Product::setProductCategory(ProductCategory category_)
{
    category = category_;
}

void Product::setNewOwner(int userID)
{
    ownerID = userID;
}

string Product::getOID()
{
    return oid;
}
int Product::getPID()
{
    return pid;
}
// used to
// define all the category of products sellers can sell on this app. You may
// add as many categories you like. There should be at least enough of them to
// cover all the classes you created as part of the products inheritance
// hierarchy.
// Electronics, Furniture, Clothing, Jewelry, Games
Product *productFactory(string pc)
{
    if (pc == "Electronics")
    {
        return new Electronics();
    }
    else if (pc == "Clothing")
    {
        return new Clothing();
    }
    else if (pc == "Furniture")
    {
        return new Furniture();
    }
    else if (pc == "Games")
    {
        return new Games();
    }
    else if (pc == "Other")
    {
        return new Other();
    }
    else
    {
        return new Product();
    }
}

Electronics::Electronics() : Product()
{
    category = ProductCategory::Electronics;
    condition = "New";
    price = 0.0;
    highestBid = 0.0;
    open = true;
    onHold = false;
}

Furniture::Furniture() : Product()
{
    category = ProductCategory::Furniture;
    condition = "New";
    price = 0.0;
    highestBid = 0.0;
    open = true;
    onHold = false;
}

Clothing::Clothing() : Product()
{
    category = ProductCategory::Clothing;
    condition = "New";
    price = 0.0;
    highestBid = 0.0;
    open = true;
    onHold = false;
}

Jewelry::Jewelry() : Product()
{
    category = ProductCategory::Jewelry;
    condition = "New";
    price = 0.0;
    highestBid = 0.0;
    open = true;
    onHold = false;
}

Games::Games() : Product()
{
    category = ProductCategory::Games;
    condition = "New";
    price = 0.0;
    highestBid = 0.0;
    open = true;
    onHold = false;
}

Other::Other() : Product()
{
    category = ProductCategory::Electronics;
    condition = "New";
    open = true;
    onHold = false;
}