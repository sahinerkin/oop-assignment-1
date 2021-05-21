// Erkin Şahin - 150170025

#ifndef ORDERLIST_H
#define ORDERLIST_H
using namespace std;

class OrderList {
        int n;
        Order* head;
    public:
        OrderList();

        void takeOrder();
        void listOrders();
        void deliverOrders();
};

OrderList::OrderList() {
    n = 0;
    head = NULL;
}


void OrderList::takeOrder() {
    int pizza_type;
    string size;
    string crust_type;

    int pizza_amount;
    
    cout << "Pizza Menu" << endl;
    cout << "1. Chicken Pizza (mozarella, chicken, mushroom, corn, olive, onion, tomato)" << endl;
    cout << "2. Broccoli Pizza (mozarella, broccoli, pepperoni, olive, corn, onion)" << endl;
    cout << "3. Sausage Pizza (mozarella, sausage, tomato, olive, mushroom, corn)" << endl;
    cout << "0. Back to main menu" << endl;

    cin >> pizza_type;
    while(pizza_type < 0 || pizza_type > 3) {
        cout << "Invalid choice." << endl;
        cin >> pizza_type;
    }


    cout << "Select size: small (15 TL), medium (20 TL), big (25 TL)" << endl;
    
    cin >> size;
    while(size.compare("small") && size.compare("medium") && size.compare("big")) {
        cout << "Invalid choice." << endl;
        cin >> size;
    }


    cout << "Select crust type: thin, normal, thick" << endl;
    
    cin >> crust_type;
    while(crust_type.compare("thin") && crust_type.compare("normal") && crust_type.compare("thick")) {
        cout << "Invalid choice." << endl;
        cin >> crust_type;
    }


    cout << "Enter the amount: ";
    
    cin >> pizza_amount;
    while(pizza_amount < 1) {
        cout << "Invalid amount." << endl;
        cin >> pizza_amount;
    }

    cout << endl;

    Pizza* pizzas = new Pizza[pizza_amount];
    Pizza first_pizza(size, crust_type, pizza_type);
    pizzas[0] =  first_pizza;

    for(int i = 0; i < pizza_amount-1; i++) {
        Pizza extra_pizza(first_pizza);
        pizzas[i+1] = extra_pizza;
    }


    cout << "Please choose a drink:" << endl;
    cout << "0. No drink" << endl;
    cout << "1. Cola (4 TL)" << endl;
    cout << "2. Soda (2 TL)" << endl;
    cout << "3. Ice Tea (3 TL)" << endl;
    cout << "4. Juice (3.5 TL)" << endl;
    cout << "Type -1 to save your order." << endl;

    int drink_choice;
    int no_drinks[4] = {0, 0, 0, 0};

    while (true) {
        cin >> drink_choice;
        
        while(drink_choice < -1 || drink_choice > 4) {
            cout << "Invalid choice." << endl;
            cin >> drink_choice;
        }

        switch (drink_choice) {
            case 1:
                no_drinks[0]++;
                break;
            case 2:
                no_drinks[1]++;
                break;
            case 3:
                no_drinks[2]++;
                break;
            case 4:
                no_drinks[3]++;
                break;
            default:
                break;
        }

        if(drink_choice == 0) {
            no_drinks[0] = 0;
            no_drinks[1] = 0;
            no_drinks[2] = 0;
            no_drinks[3] = 0;
            break;
        } else if (drink_choice == -1) break;
    }

    cout << "Please enter your name:" << endl;

    string name;
    cin >> name;

    Order* new_order = new Order(name, pizzas, pizza_amount, no_drinks);
    
    if(!head) {
        head = new_order;
    } else {
        Order* traverse = head;
        while(traverse->next) traverse = traverse->next;
        traverse->next = new_order;
    }

    n++;

    cout << endl;
    cout << "Your order is saved, it will be delivered when it is ready..." << endl;
    new_order->printOrder();
}


void OrderList::listOrders() {
    if(!head) {
        cout << "The list is empty." << endl;
        return;
    }

    Order* traverse = head;
    for(int item_num = 1; traverse; item_num++) {
        cout << item_num << endl;
        traverse->printOrder();
        traverse = traverse->next;
    }  
}

void OrderList::deliverOrders() {
    if(!head) {
        cout << "No orders." << endl;
        return;
    }

    listOrders();

    cout << "Please write the customer name in order to deliver his/her order: ";
    
    string name;
    cin >> name;
    
    if(head->customer.compare(name) == 0) {
        cout << "Following order is delivering..." << endl;
        head->printOrder();
        cout << "Total price: " << head->getPrice() << endl;
                
        string entered_code = "-";
        string promo_code = "I am a student";
        char has_promo_code = '-';
        while(has_promo_code != 'n' || entered_code.compare(promo_code) != 0) {
            cout << "Do you have a promotion code? (y/n)" << endl;
            cin >> has_promo_code;

            if(has_promo_code != 'n' && has_promo_code != 'y') continue;

            if(has_promo_code == 'y') {
                cout << "Please enter your code: ";
                cin >> entered_code;
                if(entered_code.compare(promo_code) == 0) {
                    cout << "Discounted price: " << (head->getPrice() * 0.9) << endl;
                } else {
                    cout << "Promotion code is not accepted." << endl;
                }
            } else break;
        }
        cout << "The order is delivered succesfully!" << endl;
        
        Order* temp = head->next;
        delete head;
        head = temp;
    }
    else {
        bool found = false;
        Order* traverse = head;
        while(traverse->next) {
            if(traverse->next->customer.compare(name) == 0){
                found = true;
                cout << "Following order is delivering..." << endl;
                traverse->next->printOrder();
                cout << "Total price: " << traverse->next->getPrice() << endl;
                
                string entered_code = "";
                string promo_code = "I am a student";
                char has_promo_code = '-';
                while(has_promo_code != 'n' || entered_code.compare(promo_code) != 0) {
                    cout << "Do you have a promotion code? (y/n)" << endl;
                    cin >> has_promo_code;

                    if(has_promo_code != 'n' || has_promo_code != 'y') continue;

                    if(has_promo_code == 'y') {
                        cout << "Please enter your code: ";
                        cin >> entered_code;
                        cout << endl;
                        if(entered_code.compare(promo_code) == 0) {
                            cout << "Discounted price: " << (traverse->next->getPrice() * 0.9) << endl;
                        } else cout << "Promotion code is not accepted." << endl;
                    } else break;
                }
                cout << "The order is delivered succesfully!" << endl;

                Order* temp = traverse->next;
                traverse->next = traverse->next->next;
                delete temp;
                break;

            } else traverse = traverse->next;
        }
        if(!found) cout << "Wrong name." << endl;
    }
}

#endif