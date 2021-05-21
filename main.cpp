// Erkin Şahin - 150170025

#include <iostream>
#include "Pizza.h"
#include "Order.h"
#include "OrderList.h"


int main() {
    OrderList order_list;

    while(true) {
        cout << endl;
        cout << "Welcome to Unicorn Pizza!" << endl;
        cout << "1. Add an order" << endl;
        cout << "2. List orders" << endl;
        cout << "3. Deliver order" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose what to do: ";

        int selection;
        cin >> selection;

        while(selection < 1 || selection > 4){
            cout << "Invalid selection." << endl;
            cin >> selection;
        }

        if(selection == 4) {
            cout << "Goodbye..." << endl;
            break;
        }

        switch (selection) {
            case 1:
                order_list.takeOrder();
                break;
            case 2:
                order_list.listOrders();
                break;
            case 3:
                order_list.deliverOrders();
                break;
            default:
                cout << "Something went wrong." << endl;
                break;
        }
    }
}
