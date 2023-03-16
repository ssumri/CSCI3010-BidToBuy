#include <vector>
#include <string>
#include <iostream>

#include "Product.h"
#include "User.h"
// #include "Driver.h"

using namespace std;

int Buyer::uid;
int Seller::uid;
int Product::pid;
string Product::oid;

// 3/15/2023 1:02 update: you can now move on the next seller, and adding a single product works without asking for another product

/*
TODO:
- reimplement driver with helper functions /maybe/
- finish product category functions in product.cpp // think DONE
- << operator overload for Product Category // nah
- CSV files - in progress
    - writing to userInfo csv file DONE
    - editing data inside csv file
- Bidding process
    - show buyer balance - coded (buyer balance shown after purhasing an item or when failed due to insufficient balance)
    - map that each product has. stores string as key and double as value(userID, bid)
- UI
    - edit personal information
    - choose between buyer and seller DONE
    - allow buyer to decide on how much bid to place. DONE
- Messaging between users
    - notify buyer when bid is won - coded not sure if it works
    - notify seller when buyer wants to buy the item
*/

void updateInformation(User b)
{
    string newName;
    bool exit = false;
    while (!exit)
    {
        cout << "What would you like to update?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Phone Number" << endl;
        cout << "3. address" << endl;
        cout << "4. exit" << endl;

        int update;
        cin >> update;
        cin.ignore();

        switch (update)
        {
        case 1:
        {
            cout << "Enter new name" << endl;
            getline(cin, newName); // run it when ready

            b.setName(newName);
            cin.ignore();
            cout << "Name has been updated" << endl;
            break;
        }
        case 2:
        {
            int newPhoneNum;

            cout << "Enter new valid phoneNumber" << endl;
            cin >> newPhoneNum;
            b.setPhoneNumber(newPhoneNum);
            cin.ignore();
            break;
        }
        case 3:
        {
            string newAddress;
            cout << "Enter new valid address" << endl;
            getline(cin, newAddress);
            b.setAddress(newAddress);
            cin.ignore();
            break;
        }
        case 4:
        {
            cout << "Going back..." << endl;
            exit = true;
            break;
        }
        default:
        {
            cout << "invalid input." << endl;
            break;
        }
        }
    }
    return;
}

