#include "Buyer.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Buyer::Buyer(bool buyerseller, string name_) : User(buyerseller)
{

    name = name_;
    balance = 0;
    setName(name_);
    // products = vector<Product>();
    // messages = vector<string>();
}

bool Buyer::addBidToProduct(Product p, double bid)
{
    return p.setCurrentBid(bid);
}

double Buyer::getBalance()
{
    return balance;
}

void Buyer::getBuyerOverview()
{
    return;
}