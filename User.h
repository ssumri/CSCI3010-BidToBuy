#ifndef _USER_H_
#define _USER_H_

#include <vector>
#include <string>
#include <iostream>
#include "Product.h"
#include <map>

using namespace std;

class Product;
// stores all the possible messages between buyer and seller
static vector<string> messages = vector<string>();
class User
{

public:
    // void setIsSeller(); // false for buyer true for setter
    bool getIsSeller(); // false for buyer true for setter
    void setIsSeller(bool issel);
    int getUserId(); // returns user id
    void setUserID(int id);
    void setName(string n);       // updates name of user
    string getName();             // returns name of user
    void setPhoneNumber(int num); // updates number of user
    int getPhoneNumber();         // returns number of user
    User(bool buyerorseller);     // true for seller false for buyer

    string getAddress();
    void setAddress(string newaddress);
    bool messageSend(User &u, string message);
    void messagesPrint();
    vector<string> messages;

    User();

protected:
    // Add fields as applicable

    bool isSeller;
    int userID;
    string name;
    int phoneNum;
    double balance;
    string address;
};

class Buyer : public User
{
    static int uid;

public:
    Buyer(bool buyerseller, string name_);
    bool addBidToProduct(Product &p, double bid); // places a bid
    double getBalance();                          // returns the balance of the buyer
    void getBuyerOverview();                      // returns a list of items bought by user
    // requires << operator overload for seller and products
    string getUID();

    void notifyBuyer(Product p);
    void addBuyer();
    void printBidHistory();

    bool wantsToBuyProduct(Product &p);

    map<string, double> bidHistory;

private:
    // add more fields as applicable
    string name;
    vector<Product> products;
    double balance;
    string buyerID;
};

class Seller : public User
{
    static int uid;

public:
    Seller(bool sellerorbuyer, string name_);
    void addProductForSale(Product &p);    // adds a product to the seller's list of products
    void removeProductForSale(Product &p); // removes a product from the seller's list of products
    double getBalance();                   // returns the balance of the seller
    void getSellerOverview();              // returns a list of products for sale

    // requires << operator overload for seller and products
    vector<Product> getProducts();
    string getUID();
    void closedAuction(Product &p);
    void addSeller();

    // define operator overload for == in terms of products

private:
    vector<Product> products;
    double balance;
    string name;
    string sellerID;

    // add more fields as applicable
};

#endif