// written by: Samriddhi Lamichhane and Rahul Shenoy

// #include "Driver.cpp"
#include "Product.cpp"
#include "User.cpp"
#include "Seller.cpp"
#include "Buyer.cpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;
int Product::pid;
int User::uid;

int main()
{
    // cout << "Starting Simulation..." << endl;
    // int userType;
    // while (true)
    // {
    //     cout << "Choose a role: " << endl;
    //     cout << "- Enter 1 for Buyer" << endl;
    //     cout << "- Enter 2 for Seller" << endl;
    //     cin >> userType;
    //     if (userType == 1 || userType == 2)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         cout << "invalid input." << endl;
    //     }
    // }

    // Driver d = new Driver();
    // Driver &d = Driver::GetInstance();
    // Product p = new Product(1.4, 2.5, "nam");
    // cout << p.getProductName() << endl;
    Seller s = Seller(true,"Sami");
    // cout << s.getName() << endl;
    cout << s.getName() << endl;
    // User u;
    // u.setName("Rahul");
    
};