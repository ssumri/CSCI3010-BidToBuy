#define _USER_H_
#ifndef _User_H_

#include <vector>
#include <string>
#include "Product.h"

using namespace std;
static vector<string> messages = {};
class User
{
public:
    User(bool buyerorseller); // true for seller false for buyer
    // ~User();
    // void setIsSeller(); // false for buyer true for setter
    bool getisSeller();           // false for buyer true for setter
    string getUserId();           // returns user id
    void setName(string n);       // updates name of user
    string getName();             // returns name of user
    void setPhoneNumber(int num); // updates number of user
    int getPhoneNumber();         // returns number of user

    // getter and setters for all fields
    // add applicable methods and use dynamic dispatch as needed
private:
    // Add fields as applicable
    bool isSeller;
    string userID;
    string name;
    int phoneNum;
    double balance;
};

class Seller : public User
{
public:
    Seller(string name_) : User(true)
    {

        balance = 0;
        products = {};
        messages = {};
    }
    void addProductForSale(Product p); // adds a product to the seller's list of products
    double getBalance();               // returns the balance of the seller
    void getSellerOverview();          // returns a list of products for sale
    // requires << operator overload for seller and products

    // define operator overload for == in terms of products

private:
    vector<Product> products;
    double balance;
    // add more fields as applicable
};

class Buyer : public User
{
public:
    Buyer(string name_) : User(false)
    {

        balance = 0;
        products = {};
        messages = {};
    }
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