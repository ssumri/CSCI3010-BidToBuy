#ifndef _SELLER_H_
#define _SELLER_H_

#include <vector>
#include <string>
#include <iostream>
#include "Product.h"
#include "User.h"

using namespace std;

// class User;
// class Product;

class Seller : public User
{
public:
    Seller(string name_);
    void addProductForSale(Product p); // adds a product to the seller's list of products
    double getBalance();               // returns the balance of the seller
    void getSellerOverview();          // returns a list of products for sale
    string getName();
    int getPhoneNumber();
    // requires << operator overload for seller and products

    // define operator overload for == in terms of products

private:
    vector<Product> products;
    double balance;
    // add more fields as applicable
};

#endif