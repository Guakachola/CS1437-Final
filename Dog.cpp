#include "Dog.h"
#include <iostream>
#include <fstream>

using namespace std;

void Dog::bark() {
    if (barkEnergy >= 10) {
        cout << getName() << " barks loudly! Woof woof!" << endl;
        barkEnergy -= 10;
        setBoredVal(min(getBoredVal() + 15, 100));
    } else {
        cout << getName() << " is too tired to bark." << endl;
    }
}

void Dog::feed() {
    Pet::feed();
    barkEnergy = min(barkEnergy + 30, 100);
    cout << getName() << " wags its tail happily!" << endl;
}

void Dog::play() {
    cout << getName() << " fetches a ball with enthusiasm!" << endl;
    setBoredVal(min(100, getBoredVal() + 30));
    setHappyVal(min(100, getHappyVal() + 25));
    setSleepyVal(max(0, getSleepyVal() - 20));
    barkEnergy = max(0, barkEnergy - 10);
}

void Dog::nextHour() {
    Pet::nextHour();
    barkEnergy = max(barkEnergy - 8, 0);

    setSleepyVal(max(getSleepyVal() - 12, 0));

    cout << getName() << " pants and wags tail as time passes...\n";
}

bool Dog::save(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) return false;

    file << getType() << ","
         << getName() << ","
         << getColor() << ","
         << getActionsLeft() << ","
         << getHungerVal() << ","
         << getSleepyVal() << ","
         << getBoredVal() << ","
         << getHappyVal() << ","
         << getHours() << ","
         << barkEnergy;
    return true;
}

bool Dog::load(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return false;

    string type;
    getline(file, type, ',');
    if (type != "Dog") return false;

    Pet::load(filename);

    string val;
    for (int i = 0; i < 9; i++) getline(file, val, ',');

    getline(file, val);
    barkEnergy = stoi(val);

    return true;
}

void Dog::displayStats() {
    Pet::displayStats();
    cout << "||=================================||\n";
    cout << "|| Bark Energy|" << string(barkEnergy/10, '^') << string(10 - barkEnergy/10, ' ') << "| " << barkEnergy << "/100\n";
    cout << "||=================================||\n";
}