#include <iostream>
#include <iomanip>

using namespace std;

class Ice {
private:
    string Name;
    float Price;

public:
    Ice(string name, float price) : Name(name), Price(price) {};
    void ShowIce(void);


};

void Ice::ShowIce() {
    cout << Name+"\t" << "\t";
    cout << fixed << setprecision(2) << Price << " €" << endl;
}

class IceCreamParlor {
private:
    Ice i[3] = {{"Capri", 1.1}, {"Nogger", 1.6}, {"Cornetto", 2.3}};

public:
    static void sayHello();
    void showIceCard();
    void showMainMenu();
    static void placeOrder();
};

void IceCreamParlor::sayHello() {
    cout << "ICE++EIS++++++++++ICE++EIS+++++++++ICE++EIS" << endl;
    cout << "    Herzlich willkommen in der Eisbude" << endl;
    cout << "ICE++EIS++++++++++ICE++EIS+++++++++ICE++EIS" << endl;
}

void IceCreamParlor::showIceCard() {
    cout << "\n+++<3+++<3+++Unsere Eiskarte+++<3+++<3+++" << endl;
    for (auto & j : i) {
        j.ShowIce();
    }
    cout << "+++++<3+++<3++++++<3+++<3++++++<3+++<3++++" << endl;
}

void IceCreamParlor::placeOrder() {
    float credit;
    int choice=5;

    cout << "++++++++++Eisbestellung++++++++++" << endl;
    cout << "Bitte, Höhe des Guthabens eingeben (min 1.10)" << endl;

    do {
        cout << endl << "Ihr Guthaben:";
        cin >> credit;
        if(credit<1.1) {
            cout << "Sie müssen mindestens 1.10 eingeben" << endl;
        }
    } while (credit<1.1);

    
}

void IceCreamParlor::showMainMenu() {
    int choice=5;
    while(choice!=0) {
        cout << "----------MENÜ-----------" << endl;
        cout << "[1] Eisangebot zeigen" << endl;
        cout << "[2] Bestellung aufgeben" << endl;
        cout << "[0] Eisbude verlassen" << endl;
        cout << "--------------------------" << endl;
        cout << endl << "Ihre Auswahl:";
        cin >> choice;

        if (choice == 1) {
            showIceCard();
        } else if (choice == 2) {
            placeOrder();
        } else if (choice == 0) {
            cout << "<3 Danke für ihren Besuch <3" << endl;
            cout << "<3 Beehren Sie uns wieder  <3" << endl;
        } else {
            cout << "Eingabe war nicht korrekt" << endl;
        }
    }
}
int main() {
    IceCreamParlor ice;
    ice.sayHello();
    ice.showIceCard();
    ice.showMainMenu();
    return 0;
}
