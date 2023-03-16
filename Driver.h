#ifndef DRIVER_H
#define DRIVER_H
#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <map>

#include "Product.h"
#include "User.h"

class User;
class Product;

using namespace std;

class Driver
{
public:
    // singleton initilizer for driver
    static Driver &GetInstance()
    {
        static Driver instance;
        return instance;
    }

    // sets products and users array from given data in csv files
    void setInitialProducts();
    void setInitialUsers();

    // returns the map of userid -> product.
    map<string, Product> getActiveProducts();

    // updates csv files with given product and user
    void updateProductInformation(Product p);
    void updateUserInformation(User b);

    // helper functions
    ProductCategory stringToCategory(string s);
    string categoryToString(ProductCategory c);

private:
    Driver()
    {
    }

    vector<Seller> sellers;
    vector<Buyer> buyers;

    // stores all the current users in the bidtobuy
    vector<User> users;

    // stores all products ever from bidtobuy
    vector<Product> allProducts;

    // stores all products that are on sale from bidtobuy.
    map<string, Product> onSaleProds;
};

#endif