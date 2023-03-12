#define _BUYER_H_
#ifndef _BUYER_H_

#include <vector>
#include <string>
#include "Product.h"
#include "User.h"

using namespace std;

class Buyer : public User
{
public:
    Buyer(string name_);
    void addBidToProduct();  // places a bid
    double getBalance();     // returns the balance of the buyer
    void getBuyerOverview(); // returns a list of items bought by user
    // requires << operator overload for seller and products

    // define operator overload for == in terms of products

private:
    // add more fields as applicable
    vector<Product> products;
    double balance;
};

#endif