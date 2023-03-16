
#include <vector>
#include <string>
#include <iostream>
#include "Product.h"
#include "User.h"
#include "Driver.h"

int Buyer::uid;
int Seller::uid;
int Product::pid;
string Product::oid;

using namespace std;
int main()
{
    Driver &drver = Driver::GetInstance();
    drver.setInitialProducts();

    Seller s = Seller(true, "John");
    Buyer b = Buyer(false, "Jane");

    Product p1 = Product("apple", ProductCategory::Other, "New", 2.0, 0.0);
    s.addProductForSale(p1);
    p1.productDetails();
    bool x = b.addBidToProduct(p1, 11);
    p1.productDetails();
}