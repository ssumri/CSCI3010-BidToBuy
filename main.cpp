#include <vector>
#include <string>
#include <iostream>

#include "Product.cpp"
#include "User.cpp"

using namespace std;

int Buyer::uid;
int Seller::uid;
int Product::pid;
string Product::oid;

// 3/15/2023 1:02 update: you can now move on the next seller, and adding a single product works without asking for another product

/*
TODO:
- reimplement driver with helper functions
- finish product category functions in product.cpp
- << operator overload for Product Category
- CSV files
    - writing to userInfo csv file
    - editing data inside csv file
- Bidding process
    - show buyer balance
    - map that each product has. stores string as key and double as value(userID, bid)
- UI
    - edit personal information
    - choose between buyer and seller
    - allow buyer to decide on how much bid to place.
- Messaging between users
    - notify buyer when bid is won
    - notify seller when buyer wants to buy the item
*/

// ProductCategory stringToCategory(string s)
// {
//     if (s == "Clothing")
//     {
//         return ProductCategory::Clothing;
//     }
//     if (s == "Electronics")
//     {
//         return ProductCategory::Electronics;
//     }
//     if (s == "Furniture")
//     {
//         return ProductCategory::Furniture;
//     }
//     if (s == "Games")
//     {
//         return ProductCategory::Games;
//     }
//     if (s == "Jewelry")
//     {
//         return ProductCategory::Jewelry;
//     }
//     else
//     {
//         return ProductCategory::Other;
//     }
// }

// string categoryToString(ProductCategory c)
// {
//     if (c == ProductCategory::Clothing)
//     {
//         return "Clothing";
//     }
//     if (c == ProductCategory::Electronics)
//     {
//         return "Electronics";
//     }
//     if (c == ProductCategory::Furniture)
//     {
//         return "Furniture";
//     }
//     if (c == ProductCategory::Games)
//     {
//         return "Games";
//     }
//     if (c == ProductCategory::Jewelry)
//     {
//         return "Jewelry";
//     }
//     if (c == ProductCategory::Other)
//     {
//         return "Other";
//     }
//     else
//     {
//         return "Invalid Product Category Type.";
//     }
// }

int main()
{
    vector<Seller> sellers = {Seller(true, "SuperSeller23"), Seller(true, "BargainHunter87"), Seller(true, "Collectibles_Galore"), Seller(true, "Fashionista101"), Seller(true, "TechDeals247"), Seller(true, "RetroGames4U"), Seller(true, "LuxuryWatchesOnly"), Seller(true, "AntiqueTreasuresShop"), Seller(true, "PetLoverParadise"), Seller(true, "SportsMemorabiliaHQ")};
    vector<Buyer> buyers = {Buyer(false, "SmartShopper123"), Buyer(false, "BargainFinder"), Buyer(false, "Shopaholic22"), Buyer(false, "SeriousBuyer"), Buyer(false, "FrequentBuyer55"), Buyer(false, "DealHunter99"), Buyer(false, "LuxuryBuyer123"), Buyer(false, "BestOfferMaker"), Buyer(false, "VintageCollector"), Buyer(false, "ImpulseBuyer")};
    // Product(string prodName, ProductCategory category_, string cond_, double price_, double highestb_);
    vector<Product> products = {Product("iPhone 12 Pro Max", ProductCategory::Electronics, "New", 999.99, 0.0), Product("iPhone 12 Pro", ProductCategory::Electronics, "New", 999.99, 0.0), Product("iPhone 12", ProductCategory::Electronics, "New", 799.99, 0.0), Product("iPhone 12 Mini", ProductCategory::Electronics, "New", 699.99, 0.0), Product("iPhone 11 Pro Max", ProductCategory::Electronics, "New", 999.99, 0.0)};

    cout << "Starting Simulation..." << endl;

    products[0].addProduct();

    int userType;
    int iterator = 0;
    // runs the simulation multiple times during the run.
    while (true)
    {
        cout << "Choose a role: " << endl;
        cout << "- Enter 1 for Buyer" << endl;
        cout << "- Enter 2 for Seller" << endl;
        cin >> userType;

        // checks to see if userType is valid
        while (userType != 1 && userType != 2)
        {
            cout << "Invalid input. Please try again." << endl;
            cout << "- Enter 1 for Buyer" << endl;
            cout << "- Enter 2 for Seller" << endl;
            cin >> userType;
        }

        // loop for Buyer
        if (userType == 1)
        {
            // ????
            Buyer b = buyers[iterator];

            cout << "Displaying buyer overview of " << b.getName() << endl;
            b.getBuyerOverview();

            // TODO- iterate through products in database.
            for (int i = 0; i < products.size(); i++)
            {
                cout << "Product " << i << ": " << endl;
                cout << products[i].productDetails() << endl;
            }
            // --- creates a vector with all the products in productsBid file.
            // --- iterates through all the values in the products vector.

            cout << "Press 1 to bid on a product, 0 to continue to next buyer" << endl;
            cin >> userType;
            if (userType == 1)
            {
                cout << "Enter product ID: " << endl;
                int prodID;
                cin >> prodID;
                bool found = false;
                Seller s = Seller(true, "Rahul");

                for (int i = 0; i < products.size(); i++)
                {
                    s.addProductForSale(products[i]);
                }
            }
        }
        else
        {
            
            Seller s = sellers[iterator];
            cout << "Displaying seller overview of " << s.getName() << endl;
            s.getSellerOverview();
            cout << "Press 1 to add a product for sale, 0 to continue to next seller" << endl;
            cin >> userType;
            while (true) 
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
            } else {

                iterator++;
                Seller s = sellers[iterator];
                cout << "Displaying seller overview of " << s.getName() << endl;
                s.getSellerOverview();
                cout << "Press 1 to add a product for sale, 0 to continue to next seller" << endl;
                cin >> userType;


            }
        }
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