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
}

Product::Product()
{
    productID = ++this->pid;
    prodName = "";
    category = ProductCategory::Other;
    condition = "New";
    price = 0.0;
    highestBid = 0.0;
}

ProductCategory stringToCategory(string s)
{
    if (s == "Clothing")
    {
        return ProductCategory::Clothing;
    }
    if (s == "Electronics")
    {
        return ProductCategory::Electronics;
    }
    if (s == "Furniture")
    {
        return ProductCategory::Furniture;
    }
    if (s == "Games")
    {
        return ProductCategory::Games;
    }
    if (s == "Jewelry")
    {
        return ProductCategory::Jewelry;
    }
    else
    {
        return ProductCategory::Other;
    }
}

string categoryToString(ProductCategory c)
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

// TODO bruh
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
        outFile << productID << "," << price << "," << highestBid << "," << prodName << "," << condition << "," << ownerID << categoryToString(category) << endl;
    }
    else
    {
        cout << "Cannot open file" << endl;
    }
}

double Product::getCurrentBid()
{
    return highestBid;
}

bool Product::setCurrentBid(double nb)
{
    if (nb > highestBid)
    {
        highestBid = nb;
        return true;
    }
    return false;
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

int Product::getOID()
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
// Product *productFactory(Clothing::ProductCategory pc)
// {
//     switch (pc)
//     {
//     case ProductCategory::Clothing:
//         return new Clothing(...);
//     case ProductCategory::Furniture:
//         return new Furniture(...);
//         .
//             .
//             .default : return new Product(....);
//     }
// }
