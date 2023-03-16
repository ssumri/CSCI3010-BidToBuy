#ifndef DRIVER_H
#define DRIVER_H
#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <map>

#include "Product.h"
#include "User.h"

using namespace std;

class Driver
{
public:
    static Driver &GetInstance()
    {
        static Driver instance;
        return instance;
    }

    void setInitialProducts();
    void setInitialUsers();

    map<string, Product> getActiveProducts();

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
    vector<User> users;

    vector<Product> allProducts;
    map<string, Product> onSaleProds;
};

#endif