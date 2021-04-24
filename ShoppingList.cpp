#include "ShoppingList.h"

#include <utility>

Shopping_List::Shopping_List(string name, int element_quantity) { //konstruktor lisyZakupów
    this->name = std::move(name);
    this->element_quantity = element_quantity;
}

Shopping_List::Shopping_List(const Shopping_List &list) {     //konstruktor kopiujący
    this->name = list.name;
    this->element_quantity = list.element_quantity;
    this->product_tab = list.product_tab;
}

const string &Shopping_List::getName() const {
    return name;
}

void Shopping_List::setName(const string &name) {
    Shopping_List::name = name;
}

int Shopping_List::getElementQuantity() const {
    return element_quantity;
}

void Shopping_List::setElementQuantity(int elementQuantity) {
    element_quantity = elementQuantity;
}

Product **Shopping_List::getProductTab() const {
    return product_tab;
}

Shopping_List::~Shopping_List() {

}

void Shopping_List::add_element() {        //dodanie produktu do listy
    int element_quantity = getElementQuantity();       //ilość już obecnych produktów w liście
    if (element_quantity == 10) {               //zabezpieczenie
        throw std::length_error("Przekroczona ilosc elementow w liscie");
    }
    cout << "Jaki typ produktu chcesz dodac? Wybierz numer: " << endl;
    cout << "1. Produkt na wage." << endl;
    cout << "2. Produkt na sztuki." << endl;
    cout << "3. Produkt na litry." << endl;

    int choice = int_read();                        //wczytujemy numer czynnosci

    while (choice <= 0 || choice > 3) {
        cout << "Nie ma takiej mozliwosci, wybierz jeszce raz" << endl;
        choice = int_read();                        //wczytujemy numer czynnosci
    }

    cout << "Podaj nazwe produktu, ktory chcesz dodac i wcisnij enter: " << endl;
    string name = string_read();                //wczytanie nazwy produktu

    //utworzenie produktow w zaleznosci od typu produktu - waga, ilosc, objetosc
    switch (choice) {
        case 1: {
            cout << "Podaj wage tych produktow w dekagramach: ";
            //wczytanie ilości sztuk produktu
            double quantity_product = int_read();

            Weight *product = new Weight(name, quantity_product);
            getProductTab()[element_quantity] = product;
            break;
        }
        case 2: {
            cout << "Podaj ilosc tych produktow: ";
            //wczytanie ilości sztuk produktu
            int quantity_product = int_read();

            Quantity *product = new Quantity(name, quantity_product);
            getProductTab()[element_quantity] = product;
            break;
        }
        case 3: {
            cout << "Podaj objetosc tych produktow w mililitrach: ";
            //wczytanie ilości sztuk produktu
            int quantity_product = int_read();                        //wczytujemy numer czynnosci

            Liters *product = new Liters(name, quantity_product);
            getProductTab()[element_quantity] = product;
            break;
        }
    }
    setElementQuantity(element_quantity + 1);
}

void Shopping_List::write_all_elements() {
    if (getElementQuantity() == 0) {
        cout << "\t" << "Nie masz elementow na liscie \"" << getName() << "\"" << endl;
        return;
    }
    cout << "Twoje produkty z listy \"" << getName() << "\" to: " << endl;
    for (int i = 0; i < getElementQuantity(); i++) {       //wypisanie wszystkich produktów z listy
        cout << "\t" << i + 1 << ") ";
        getProductTab()[i]->print(getProductTab()[i]); //użycie funkcji klasy Product wypisującej
    }                                                            //nazwę i ilość produktu
}

Product *Shopping_List::delete_element(int index) {
    Product *product = getProductTab()[index];
    for (int i = index; i < getElementQuantity() - 1; i++) {
        getProductTab()[i] = getProductTab()[i + 1];
    }
    setElementQuantity(getElementQuantity() - 1);     //zmniejszenie ilości elementów w liście
    return product;
}

std::string string_read() {      //funkcja wczytująca string
    std::string word;
    getline(std::cin, word);
    return word;
}

int int_read() {            //funkcja wczytujaca int
    std::string line;
    while (true) {
        try {
            getline(std::cin, line);
            for (int i = 0; i < line.size(); i++) {
                if (!isdigit(line[i])) {
                    throw std::invalid_argument("Podana wartosc nie jest liczba");
                }
            }
            break;
        }
        catch (std::logic_error &e) {
            cout << "Niepoprawny argument: " << e.what() << endl << "Musisz podac numer: " << std::endl;
        }
    }
    return atoi(line.c_str());
}
