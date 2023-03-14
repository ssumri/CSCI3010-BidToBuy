#include "Product.cpp"
#include "User.cpp"
#include "Seller.cpp"
#include "Buyer.cpp"
#include <vector>
#include <string>
#include <iostream>

int Buyer::uid;
int Seller::uid;
int Product::pid;
int Product::oid;

int main()
{

    Seller s = Seller(true, "John");
    Buyer b = Buyer(false, "Jane");

    cout << b.getUID() << endl;
}