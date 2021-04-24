#ifndef FLORCZAKEWELINA_ETAP3_TEMPLATES_H
#define FLORCZAKEWELINA_ETAP3_TEMPLATES_H

#include <string>
#include <iostream>
#include "ShoppingList.h"

template<typename T1>
int print(T1 elements, int size) {//, std::string warning) {
    if (size == 0) {
        // cout << warning << endl;
        return 1;
    }
    for (int i = 0; i < size; i++) {
        cout << "\t" << i + 1 << ") " << elements[i].getName() << endl;
    }
    return 0;
}

template<typename T2>
int read_and_security(T2 warning, int element_quantity) {
    int position = int_read();

    if (position > element_quantity || position <= 0) {
        cout << warning << endl;
        return -1;
    }
    return position;
}


#endif //FLORCZAKEWELINA_ETAP3_TEMPLATES_H
