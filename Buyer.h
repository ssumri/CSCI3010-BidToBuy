#ifndef _BUYER_H_
#define _BUYER_H_


#include <vector>
#include <string>
#include "Product.h"
#include "User.h"

using namespace std;

class Buyer : public User
{
public:
    Buyer(bool buyerseller, string name_);
    bool addBidToProduct(Product p, double bid);  // places a bid
    double getBalance();     // returns the balance of the buyer
    void getBuyerOverview(); // returns a list of items bought by user
    // requires << operator overload for seller and products

    // define operator overload for == in terms of products

private:
    // add more fields as applicable
    string name;
    vector<Product> products;
    double balance;
};

#endif