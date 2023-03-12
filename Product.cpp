// Electronics, Furniture, Clothing, Jewelry, Games
#include "Product.h"
#include <vector>
#include <fstream>
using namespace std;

Product::Product(int pid_, int owner_id, string prodName, ProductCategory category_, string cond_, double price_, double highestb_)
{
    productID = pid_;
    ownerID = owner_id;
    prodName = n_;
    category = categoty_;
    condition = cond_;
    price = price_;
    highestBid = highestb_;
}

Product::Product()
{
    productID = generatePid();
    ownerID = -1;
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

void Product::setCurrentBid(double nb)
{
    if (nb > highestBid)
    {
        highestBid = nb;
    }
}

double Product::getProductPrice()
{
    return price;
}

string Product::getProductName()
{
    return name;
}

void setProductCategory(ProductCategory category_)
{
    category = category_;
}

void setNewOwner(int userID)
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
