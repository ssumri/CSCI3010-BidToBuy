#include <vector>
#include <string>
#include <iostream>

#include "Product.h"
#include "User.h"

using namespace std;

class Driver
{
public:
    Driver();
    void setInitialProducts();
    void setInitialUsers();

    void updateProductInformation(Product p);
    void updateUserInformation(User b);

private:
    vector<Seller> sellers;
    vector<Buyer> buyers;
    vector<User> users;

    vector<Product> allProducts;
    vector<Product> activeProducts;
};