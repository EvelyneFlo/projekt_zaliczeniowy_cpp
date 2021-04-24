#ifndef PROJEKT_LISTY_PRODUCTTYPES_H
#define PROJEKT_LISTY_PRODUCTTYPES_H

#include "Product.h"
#include "ShoppingList.h"


class Weight : public Product {   //klasa produktu na wage
public:
    Weight(const string &productName = nullptr, int productQuantity = -1);

    void print(Product *product);
};

class Quantity : public Product {     //klasa produktu na ilosc
public:
    Quantity(const string &productName = nullptr, int productQuantity = -1);

    void print(Product *product);
};

class Liters : public Product {       //klasa produktu na objetosc
public:
    Liters(const string &productName = nullptr, int productQuantity = -1);

    void print(Product *product);
};

#endif //PROJEKT_LISTY_PRODUCTTYPES_H
