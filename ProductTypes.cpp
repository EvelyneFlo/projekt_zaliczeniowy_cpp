#include "ProductTypes.h"

Quantity::Quantity(const string &productName, int productQuantity) : Product(productName, productQuantity) {}

void Quantity::print(Product *product) {
    cout << product->getProductName() << "\t" << product->getProductQuantity() << "szt" << endl;
}

Weight::Weight(const string &productName, int productQuantity) : Product(productName, productQuantity) {}

void Weight::print(Product *product) {
    cout << product->getProductName() << "\t" << product->getProductQuantity() << "dag" << endl;
}

Liters::Liters(const string &productName, int productQuantity) : Product(productName, productQuantity) {}

void Liters::print(Product *product) {
    cout << product->getProductName() << "\t" << product->getProductQuantity() << "ml" << endl;
}


