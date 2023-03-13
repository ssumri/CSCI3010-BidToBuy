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
    vector<Seller> sellers = {Seller(true,"SuperSeller23"),Seller(true,"BargainHunter87"),Seller(true,"Collectibles_Galore"),Seller(true,"Fashionista101"),Seller(true,"TechDeals247"),Seller(true,"RetroGames4U"),Seller(true,"LuxuryWatchesOnly"),Seller(true,"AntiqueTreasuresShop"),Seller(true,"PetLoverParadise"),Seller(true,"SportsMemorabiliaHQ")};
    vector<Buyer> buyers = {Buyer(false,"SmartShopper123"),Buyer(false,"BargainFinder"),Buyer(false,"Shopaholic22"),Buyer(false,"SeriousBuyer"),Buyer(false,"FrequentBuyer55"),Buyer(false,"DealHunter99"),Buyer(false,"LuxuryBuyer123"),Buyer(false,"BestOfferMaker"),Buyer(false,"VintageCollector"),Buyer(false,"ImpulseBuyer")};
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

    if (userType == 1)
    {
        Buyer b = Buyer(false, "Rahul");
        buyers.push_back(b);
        cout << b.getName() << endl;
    }
    else
    {
        Seller s = Seller(true, "Sami");
        sellers.push_back(s);
        cout << s.getName() << endl;
    }
    
    for (int i = 0; i < sellers.size(); i++)
    {
        cout << sellers[i].getName() << endl;
    }

    // Driver d = new Driver();
    // Driver &d = Driver::GetInstance();
    // Product p = new Product(1.4, 2.5, "nam");
    // cout << p.getProductName() << endl;
    // Seller s = Seller(true,"Sami");
    // // cout << s.getName() << endl;
    // cout << s.getName() << endl;
    // User u;
    // u.setName("Rahul");
    
};