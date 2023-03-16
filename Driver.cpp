#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <fstream>
#include <map>
#include <sstream>
#include "Driver.h"
#include "User.h"
#include "Product.h"

using namespace std;

// takes in string input and returns corresponding productCategory
ProductCategory Driver::stringToCategory(string s)
{
    if (s == "Clothing")
    {
        return ProductCategory::Clothing;
    }
    if (s == "Electronics")
    {
        return ProductCategory::Electronics;
    }
    if (s == "Furniture")
    {
        return ProductCategory::Furniture;
    }
    if (s == "Games")
    {
        return ProductCategory::Games;
    }
    if (s == "Jewelry")
    {
        return ProductCategory::Jewelry;
    }
    else
    {
        return ProductCategory::Other;
    }
}

// takes in productcategory input and returns corresponding string
string Driver::categoryToString(ProductCategory c)
{
    if (c == ProductCategory::Clothing)
    {
        return "Clothing";
    }
    if (c == ProductCategory::Electronics)
    {
        return "Electronics";
    }
    if (c == ProductCategory::Furniture)
    {
        return "Furniture";
    }
    if (c == ProductCategory::Games)
    {
        return "Games";
    }
    if (c == ProductCategory::Jewelry)
    {
        return "Jewelry";
    }
    if (c == ProductCategory::Other)
    {
        return "Other";
    }
    else
    {
        return "Invalid Product Category Type.";
    }
}

// takes values from productBid.csv and populates the products array
void Driver::setInitialProducts()
{
    ifstream inFile("productBid.csv");
    string data;

    if (!inFile.is_open())
    {
        cout << "Cannot initialize products." << endl;
        return;
    }

    while (getline(inFile, data))
    {
        vector<string> productData;
        stringstream s(data);
        string datas;

        while (getline(s, datas, ','))
        {
            productData.push_back(datas);

            Product product = new Product(productData[0], stringToCategory(productData[1]), productData[2], stod(productData[3]), stod(productData[4]));
            onSaleProds[productData[1]] = product;
        }
    }
    inFile.close();
}

// takes values from  the userInfo.csv and populates the users array
void Driver::setInitialUsers()
{
    ifstream inFile("userInfo.csv");
    string data;
    if (!inFile.is_open())
    {
        cerr << "Error: Cannot open file." << endl;
        return;
    }
    while (getline(inFile, data))
    {
        vector<string> userInfo;
        stringstream s(data);
        string datas;

        // sepearates each element of line via comma
        while (getline(s, datas, ','))
        {
            userInfo.push_back(datas);
        }

        // make each line of csv files into User class
        User user = new User();
        // user.set
        users.push_back(user);
    }

    inFile.close();
}

void Driver::updateProductInformation(Product p)
{
    return;
}

void Driver::updateUserInformation(User b)
{
    return;
}

map<string, Product> Driver::getActiveProducts()
{
    return onSaleProds;
}
