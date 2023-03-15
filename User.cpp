#include "User.h"
// #include "Product.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

User::User(bool bors)
{
    isSeller = bors;
    // use a static int to keep track of this , userID++;
}

User::User()
{
    isSeller = true;
}

bool User::getIsSeller()
{
    return isSeller;
}

void User::setName(string n)
{
    name = n;
}

string User::getName()
{
    return name;
}
void User::setPhoneNumber(int num)
{
    phoneNum = num;
}
int User::getPhoneNumber()
{
    return phoneNum;
}

// ______________________ BUYER STUFF ______________________

class Seller;

Buyer::Buyer(bool buyerseller, string name_) : User(buyerseller)
{

    name = name_;
    balance = 0; // fix balance
    setName(name_);
    buyerID = "B" + to_string(++uid);
    // products = vector<Product>();
    // messages = vector<string>();
}

bool Buyer::addBidToProduct(Product p, double bid)
{
    if (bid > p.getCurrentBid() && bid <= this->getBalance())
    {
        p.setCurrentBid(bid);
        p.setOID(this->getUID());
        return true;
    }
    else
    {
        return false;
    }
}

double Buyer::getBalance()
{
    return balance;
}

string Buyer::getUID()
{
    return buyerID;
}

bool Buyer::messageSendBuyer(string sellerName, string message)
{
    string add = "Buyer " + sellerName + " sent you a message: " + message;
    this->messages.push_back(add);
    if (this->messages[this->messages.size() - 1] == add)
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

void Buyer::getBuyerOverview()
{
    cout << "* Insert Buyer Overview here" << endl;
}

// ______________________ SELLER STUFF ______________________

Seller::Seller(bool sellerorbuyer, string name_) : User(sellerorbuyer)
{

    balance = 0.0;
    name = name_;
    setName(name_);
    sellerID = "S" + to_string(++uid);
    products = vector<Product>();
}

void Seller::addProductForSale(Product p)
{
    products.push_back(p);
}

double Seller::getBalance()
{
    return balance;
}

void Seller::getSellerOverview()
{
    cout << "Seller Overview" << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Phone Number: " << this->getPhoneNumber() << endl;
    cout << "Balance: " << this->getBalance() << endl;
    cout << "Products for Sale: " << endl;
    for (int i = 0; i < products.size(); i++)
    {
        cout << "Product " << i << ": " << products[i].getProductName() << endl;
    }
}

vector<Product> Seller::getProducts()
{
    return products;
}

string Seller::getUID()
{
    return sellerID;
}

bool Seller::messageSendSeller(string buyerName, string message)
{
    string add = "Seller " + buyerName + " sent you a message: " + message;
    this->messages.push_back(add);
    if (this->messages[this->messages.size() - 1] == add)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Seller::messagesPrint()
{
    cout << "Messages: " << endl;
    for (int i = 0; i < this->messages.size(); i++)
    {
        cout << this->messages[i] << endl;
    }
}