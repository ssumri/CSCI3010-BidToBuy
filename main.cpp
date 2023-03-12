// written by: Samriddhi Lamichhane and Rahul Shenoy

// #include "Driver.h"
// #include "Product.h" // dont need
// #include "User.h" // circular dependency
// #include "Buyer.h"
#include "Seller.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    cout << "Starting Simulation..." << endl;
    int userType;
    while (true)
    {
        cout << "Choose a role: " << endl;
        cout << "- Enter 1 for Buyer" << endl;
        cout << "- Enter 2 for Seller" << endl;
        cin >> userType;
        if (userType == 1 || userType == 2)
        {
            break;
        }
        else
        {
            cout << "invalid input." << endl;
        }
    }

    // Driver d = new Driver();
    // Driver &d = Driver::GetInstance();
    // Product p = new Product(1.4, 2.5, "nam");
    // cout << p.getProductName() << endl;
    Seller s("Rahul");
    // cout << s.getBalance() << endl;
    // User u;
    // u.setName("Rahul");
    // Product *a = new Product();
    // Product *b = new Product(1001, 1, "iphone 3", ProductCategory::Electronics, "New", 599.00, 599.00);
    //  ./User.h:60:27: error: no matching constructor for initialization of 'User'
};