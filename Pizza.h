// Erkin Şahin - 150170025

#ifndef PIZZA_H
#define PIZZA_H
using namespace std;

class Pizza {
        string name;
        string size;
        string* ingredients;
        string crust_type;

        friend class Order;

    public:
        Pizza();
        Pizza(string, string, int);
        Pizza(Pizza&);
};

Pizza::Pizza() {
    name = "No Topping";
    size = "medium";
    crust_type = "normal";
    ingredients = new string[2] {"mozarella", "."};
}

Pizza::Pizza(string size, string crust_type, int pizza_type) {
    this->size = size;
    this->crust_type = crust_type;

    switch(pizza_type) {
        case 1: 
            name = "Chicken Pizza";
            ingredients = new string[8] {"mozarella", "chicken", "mushroom", "corn", "olive", "onion", "tomato", "."};
            break;
        case 2: 
            name = "Broccoli Pizza";
            ingredients = new string[7] {"mozarella", "broccoli", "pepperoni", "olive", "corn", "onion", "."};
            break;
        case 3: 
            name = "Sausage Pizza";
            ingredients = new string[7] {"mozarella", "sausage", "tomato", "olive", "mushroom", "corn", "."};
            break;
        default:
            name = "No Topping";
            ingredients = new string[2] {"mozarella", "."};
    }
}

Pizza::Pizza(Pizza& pizza) {
    name = pizza.name;
    size = pizza.size;
    crust_type = pizza.crust_type;

    cout << "Please enter the number of the ingredient you want to remove from your pizza." << endl;

    int i;
    int num = 1;

    for(i = 0; pizza.ingredients[i].compare("."); i++) {
        if(!pizza.ingredients[i].compare("-")) continue;
        cout << num << ". " << pizza.ingredients[i] << endl;
        num++;
    }

    cout << "Type 0 to save it." << endl;

    this->ingredients = new string[i+1];

    for(int j = 0; j<=i; j++) {
        this->ingredients[j] = pizza.ingredients[j];
    }

    while(true) {
        int selection;
        cin >> selection;

        if (selection == 0) break;
        if (selection < 0 || selection > i) {
            cout << "Invalid selection." << endl;
            continue;
        }
        this->ingredients[selection-1] = "-";
    }
}



#endif