#include "User.h"
// #include "Product.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

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

void User::setAddress(string add)
{
    address = add;
}

string User::getAddress()
{
    return address;
}

// ______________________ BUYER STUFF ______________________

class Seller;

Buyer::Buyer(bool buyerseller, string name_) : User(buyerseller)
{

    name = name_;
    balance = 1000; // fix balance
    setName(name_);
    buyerID = "B" + to_string(++uid);
    // products = vector<Product>();
    // messages = vector<string>();
}

bool Buyer::addBidToProduct(Product &p, double bid)
{
    if (bid > p.getCurrentBid() && bid <= this->getBalance())
    {
        p.setCurrentBid(bid);
        p.setOID(this->getUID());
        bidHistory.insert({p.getProductName(), bid});
        cout << "Your bid has been placed" << endl;
        balance = balance - bid;
        cout << "Your current balance is now: " << this->getBalance() << endl;
        return true;
    }
    else if (bid > this->getBalance())
    {
        cout << "You do not have enough money to bid on this item" << endl;
        cout << "Your balance is: " << this->getBalance() << endl;
        return false;
    }
    else
    {
        cout << "Your bid is not high enough" << endl;
        cout << "The current bid is: " << p.getCurrentBid() << endl;
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

void Buyer::addBuyer()
{
    ofstream outFile;
    outFile.open("userInfo.csv", std::ios::app);
    if (!outFile.fail())
    {
        outFile << buyerID << "," << name << "," << isSeller << "," << address << "," << phoneNum << endl;
    }
    else
    {
        cout << "Cannot open file" << endl;
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

void Buyer::printBidHistory()
{
    cout << "Bid History: " << endl;
    for (auto itr = bidHistory.begin(); itr != bidHistory.end(); ++itr)
    {
        cout << "Product Name: " << itr->first << "| Bid amount: " << itr->second << endl;
    }
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

void Buyer::notifyBuyer(Product p)
{
    if (!p.getOpen())
    {

        cout << "Buyer " << p.getOID() << " has won the auction for " << p.getProductName() << endl;
    }
}

void Seller::addSeller()
{
    ofstream outFile;
    outFile.open("userInfo.csv", std::ios::app);
    if (!outFile.fail())
    {
        outFile << sellerID << "," << name << "," << isSeller << "," << address << "," << phoneNum << endl;
    }
    else
    {
        cout << "Cannot open file" << endl;
    }
}