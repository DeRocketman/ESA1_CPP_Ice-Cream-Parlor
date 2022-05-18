#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Ice {
private:
    int Number;
    string Name;
    float Price;

public:
    Ice(int Number, string name, float price) : Number(Number), Name(name), Price(price) {};
    void ShowIce(bool showWithNumber);

    int get_Number() {
        return Number;
    }

    float get_Price() {
        return Price;
    }


};

void Ice::ShowIce(bool ShowWithNumber) {
    if (ShowWithNumber) {
        cout << "(" << Number << ") ";
    }

    cout << Name+"\t" << "\t";
    cout << fixed << setprecision(2) << Price << " €" << endl;

}

class IceCreamParlor {
private:
    Ice i[3] = {{1, "Capri", 1.1}, {2, "Nogger", 1.6}, {3, "Cornetto", 2.3}};

public:
    static void sayHello();
    void showIceCard(bool ShowNumber);
    void showMainMenu();
    void placeOrder(bool ShowNumber);
};

void IceCreamParlor::sayHello() {
    cout << "ICE++EIS++++++++++ICE++EIS+++++++++ICE++EIS" << endl;
    cout << "    Herzlich willkommen in der Eisbude" << endl;
    cout << "ICE++EIS++++++++++ICE++EIS+++++++++ICE++EIS" << endl;
}

void IceCreamParlor::showIceCard(bool ShowNumber) {
    cout << "\n+++<3+++<3+++Unsere Eiskarte+++<3+++<3+++" << endl;
    for (auto & j : i) {
        j.ShowIce(ShowNumber);
    }
    cout << "+++++<3+++<3++++++<3+++<3++++++<3+++<3++++" << endl;
}

void IceCreamParlor::placeOrder(bool ShowNumber) {
    float credit;
    float sum = 0;
    int choice=4;
    vector<Ice> Order;


    cout << "++++++++++Eisbestellung++++++++++" << endl;
    cout << "Bitte, Höhe des Guthabens eingeben (min 1.10)" << endl;

    do {
        cout << endl << "Ihr Guthaben:";
        cin >> credit;
        if(credit<1.1) {
            cout << "Sie müssen mindestens 1.10 eingeben" << endl;
        }
    } while (credit<1.1);

    cout << "Vielen Dank" << endl;

    while (choice!=0 && choice !=5) {
        cout << "++++++++++Eisbestellung++++++++++" << endl;
        cout << "Ihr Guthaben: ";
        cout << fixed << setprecision(2) << credit << endl;
        for (auto & j : i) {
            j.ShowIce(ShowNumber);
        }
        cout << "---------------------------------" << endl;
        cout << "(5) bezahlen" << endl;
        cout << "(0) beenden und zum Hauptmenü zurück" << endl;
        cout << "---------------------------------" << endl;
        cout << endl << "Ihre Auswahl:";
        cin >> choice;

        if (choice == 0) {
            cout << "Bitte Geld entnehmen" << endl;
        } else if (choice >= 1 && choice <= 3) {
            for (auto & ice : i) {
                if (choice == ice.get_Number()) {
                    if(credit >= ice.get_Price()) {
                        Order.push_back(ice);
                        credit -= ice.get_Price();
                    } else if(ice.get_Number() == 1) {
                        cout << "Nicht mehr genug Guthaben für ein Eis" << endl;
                    } else {
                        cout << "Das Eis ist zu teuer. Bitte ein günstigeres als ";
                        cout << fixed << setprecision(2) << ice.get_Price() << " € ";
                        cout <<"wählen" << endl;
                    }
                }
            }
        } else if (choice == 5) {
            cout << "Ihre Bestellung wird abgeschlossen und eine Rechnung erstellt:" << endl;
            if (Order.empty()) {
                cout << "Sie haben nichts bestellt. Bitte Geld entnehmen" << endl;
                choice = 0;
            } else {
                for (int j = 0; j < Order.size(); j++) {
                    sum += Order[j].get_Price();
                    cout << j+1 << ": ";
                    Order[j].ShowIce(false);
                }
                cout << "------------------------" << endl;
                cout << "Gesamt:   ";
                cout << fixed << setprecision(2)<< sum << " €" << endl;
                cout << "Guthaben: ";
                cout << fixed << setprecision(2)<< credit+sum << " €" << endl;
                cout << "------------------------" << endl;
                cout << "Rest:     ";
                cout << fixed << setprecision(2)<<credit << " €" << endl;
            }
        } else {
            cout << "Ihre Eingabe war ungültig" << endl;
        }
    }
}

void IceCreamParlor::showMainMenu() {
    int choice=5;
    while (choice!=0) {
        cout << "----------MENÜ-----------" << endl;
        cout << "[1] Eisangebot zeigen" << endl;
        cout << "[2] Bestellung aufgeben" << endl;
        cout << "[0] Eisbude verlassen" << endl;
        cout << "--------------------------" << endl;
        cout << endl << "Ihre Auswahl:";
        cin >> choice;

        if (choice == 1) {
            showIceCard(false);
        } else if (choice == 2) {
            placeOrder(true);
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
    ice.showIceCard(false);
    ice.showMainMenu();
    return 0;
}
