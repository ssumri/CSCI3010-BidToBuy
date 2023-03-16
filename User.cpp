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

// default constructor for User. seller by default
User::User()
{
    isSeller = true;
}

// returns true of user is a seller
bool User::getIsSeller()
{
    return isSeller;
}

// sets user to be buyer or seller. Only used when initilizing
void User::setIsSeller(bool issel)
{
    isSeller = issel;
}

// sets userid. only used when initilizing
void User::setUserID(int id)
{
    userID = id;
}

// returns userID. integer
int User::getUserId()
{
    return userID;
}

// sets name of user
void User::setName(string n)
{
    name = n;
}

// returns name of user
string User::getName()
{
    return name;
}

// sets Phone number of user
void User::setPhoneNumber(int num)
{
    phoneNum = num;
}

// returns phone number of user
int User::getPhoneNumber()
{
    return phoneNum;
}

// sets address of user
void User::setAddress(string add)
{
    address = add;
}

// returns address of user
string User::getAddress()
{
    return address;
}

// sends message between users and saves into database.
bool User::messageSend(User &u, string message)
{
    bool sender = getIsSeller();
    bool receiver = u.getIsSeller();
    string x, y;

    if (sender == true)
    {

        x = "Seller";
    }
    else
    {
        x = "Buyer";
    }

    if (receiver == true)
    {

        y = "Seller";
    }
    else
    {
        y = "Buyer";
    }

    if (x == y)
    {
        return false;
    }

    // records message to messages array.
    string add = x + " " + getName() + " sent " + y + " " + u.getName() + " a message: " + message;
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

// prints messages records that user has
void User::messagesPrint()
{
    cout << "Messages: " << endl;
    for (int i = 0; i < this->messages.size(); i++)
    {
        cout << this->messages[i] << endl;
    }
}

// ______________________ BUYER STUFF ______________________

class Seller;

// parameterized constructor
Buyer::Buyer(bool buyerseller, string name_) : User(buyerseller)
{

    name = name_;
    balance = 1000;
    setName(name_);
    buyerID = "B" + to_string(++uid);
}

// adds bid to product
bool Buyer::addBidToProduct(Product &p, double bid)
{
    if (bid > p.getCurrentBid() && bid <= this->getBalance())
    {
        p.setCurrentBid(bid, buyerID); // sets current bid to bid and sets buyerID to highest bidder
        p.addToMap(buyerID, p);        // adds buyerID to product map
        bidHistory.insert({p.getProductName(), bid});
        cout << "Your bid has been placed" << endl;
        balance = balance - bid; // subtracts bid from balance
        cout << "Your current balance is now: " << this->getBalance() << endl;
        return true;
    }
    else if (bid > this->getBalance())
    {
        cout << "You do not have enough money to bid on this item" << endl; // if bid is greater than balance
        cout << "Your balance is: " << this->getBalance() << endl;
        return false;
    }
    else
    {
        cout << "Your bid is not high enough" << endl; // if bid is less than current bid
        cout << "The current bid is: " << p.getCurrentBid() << endl;
        return false;
    }
}
// buyer has won the auction and is deciding whether to buy the product or not
bool Buyer::wantsToBuyProduct(Product &p)
{
    if (!p.getOpen() && p.productMap[getUID()].getPID() == p.getPID()) // buyer is the highest bidder
    {
        cout << "You have won the auction for " << p.getProductName() << endl;
        cout << "Press 1 to purchase this item or press 2 to relinquish your bid" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            string add = "You have purchased this item and are the owner of " + p.getProductName(); // buyer still wants to buy product
            this->messages.push_back(add);
            p.setOID(this->getUID());
            return true;
        }
        else if (choice == 2)
        {
            string add = "You have relinquished your bid and your bid money has been added back to your account"; // buyer does not want to buy product
            this->messages.push_back(add);
            balance = balance + p.getCurrentBid();
            return false;
        }
        else
        {
            cout << "Invalid input" << endl;
            return false;
        }
        return false;
    }
    else
    {
        string add = "You did not win the auction for this item"; // buyer is not the highest bidder
        this->messages.push_back(add);
        return false;
    }
}

double Buyer::getBalance() // returns balance
{
    return balance;
}

string Buyer::getUID() // returns buyerID
{
    return buyerID;
}

void Buyer::addBuyer() // adds buyer to database
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

void Buyer::getBuyerOverview() // ***
{
    cout << "Insert Buyer Overview here" << endl;
}

void Buyer::printBidHistory() // prints bid history
{
    cout << "Bid History: " << endl;
    for (auto itr = bidHistory.begin(); itr != bidHistory.end(); ++itr)
    {
        cout << "Product Name: " << itr->first << "| Bid amount: " << itr->second << endl;
    }
}

// ______________________ SELLER STUFF ______________________

// parameterized constructor for seller. takes in name
Seller::Seller(bool sellerorbuyer, string name_) : User(sellerorbuyer)
{

    balance = 0.0;
    name = name_;
    setName(name_);
    sellerID = "S" + to_string(++uid);
    products = vector<Product>();
}

// adds product to the product map and links owner as the seller.
void Seller::addProductForSale(Product &p)
{
    this->products.push_back(p);
    p.productMap.emplace(sellerID, p);
}

void Seller::removeProductForSale(Product &p) // removes product from product map and products vector
{
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].getPID() == p.getPID())
        {
            products.erase(products.begin() + i);
        }
    }
    p.productMap.erase(sellerID);
}

// returns balance of seller
double Seller::getBalance()
{
    return balance;
}

// prints general information of seller
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
    return products; // returns products vector
}

void Seller::closedAuction(Product &p)
{
    p.setOpen(false); // closes auction on a product
}

string Seller::getUID()
{
    return sellerID; // returns sellerID
}

// messages buyer when they have on the bid on a product
void Buyer::notifyBuyer(Product p)
{
    if (!p.getOpen())
    {

        cout << "Buyer " << p.getOID() << " has won the auction for " << p.getProductName() << endl;
    }
}

void Seller::addSeller()
{
    ofstream outFile;                            // output file stream
    outFile.open("userInfo.csv", std::ios::app); // opens file
    if (!outFile.fail())
    {
        outFile << sellerID << "," << name << "," << isSeller << "," << address << "," << phoneNum << endl; // adds seller to database
    }
    else
    {
        cout << "Cannot open file" << endl; // if file cannot be opened
    }
}