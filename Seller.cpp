
#include "Seller.h"
// #include "User.h"
#include "Product.h"

// #include "Buyer.cpp"
#include <vector>
#include <iostream>

using namespace std;

class User;

Seller::Seller(bool sellerorbuyer, string name_) : User(sellerorbuyer)
{

    balance = 0.0;
    name = name_;
    setName(name_);
    sellerID = "S" + to_string(++uid);
    products = vector<Product>();
}

// Seller::~Seller()
// {
//     delete this;
// }

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

bool Seller::messageSend(Buyer &b, string message)
{
    string add = "Seller " + this->getName() + " sent you a message: " + message;
    b.messages.push_back(add);
    this->messages.push_back(add);
    if (b.messages[b.messages.size() - 1] == add)
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