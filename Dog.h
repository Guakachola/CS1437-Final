#ifndef DOG_H
#define DOG_H

#include "Pet.h"

class Dog : public Pet {
public:
    Dog() : Pet(), barkEnergy(100) {}
    Dog(string n, string c) : Pet(n, c), barkEnergy(100) {}
    Dog(string n, string c, int a, int h, int sl, int b, int ha) : Pet(n, c, a, h, sl, b, ha), barkEnergy(100) {}

    int getBarkEnergy() const { return barkEnergy; }
    void setBarkEnergy(int e) { barkEnergy = e; }

    void bark();
    void feed() override;
    void play() override;
    void nextHour() override;

    bool isEnergetic() const { return barkEnergy > 50; }

    string getType() const override { return "Dog"; }

    bool save(const string& filename) override;
    bool load(const string& filename) override;
    void displayStats() override;

    void drawPet() override{
        cout << "  / \\__\n"; 
        cout << " (    @\\___\n";
        cout << " /         O\n";
        cout << getName() << " the dog" << endl;
    }

private:
    int barkEnergy;
};

#endif