#ifndef PROJEKT_LISTY_SHOPPINGLIST_H
#define PROJEKT_LISTY_SHOPPINGLIST_H

#include "Product.h"
#include "ProductTypes.h"
#include "Templates.h"
#include <iostream>
#include <string>

using namespace std;

string string_read();

int int_read();

class Shopping_List {
    string name;
    Product **product_tab = new Product *[10];
    int element_quantity = 0;

public:
    Shopping_List(string name, int element_quantity);

    Shopping_List(const Shopping_List &list);

    const string &getName() const;

    void setName(const string &name);

    int getElementQuantity() const;

    void setElementQuantity(int elementQuantity);

    Product **getProductTab() const;

    ~Shopping_List();

    void add_element();

    Product *delete_element(int index);

    void write_all_elements();
};


#endif //PROJEKT_LISTY_SHOPPINGLIST_H
