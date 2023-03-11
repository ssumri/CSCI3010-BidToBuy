#define _DRIVER_H_
#ifndef _DRIVER_H_

#include <vector>
#include <string>
#include "Product.h"
#include "User.h"

using namespace std;

class Driver
{
private:
    vector<User> currentUsers;
    vector<Product> currentProducts;
    Driver();

public:
    void startEbay();
    // Driver();
    static Driver &GetInstance() // Singleton
    {
        // only instantiated for the first time
        static Driver instance;
        return instance;
    }
    static void initializeBuyersAndSellers(); // take in a file and create the buyers and sellers
    static void initializeProducts();         // take in a file and create the products
    static vector<Buyers> getBuyers();        // return all buyers in a vector
    static void printBuyerStats();            // print all buyers
    static void printSellerStats();           // print all sellers
    static vector<Sellers> getSellers();      // return all sellers in a vector
    static void addProducts();                // add a product to the currentProducts vector
}

#endif