#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <vector>
#include <string>
// Electronics, Furniture, Clothing, Jewelry, Games

using namespace std;
class Product
{
private:
public:
    Product();
    ~Product();
    double getCurrentBid();   // returns the current highest bid for this product
    void setCurrentBid();     // sets a bid for this product, if the bid is higher than the current bid, the current bid is updated
    double getProductPrice(); // returns the price of the product
    string getProductName();  // returns the name of the product

    enum class ProductCategory // used to define all the category of products sellers can sell on this app.
    {
        Electronics,
        Furniture,
        Clothing,
        Jewelry,
        Games
    };
};
class Electronics : public Product
{
private:
    string electronicType;
};
class Furniture : public Product
{
private:
    string furnitureType;
};
class Clothing : public Product
{
private:
    int size;
};
class Jewelry : public Product
{
private:
    string metal;
};
class Games : public Product
{
private:
    string console;
};

// used to
// define all the category of products sellers can sell on this app. You may
// add as many categories you like. There should be at least enough of them to
// cover all the classes you created as part of the products inheritance
// hierarchy.
Product *productFactory(Clothing::ProductCategory pc)
{
    switch (pc)
    {
        // case ProductCategory::Clothing:
        //     return new Clothing(...);
        // case ProductCategory::Furniture:
        //     return new Furniture(...);
        //     .
        //         .
        //         .default : return new Product(....);
    }
}

#endif