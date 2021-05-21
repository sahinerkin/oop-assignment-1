/*
    Erkin Şahin
    150170025
*/

#ifndef ORDER_H
#define ORDER_H
using namespace std;

class Order {
        string customer;
        Pizza* pizza;
        int no_pizzas;
        int no_drinks[4];
        
        Order* next;

        friend class OrderList;
    public:
        Order(string, Pizza*, int, int*);
        
        float getPrice();
        void printOrder();
};


Order::Order(string customer_name, Pizza* pizza, int no_pizzas, int no_drinks[4]) {
    customer = customer_name;
    this->pizza = pizza;
    this->no_pizzas = no_pizzas;
    for(int i = 0; i < 4; i++) {
        this->no_drinks[i] = no_drinks[i];
    }

    this->next = NULL;
}

float Order::getPrice() {
    
    float total = 0;

    for(int i = 0; i < no_pizzas; i++) {
        if(pizza[i].size.compare("small") == 0) {
            total += 15;
        } else if(pizza[i].size.compare("medium") == 0) {
            total += 20;
        } else if(pizza[i].size.compare("big") == 0) {
            total += 25;
        }
    }

    total += no_drinks[0] * 4;
    total += no_drinks[1] * 2;
    total += no_drinks[2] * 3;
    total += no_drinks[3] * 3.5;

    return total;
}

void Order::printOrder() {
    cout << "------------" << endl;
    cout << "Name: " << customer << endl << endl;

    
    for(int i = 0; i < no_pizzas; i++) {
        
        cout << pizza[i].name << "(";

        for(int j = 0; pizza[i].ingredients[j].compare("."); j++) {
            if(!pizza[i].ingredients[j].compare("-")) continue;
            cout << pizza[i].ingredients[j] << ", ";
        }

        cout << ")" << endl;
        cout << "size: " << pizza[i].size << ", crust: " << pizza[i].crust_type << endl << endl; 
    }
    
    
    if (no_drinks[0] != 0) cout << no_drinks[0] << " cola, ";
    if (no_drinks[1] != 0) cout << no_drinks[1] << " soda, ";
    if (no_drinks[2] != 0) cout << no_drinks[2] << " ice tea, ";
    if (no_drinks[3] != 0) cout << no_drinks[3] << " fruit juice, ";

    cout << endl;
    cout << "------------" << endl;
}

#endif