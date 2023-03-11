#include "User.h"
#include "Product.h"

#include <vector>
#include <string>

using namespace std;

bool messageSend(User u, string message)
{
    string add;
    if (u.getisSeller() == false)
    {
        add = "Buyer says: " + message;
    }
    else
    {
        add = "Seller says: " + message;
    }

    b.messages.push_back(add);
    this->messages.push_back(add);
    if (b.message[message.size() - 1] == add)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void messageRecieve()
{
    for (int i = 0; i < messages.size(); i++)
    {
        cout << messages[i] << endl;
    }
}

User::User(bool bors, string n_)
{
    isSeller = bors;
    userID = "0"; // use a static int to keep track of this , userID++;
    name = n_;
}

User::~User()
{
    delete this;
}

bool User::getisSeller()
{
    return isSeller;
}

string User::getuserID()
{
    return userID;
}

void setName(string n)
{
    name = n;
}

string getName()
{
    return name;
}
void setPhoneNumber(int num)
{
    phoneNumber = num;
}
int getPhoneNumber()
{
    return phoneNumber;
}

Seller::~Seller()
{
    delete this;
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
    cout << "Name: " << getName() << endl;
    cout << "Phone Number: " << getPhoneNumber() << endl;
    cout << "Balance: " << getBalance() << endl;
    cout << "Products for Sale: " << endl;
    for (int i = 0; i < products.size(); i++)
    {
        cout << "Product " << i << ": " << products[i].getName() << endl;
    }
}
