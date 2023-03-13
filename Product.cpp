// Electronics, Furniture, Clothing, Jewelry, Games
#include "Product.h"
#include <vector>
#include <fstream>
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
