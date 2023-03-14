#include "Product.cpp"
#include "User.cpp"
#include "Seller.cpp"
#include "Buyer.cpp"
#include <vector>
#include <string>
#include <iostream>

int main() {

    Seller s = Seller(true, "John");
    Buyer b = Buyer(false, "Jane");

    s.messageSend(b, "Hello");
    b.messagesPrint();

}