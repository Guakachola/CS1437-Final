#ifndef CAT_H
#define CAT_H

#include "Pet.h"

class Cat : public Pet {
public:
    Cat() : Pet(), purrPower(50) {}
    Cat(string n, string c) : Pet(n, c), purrPower(50) {}
    Cat(string n, string c, int a,int h, int sl, int b, int ha) : Pet(n, c, a, h, sl, b, ha), purrPower(50) {}

    int getPurrPower() const { return purrPower; }
    void setPurrPower(int p) { purrPower = p; }

    void purr();
    void feed() override;
    void play() override;
    void cuddle() override;
    void nextHour() override;

    bool isContent() const { return purrPower > 30; }

    string getType() const override { return "Cat"; }

    bool save(const string& filename) override;
    bool load(const string& filename) override;
    void displayStats() override;

    void drawPet() override{
        cout << " /\\_/\\ " << endl;
        cout << "( o.o )" << endl;
        cout << " > ^ < " << endl;
        cout << getName() << " the cat" << endl;
    }

private:
    int purrPower;
};

#endif