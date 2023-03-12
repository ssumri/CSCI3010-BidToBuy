#include "User.h"
// #include "Product.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

// bool messageSend(User u, string message)
// {
//     string add;
//     if (u.getIsSeller() == false)
//     {
//         add = "Buyer says: " + message;
//     }
//     else
//     {
//         add = "Seller says: " + message;
//     }

//     b.messages.push_back(add);
//     this->messages.push_back(add);
//     if (b.message[message.size() - 1] == add)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

void messageRecieve()
{
    // for (int i = 0; i < messages.size(); i++)
    // {
    //     cout << messages[i] << endl;
    // }
}

User::User(bool bors)
{
    isSeller = bors;
    userID = 0; // use a static int to keep track of this , userID++;
    name = "";
}

User::User()
{
    isSeller = true;
    userID = 0;
    name = "Rahul";
}

// User::~User()
// {
//     delete this;
// }

bool User::getIsSeller()
{
    return isSeller;
}

int User::getUserId()
{
    return userID;
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
