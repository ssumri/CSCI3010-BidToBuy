// Electronics, Furniture, Clothing, Jewelry, Games
#include "Product.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// parameterized constructor for product class
Product::Product(string prodName_, ProductCategory category_, string cond_, double price_, double highestb_)
{
    // increments the static pid everytime a new product is created.
    productID = ++this->pid;
    prodName = prodName_;
    category = category_;
    condition = cond_;
    price = price_;
    highestBid = highestb_;
    open = true;
    onHold = false;
    // init
}

// default constructor for Product class
Product::Product()
{
    // increments the static pid everytime a new product is created.
    productID = ++this->pid;
    prodName = "";
    category = ProductCategory::Other;
    condition = "New";
    price = 0.0;
    highestBid = 0.0;
    open = true;
    onHold = false;
    // init
}

string Product::getCondition()
{
    return condition; // return condition
}

string catToStr(ProductCategory c)
{
    if (c == ProductCategory::Clothing)
    {
        return "Clothing";
    }
    if (c == ProductCategory::Electronics)
    {
        return "Electronics";
    }
    if (c == ProductCategory::Furniture)
    {
        return "Furniture";
    }
    if (c == ProductCategory::Games)
    {
        return "Games";
    }
    if (c == ProductCategory::Jewelry)
    {
        return "Jewelry";
    }
    if (c == ProductCategory::Other)
    {
        return "Other";
    }
    else
    {
        return "Invalid Product Category Type.";
    }
}

void Product::addProduct()
{
    ofstream outFile; // create output file stream
    outFile.open("productBid.csv", std::ios::app);
    if (!outFile.fail())
    {
        outFile << productID << "," << price << "," << highestBid << "," << prodName << "," << condition << "," << ownerID << catToStr(category) << endl; // write to file
    }
    else
    {
        cout << "Cannot open file" << endl; // file could not open
    }
    open = true;    // product is open for sale
    onHold = false; // product cannot be on hold when it is first created
}

string Product::productDetails()
{
    string output = "";
    // return output;
    cout << "Product ID: " << getPID() << endl;
    cout << "Product Name: " << getProductName() << endl;
    cout << "Product Category: other" << endl; // fix later
    cout << "Product Condition: " << getCondition() << endl;
    cout << "Product Price: " << getProductPrice() << endl;
    cout << "Product Highest Bid: " << getCurrentBid() << endl;
    cout << "Product Open: " << getOpen() << endl;
    cout << "Product On Hold: " << onHold << endl;
    return output;
    // printing out the product details
}

double Product::getCurrentBid()
{
    return highestBid; // return highest bid
}
// productMap.emplace(userID, Product("orange", ProductCategory::Other, "New", 2.0, 0.0));
void Product::addToMap(string id, Product &p)
{
    productMap.emplace(id, p); // add product to map
}

bool Product::setCurrentBid(double nb, string userID)
{
    if (open == true && onHold == false)
    {
        highestBid = nb;
        cout << "Bid placed successfully." << endl; // bid placed successfully
        return true;
    }
    else if (open == true && onHold == true)
    {
        cout << "This product is on hold. You cannot bid on it." << endl; // product is on hold
        return false;
    }
    else
    {
        cout << "This product is closed. You cannot bid on it." << endl; // product is closed
        return false;
    }
}

bool Product::getOpen()
{
    return open; // return open/closed
}

void Product::setOpen(bool open_)
{
    open = open_; // set open/closed
}

void Product::setOID(string oid_)
{
    oid = oid_; // set owner ID
}

double Product::getProductPrice()
{
    return price; // return price
}

string Product::getProductName()
{
    return prodName; // return product name
}

void Product::setProductCategory(ProductCategory category_)
{
    category = category_; // set product category
}

void Product::setNewOwner(int userID)
{
    ownerID = userID; // set new owner ID
}

string Product::getOID()
{
    return oid; // return owner ID
}
int Product::getPID()
{
    return pid; // return product ID
}

void Product::printMap() // print map
{
    for (auto it = productMap.begin(); it != productMap.end(); ++it)
    {
        cout << it->first << " => " << it->second.getProductName() << '\n';
    }
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