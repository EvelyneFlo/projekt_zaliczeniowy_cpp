#include "Product.h"

using namespace std;

Product::Product(const string &productName, int productQuantity) {     //konstruktor
    this->product_name = productName;
    this->product_quantity = productQuantity;
}

const string &Product::getProductName() const {
    return product_name;
}

void Product::setProductName(const string &productName) {
    product_name = productName;
}

int Product::getProductQuantity() const {
    return product_quantity;
}

void Product::setProductQuantity(int productQuantity) {
    product_quantity = productQuantity;
}

void Product::print(Product *product) {     //funkcja wypisująca dane o produkcie
    cout << "\t" << product->getProductName() << "\t" << product->getProductQuantity() << endl;
}

