#ifndef PROJEKT_LISTY_PRODUCT_H
#define PROJEKT_LISTY_PRODUCT_H

#include <string>
#include <iostream>

using namespace std;

class Product {
    string product_name;
    int product_quantity;
public:
    explicit Product(const string &productName = nullptr, int productQuantity = -1);

    const string &getProductName() const;

    void setProductName(const string &productName);

    int getProductQuantity() const;

    void setProductQuantity(int productQuantity);

    void virtual print(Product *product);
};

#endif //PROJEKT_LISTY_PRODUCT_H
