// Electronics, Furniture, Clothing, Jewelry, Games
#include "Product.h"
using namespace std;

Product::Product(double p, double hb, string n_)
{
    price = p;
    highestBid = hb;
    name = n_;
}

Product::Product()
{
    price = 0.0;
    highestBid = 0.0;
    name = "";
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
