#include "Dragon.h"

void Dragon::cast(){
	if(elixirVal >= 20){
		cout << getName() << " shot lightining! " << getName() << " is having fun!" << endl;
		elixirVal -= 20;
		setHappyVal(min(getHappyVal() + 15, 100));
		setBoredVal(min(getBoredVal() + 20, 100));
	} else {
		cout << getName() << " does not have enough elixir to cast." << endl;
	}
	
}

void Dragon::feed(){
	Pet::feed();
	elixirVal = min(elixirVal + 20, 100);
	cout << "Magical energy restored!" << endl;
	
}

void Dragon::nextHour() {
	Pet::nextHour();
	elixirVal = max(elixirVal - 5, 0);
	setHungerVal(max(getHungerVal() - 10, 0));

	cout << getName() << "'s magical energy wanes slightly as time passes...\n";
}
