#include <iostream>
#include <utility>
#include <fstream>
#include <vector>
#include <string>
#include "Product.h"
#include "ShoppingList.h"

using namespace std;


void add_list(std::vector<Shopping_List> &lists, string name);

void edit_list(std::vector<Shopping_List> &lists, int index);

void delete_list(std::vector<Shopping_List> &lists, int index);

void write_all_lists(const std::vector<Shopping_List> &lists);

void move_product(Shopping_List &list1, Shopping_List &list2, int index);

void merge_lists(std::vector<Shopping_List> &lists, int index1, int index2, const string &name);

int compare_strings(const string &first, const string &second);

int find_product(const string &name, Shopping_List &list);

int main(int argc, char *argv[]) {
    std::vector<Shopping_List> lists;                   //tu przechowywane są wszystkie listy

    std::ifstream plik;
    if(argc>=2){
        plik.open( argv[1]);
        std::cin.rdbuf(plik.rdbuf());
    }

    while (true) {
        cout << endl << endl << endl << "1. Dodaj liste" << endl;
        cout << "2. Wyswietl wszystkie listy" << endl;
        cout << "3. Dodaj element do listy" << endl;
        cout << "4. Edytuj liste" << endl;
        cout << "5. Przenies element miedzy listami" << endl;
        cout << "6. Wypisz zawartosc listy" << endl;
        cout << "7. Scal dwie listy" << endl;
        cout << "8. Usun liste" << endl;
        cout << "9. Zakoncz" << endl;
        cout << "Wybierz czynnosc, ktora chcesz wykonac: " << endl << endl;

        int number = int_read();                        //wczytujemy numer czynnosci
        switch (number) {
            case 1: {
                cout << "Podaj nazwe listy i wcisnij enter: ";
                string name = string_read();                        //wczytanie nazwy listy

                add_list(lists, name);                     //dodajemy listę do wektora
                break;
            }
            case 2: {
                try {
                    write_all_lists(lists);                 //wypisujemy wszystkie listy w wektorze
                }
                catch (std::logic_error &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: {
                try {
                    write_all_lists(lists);          //sprawdzamy czy istnieja listy
                    cout << "do ktorej listy chcesz dodac produkt - podaj numer: ";
                    int index = read_and_security("nie masz listy na tej pozycji", lists.size());
                    if (index == -1) {
                        break;
                    }
                    lists[index - 1].add_element();     //dodanie produktu do listy

                }
                catch (std::length_error &e) {
                    cout << "Error: " << e.what() << endl << endl;
                    write_all_lists(lists);
                    cout<<"Wybierz inna liste"<<endl;
                    int index = read_and_security("nie masz listy na tej pozycji", lists.size());
                    if (index == -1) {
                        break;
                    }
                    lists[index - 1].add_element();

                }
                catch (std::logic_error &e) {
                    cout << e.what() << endl;
                }

                break;
            }
            case 4: {
                try {
                    write_all_lists(lists);
                    cout << "ktora liste chcesz edytowac - podaj numer: ";
                    int index = read_and_security("nie masz listy na tej pozycji", lists.size());
                    if (index == -1) {
                        break;
                    }
                    index--;
                    edit_list(lists, index);               //edycja listy
                }
                catch (std::logic_error &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 5: {
                if (lists.size() > 1) {

                    write_all_lists(lists);
                    cout << "Z ktorej listy chcesz przeniesc produkt? - Podaj numer: " << endl;
                    int index1 = int_read();

                    if (lists[index1 - 1].getElementQuantity() > 0) {

                        lists[index1 - 1].write_all_elements();
                        cout << "Podaj numer produktu ktory chcesz przeniesc: ";
                        int index = read_and_security("nie ma takiego elementu na liscie",
                                                      lists[index1 - 1].getElementQuantity());
                        if (index == -1) {
                            break;
                        }

                        write_all_lists(lists);
                        cout << "Do ktorej listy chcesz przeniesc produkt? - Podaj numer: " << endl;
                        int index2 = int_read();

                        move_product(lists[index1 - 1], lists[index2 - 1], index - 1);
                    } else {
                        cout << "Nie masz zadnych produktow w tej liscie - dodaj najpierw elementy do listy" << endl;
                    }
                } else {
                    cout << "Zbyt mala ilosc list - dodaj najpierw liste " << endl;
                }
                break;
            }
            case 6: {
                try {
                    write_all_lists(lists);
                    cout << "ktora liste chcesz wyswietlic - podaj numer: ";
                    int index = read_and_security("nie masz listy na tej pozycji", lists.size());
                    if (index == -1) {
                        break;
                    }
                    lists[index - 1].write_all_elements();  //wypisanie produktów  z listy
                }
                catch (std::logic_error &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 7: {
                if (lists.size() > 1) {
                    write_all_lists(lists);
                    cout << "Ktore listy chcesz scalic? - Podaj numer pierwszej listy: " << endl;
                    int index1 = int_read();
                    while (index1 > lists.size() || index1 <= 0) {
                        cout << "Nie masz listy na tej pozycji - podaj numer jeszcze raz: " << endl;
                        index1 = int_read();
                    }
                    write_all_lists(lists);
                    cout << "Podaj numer drugiej listy: " << endl;
                    int index2 = int_read();

                    while (index2 > lists.size() || index2 <= 0 || index2 == index1) {
                        if (index2 == index1) {
                            cout << "Ta lista jest juz wybrana - wybierz inna: " << endl;
                        } else {
                            cout << "Nie masz listy na tej pozycji - podaj numer jeszcze raz: " << endl;
                        }
                        index2 = int_read();
                    }

                    cout << "Podaj nazwe nowej scalonej listy i wcisnij enter: ";
                    string name = string_read();                        //wczytanie nazwy listy

                    merge_lists(lists, index1 - 1, index2 - 1, name);

                } else {
                    cout << "Zbyt mala ilosc list, aby scalic - dodaj najpierw liste" << endl;
                }
                break;
            }
            case 8: {
                try {
                    write_all_lists(lists);
                    cout << "ktora liste chcesz usunac - podaj numer: ";
                    int index = read_and_security("nie masz listy na tej pozycji", lists.size());
                    if (index == -1) {
                        break;
                    }
                    index--;                                                //dopasowanie numerów list do ich pozycji w wektorze

                    delete_list(lists, index);         //usunięcie listy
                }
                catch (std::logic_error &e) {
                    cout << e.what() << endl;

                }
                break;
            }

            case 9: {
                for (int i = lists.size() - 1; i >= 0; i--) {              //zwalnianie pamieci
                    delete_list(lists, i);
                    //wyczyszczenie wektora
                }
                return 0;                   //zakończenie programu
            }


            default: {
                cout << "wybierz inny warunek" << endl;
            }
        }
    }

}

void add_list(std::vector<Shopping_List> &lists, string name) {
    lists.push_back(Shopping_List(std::move(name), 0));              //dodanie obiektu utworzonego poprzez konstruktor
}

void edit_list(std::vector<Shopping_List> &lists, int index) {
    cout << "1. Zmien nazwe listy" << endl;
    cout << "2. Usun produkt" << endl;
    cout << "3. edytuj nazwe elementu" << endl;
    cout << "4. edytuj ilosc elementu" << endl;

    cout << "Wybierz, co chcesz zrobic - podaj numer: " << endl;
    int number = int_read();                            //wczytanie numeru czynności
    switch (number) {
        case 1: {
            cout << "Podaj nowa nazwe listy: " << endl;
            string list_name = string_read();           //wczytanie nowej nazwy wybranej listy
            lists[index].setName(list_name);            //zmiana nazwy listy
            break;
        }
        case 2: {
            if (lists[index].getElementQuantity() == 0) {
                cout << "Nie masz produktow w tej liscie" << endl;
                break;
            }
            lists[index].write_all_elements();      //wypisanie wszystkich elementów listy
            cout << "ktory element chcesz usunac? - podaj numer: " << endl;
            int position = read_and_security("nie masz produktu na tej pozycji", lists[index].getElementQuantity());
            if (position == -1) {
                break;
            }
            lists[index].delete_element(position - 1);   //usunięcie elementu z wybranej
            break;                                                          //pozycji
        }
        case 3: {
            if (lists[index].getElementQuantity() == 0) {
                cout << "Nie masz produktow w tej liscie" << endl;
                break;
            }
            lists[index].write_all_elements();      //wypisanie wszystkich elementów listy
            cout << "Wybierz numer produktu: " << endl;
            int position = read_and_security("nie masz produktu na tej pozycji", lists[index].getElementQuantity());
            if (position == -1) {
                break;
            }
            cout << "Podaj nowa nazwe: " << endl;
            string new_name = string_read();                        //wczytanie nowej nazy produktu
            lists[index].getProductTab()[position - 1]->setProductName(new_name);   //zmiana nazwy produktu
            break;
        }
        case 4: {
            if (lists[index].getElementQuantity() == 0) {
                cout << "Nie masz produktow w tej liscie" << endl;
                break;
            }
            lists[index].write_all_elements();      //wypisanie wszystkich elementów
            cout << "Wybierz numer produktu: " << endl;
            int position = read_and_security("nie masz produktu na tej pozycji", lists[index].getElementQuantity());
            if (position == -1) {
                break;
            }
            cout << "Podaj nowa ilosc elementow: " << endl;

            int new_quantity = int_read();                          //wczytanie nowej ilości produktów
            lists[index].getProductTab()[position - 1]->setProductQuantity(new_quantity);   //zmiana ilości
            break;
        }
        default: {
            cout << "brak takiej mozliwosci" << endl;
        }
    }
}

void delete_list(std::vector<Shopping_List> &lists, int index) {
    for (int i = lists[index].getElementQuantity() - 1; i >= 0; i--) {
        delete lists[index].getProductTab()[i];            //usuwanie produktów w liście
        lists[index].setElementQuantity(lists[index].getElementQuantity() - 1);
    }
    delete[] lists[index].getProductTab();
    lists.erase(lists.begin() + index);                     //wyczyszczenie wektora na wybranej pozycji
}


void write_all_lists(const std::vector<Shopping_List> &lists) {
    int result = print(lists, lists.size());//, "Nie masz zadnych list");
    if (result) {
        throw std::logic_error("Nie masz zadnych list - dodaj najpierw liste");
    }
}

void move_product(Shopping_List &list1, Shopping_List &list2, int index) {
    if (list2.getElementQuantity() >= 10) {
        cout << "Nie mozesz przeniesc tu elementu - lista pelna" << endl;
    }

    list2.getProductTab()[list2.getElementQuantity()] = list1.delete_element(index);
    list2.setElementQuantity(list2.getElementQuantity() + 1);
}

int compare_strings(const string &first, const string &second) {
    if (first == second)
        return 1;
    return 0;
}

int find_product(const string &name, Shopping_List &list) {
    for (int i = 0; i < list.getElementQuantity(); i++) {
        if (compare_strings(name, list.getProductTab()[i]->getProductName())) {
            return i;
        }
    }
    return -1;
}

void merge_lists(std::vector<Shopping_List> &lists, int index1, int index2, const string &name) {
    int new_quantity = lists[index1].getElementQuantity();

    for (int i = 0; i < lists[index2].getElementQuantity(); i++) {
        if (find_product(lists[index2].getProductTab()[i]->getProductName(), lists[index1]) == -1) {
            new_quantity++;
        }
        if (new_quantity >= 10) {
            cout << "Nie mozna zlaczyc list - za duzo elementow " << endl;
            return;
        }
    }

    //przenosimy produkty z listy2 do listy1
    for (int i = lists[index2].getElementQuantity() - 1; i >= 0; i--) {
        int position = find_product(lists[index2].getProductTab()[i]->getProductName(), lists[index1]);
        if (position == -1) {
            move_product(lists[index2], lists[index1], i);
        } else {
            lists[index1].getProductTab()[position]->setProductQuantity(
                    lists[index1].getProductTab()[position]->getProductQuantity() +
                    lists[index2].getProductTab()[i]->getProductQuantity());
        }
    }
    //zmieniamy nazwe listy1 na nazwe scalonej listy
    lists[index1].setName(name);
    //usuwamy zbedna liste
    lists.erase(lists.begin() + index2);
}