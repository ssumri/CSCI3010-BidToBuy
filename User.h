#ifndef _USER_H_
#define _USER_H_

#include <vector>
#include <string>
// #include "Seller.h"
// #include "Product.h"

using namespace std;
// stores all the possible messages between buyer and seller
static vector<string> messages = vector<string>();
class User
{
public:
    User(bool buyerorseller); // true for seller false for buyer
    User();
    // void setIsSeller(); // false for buyer true for setter
    bool getIsSeller();           // false for buyer true for setter
    int getUserId();              // returns user id
    void setName(string n);       // updates name of user
    string getName();             // returns name of user
    void setPhoneNumber(int num); // updates number of user
    int getPhoneNumber();         // returns number of user

    // getter and setters for all fields
    // add applicable methods and use dynamic dispatch as needed
private:
    // Add fields as applicable
    bool isSeller;
    int userID;
    string name;
    int phoneNum;
    double balance;
};

#endif