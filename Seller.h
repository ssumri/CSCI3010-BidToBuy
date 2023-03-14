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
static int uid;
public:
    Seller(bool sellerorbuyer, string name_);
    void addProductForSale(Product p); // adds a product to the seller's list of products
    double getBalance();               // returns the balance of the seller
    void getSellerOverview();          // returns a list of products for sale
    // requires << operator overload for seller and products
    vector<Product> getProducts();
    string getUID();
    bool messageSend(Buyer b, string message);
    void messagesPrint();
    vector <string> messages;

    

    // define operator overload for == in terms of products

private:
    vector<Product> products;
    double balance;
    string name;
    string sellerID;
    
    
    // add more fields as applicable
};

#endif