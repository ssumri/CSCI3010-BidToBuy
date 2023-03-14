#include "Buyer.h"
// #include "Product.h"
// #include "Seller.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Buyer::Buyer(bool buyerseller, string name_) : User(buyerseller)
{

    name = name_;
    balance = 0;
    setName(name_);
    buyerID = "B" + to_string(++uid);
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

string Buyer::getUID()
{
    return buyerID;
}

void Buyer::getBuyerOverview()
{
    return;
}

bool Buyer::messageSend(Seller &s, string message)
{
    string add = "Buyer " + this->getName() + " sent you a message: " + message;
    s.messages.push_back(add);
    this->messages.push_back(add);
    if (s.messages[s.messages.size() - 1] == add)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Buyer::messagesPrint()
{
    cout << "Messages: " << endl;
    for (int i = 0; i < this->messages.size(); i++)
    {
        cout << this->messages[i] << endl;
    }
}
