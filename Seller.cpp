
#include "Seller.h"
// #include "User.h"
#include "Product.h"
#include <vector>
#include <iostream>

using namespace std;

// class User;

Seller::Seller(string name_) : User()
{

    balance = 0.0;
    // name = name_;
    // products = vector<Product>();
}

// Seller::~Seller()
// {
//     delete this;
// }

void Seller::addProductForSale(Product p)
{
    products.push_back(p);
}

string Seller::getName()
{
    return "Ethan";
}

int Seller::getPhoneNumber()
{
    return 12345;
}

double Seller::getBalance()
{
    return balance;
}

void Seller::getSellerOverview()
{
    cout << "Seller Overview" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Phone Number: " << getPhoneNumber() << endl;
    cout << "Balance: " << getBalance() << endl;
    cout << "Products for Sale: " << endl;
    // for (int i = 0; i < products.size(); i++)
    // {
    //     cout << "Product " << i << ": " << products[i].getName() << endl;
    // }
}