int main()
{
    // Driver &drver = Driver::GetInstance();
    // drver.setInitialProducts();
    // drver.setInitialUsers();

    vector<Seller> sellers = {Seller(true, "SuperSeller23"), Seller(true, "BargainHunter87"), Seller(true, "Collectibles_Galore"), Seller(true, "Fashionista101"), Seller(true, "TechDeals247"), Seller(true, "RetroGames4U"), Seller(true, "LuxuryWatchesOnly"), Seller(true, "AntiqueTreasuresShop"), Seller(true, "PetLoverParadise"), Seller(true, "SportsMemorabiliaHQ")};
    vector<Buyer> buyers = {Buyer(false, "SmartShopper123"), Buyer(false, "BargainFinder"), Buyer(false, "Shopaholic22"), Buyer(false, "SeriousBuyer"), Buyer(false, "FrequentBuyer55"), Buyer(false, "DealHunter99"), Buyer(false, "LuxuryBuyer123"), Buyer(false, "BestOfferMaker"), Buyer(false, "VintageCollector"), Buyer(false, "ImpulseBuyer")};

    // Product(string prodName, ProductCategory category_, string cond_, double price_, double highestb_);
    vector<Product> products = {Product("iPhone 12 Pro Max", ProductCategory::Electronics, "New", 999.99, 0.0), Product("iPhone 12 Pro", ProductCategory::Electronics, "New", 999.99, 0.0), Product("iPhone 12", ProductCategory::Electronics, "New", 799.99, 0.0), Product("iPhone 12 Mini", ProductCategory::Electronics, "New", 699.99, 0.0), Product("iPhone 11 Pro Max", ProductCategory::Electronics, "New", 999.99, 0.0)};

    cout << "Starting Simulation..." << endl;

    // products[0].addProduct();
    // sellers[0].addSeller();
    // buyers[0].addBuyer();

    int userType;
    int iterator = 0;
    // runs the simulation multiple times during the run.
    while (true)
    {
        cout << "Choose a role: " << endl;
        cout << "- Enter 1 for Buyer" << endl;
        cout << "- Enter 2 for Seller" << endl;
        cin >> userType;

        // loop for Buyer
        if (userType == 1)
        {
            Buyer b = buyers[iterator];

            cout << "Displaying buyer overview of " << b.getName() << endl;
            b.getBuyerOverview();

            // options menu. buyer interface goes here
            while (true)
            {
                cout << "What would you like to do? Pick one." << endl;
                cout << "1. View products for sale." << endl;
                cout << "2. Check/send messages." << endl;
                cout << "3. Check account balance." << endl;
                cout << "4. Update personal information." << endl;
                cout << "5. View previous bids." << endl;
                cout << "6. View previous purchases. " << endl;

                int choice;
                cin >> choice;

                switch (choice)
                {
                case 1:
                {
                    cout << "Viewing products." << endl;
                    // TODO- iterate through products in database.
                    for (int i = 0; i < products.size(); i++)
                    {
                        cout << "Product " << i + 1 << ": " << endl;
                        cout << products[i].productDetails() << endl; // product ID broken!!!
                    }
                    // --- creates a vector with all the products in productsBid file.
                    // --- iterates through all the values in the products vector.

                    cout << "Press 1 to bid on a product, 0 to continue to next buyer" << endl;
                    cin >> userType;
                    if (userType == 1)
                    {
                        cout << "Which product would you like to bid on?" << endl;
                        int productChoice;
                        cin >> productChoice;
                        cout << "How much would you like to bid?" << endl;
                        double bidAmount;
                        cin >> bidAmount;
                        Product p = products[productChoice - 1];
                        bool x = b.addBidToProduct(p, bidAmount);
                        p.productDetails();
                    }
                    break;
                }
                case 2:
                {
                    cout << "Press 1 to send a message, 0 to check messages" << endl;
                    cin >> userType;
                    cin.ignore();
                    if (userType == 1)
                    {
                        Seller s = sellers[iterator];
                        cout << "Enter message to send to " << s.getName() << endl;
                        string message;
                        getline(cin, message);
                        b.messageSend(s, message);
                        cin.ignore();
                    }
                    else if (userType == 0)
                    {
                        b.messagesPrint();
                    }
                    break;
                }
                case 3:
                {
                    cout << "Balance: " << b.getBalance() << endl;
                    break;
                }
                case 4:
                {
                    updateInformation(b);
                    break;
                }
                case 5:
                {
                    cout << "Viewing previous bids." << endl;
                    b.printBidHistory();
                    break;
                }
                case 6:
                {
                    cout << "Viewing previous purchases." << endl;
                    break;
                }
                default:
                {
                    cout << "invalid input. try again" << endl;
                }
                }
            }
        }
        else if (userType == 2)
        {
            Seller s = sellers[iterator];
            cout << "Displaying seller overview of " << s.getName() << endl;
            s.getSellerOverview();

            while (true)
            {
                cout << "What would you like to do? Pick one." << endl;
                cout << "1. List products for sale." << endl;
                cout << "2. Check messages." << endl;
                cout << "3. Check account balance." << endl;
                cout << "4. Update personal information." << endl;
                cout << "5. View previous inventory." << endl;
                cout << "6. Open/Close bidding. " << endl;

                int userChoice;
                cin >> userChoice;

                switch (userChoice)
                {
                case 1:
                {
                    while (true)
                    {
                        if (userType == 1)
                        {
                            cout << "Enter product name: " << endl;
                            string prodName;
                            cin >> prodName;

                            cout << "Enter product category: " << endl;
                            string prodCategory_;
                            cin >> prodCategory_;

                            // TODO
                            // stringToCategory(prodCategory_)
                            ProductCategory prodCategory = ProductCategory::Clothing;

                            cout << "Enter product condition: " << endl;
                            string prodCondition;
                            cin >> prodCondition;

                            cout << "Enter product price: " << endl;
                            double prodPrice;
                            cin >> prodPrice;
                            Product p = Product(prodName, prodCategory, prodCondition, prodPrice, 0.0);
                            s.addProductForSale(p);
                            p.addProduct();
                            break;
                        }
                        else
                        {

                            iterator++;
                            Seller s = sellers[iterator];
                            cout << "Displaying seller overview of " << s.getName() << endl;
                            s.getSellerOverview();
                            cout << "Press 1 to add a product for sale, 0 to continue to next seller" << endl;
                            cin >> userType;
                        }
                    }
                }
                case 2:
                {
                    break;
                }
                case 3:
                {
                    cout << "Account Balance: " << s.getBalance() << endl;
                    break;
                }
                case 4:
                {
                    updateInformation(s);
                    break;
                }
                case 5:
                {
                    break;
                }
                case 6:
                {
                    break;
                }
                }

                cout << "Press 1 to add a product for sale, 0 to continue to next seller" << endl;
                cin >> userType;
            }
        }
        else
        {
            // checks to see if userType is valid
            cout << "Invalid input. Please try again." << endl;
        }
    }
};