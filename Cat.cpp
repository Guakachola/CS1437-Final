#include "Cat.h"
#include <iostream>
#include <fstream>

using namespace std;

void Cat::purr() {
    if (purrPower >= 15) {
        cout << getName() << " purrs loudly! " << getName() << " seems content." << endl;
        purrPower -= 15;
        setHappyVal(min(getHappyVal() + 20, 100));
        setBoredVal(min(getBoredVal() + 20, 100));
    } else {
        cout << getName() << " doesn't have enough energy to purr." << endl;
    }
}

void Cat::feed() {
    Pet::feed();
    purrPower = min(purrPower + 25, 100);
    cout << getName() << " licks its paws contentedly." << endl;
}
void Cat::cuddle() {
    Pet::cuddle();
    purrPower = min(purrPower + 25, 100);
    cout << getName() << " makes biscuits on your lap." << endl;
}
void Cat::play() {
    cout << getName() << " chases a toy mouse!" << endl;
    setBoredVal(min(100, getBoredVal() + 25));
    setHappyVal(min(100, getHappyVal() + 15));
    setSleepyVal(max(0, getSleepyVal() - 15));
    purrPower = max(0, purrPower - 10);
}

void Cat::nextHour() {
    Pet::nextHour();
    purrPower = max(purrPower - 5, 0);

    setBoredVal(max(getBoredVal() - 10, 0));

    cout << getName() << " stretches and looks around lazily as time passes...\n";
}

bool Cat::save(const string& filename) {
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
         << purrPower;
    return true;
}

bool Cat::load(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return false;

    string type;
    getline(file, type, ',');
    if (type != "Cat") return false;

    Pet::load(filename);

    string val;
    for (int i = 0; i < 9; i++) getline(file, val, ',');

    getline(file, val);
    purrPower = stoi(val);

    return true;
}

void Cat::displayStats() {
    Pet::displayStats();
    cout << "||=================================||\n";
    cout << "|| Purr Power |" << string(purrPower/10, '~') << string(10 - purrPower/10, ' ') << "| " << purrPower << "/100\n";
    cout << "||=================================||\n";
}