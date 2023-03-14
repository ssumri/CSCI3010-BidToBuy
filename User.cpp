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

// User::~User()
// {
//     delete this;
// }

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
