#include "Pet.h"

class Dragon : public Pet{
public:
	Dragon() : Pet(), elixirVal(100) {}
	Dragon(string n, string c) : Pet(n, c), elixirVal(100) {}
	Dragon(string n, string c, int h, int sl, int b, int ha, int a) : Pet(n, c, h, sl, b, ha, a), elixirVal(100) {}

	int getElixirVal() const {return elixirVal;}
	void setElixirVal(int v) {elixirVal = v;}

	void cast();
	void feed();
	void nextHour();

	bool isEmpty() const {return elixirVal < 40;}

	string getType() const override { return "Dragon"; }

	bool save(const string& filename) override {
		ofstream file(filename);
		if(!file.is_open()) return false;

		file << getType() << ","
		<< getName() << ","
		<< getColor() << ","
		<< getActionsLeft() << ","
		<< getHungerVal() << ","
		<< getSleepyVal() << ","
		<< getBoredVal() << ","
		<< getHappyVal() << ","
		<< getHours() << ","
		<< elixirVal;
		return true;
	}
	bool load(const string& filename) override {
		ifstream file(filename);
		if (!file.is_open()) return false;

		string type;
		getline(file, type, ',');
		if (type != "Dragon") return false;

		Pet::load(filename);

		string val;
		for(int i = 0; i < 9; i++) getline(file, val, ',');

		getline(file, val);
		elixirVal = stoi(val);

		return true;
	}
	void displayStats() override {
		Pet::displayStats();
		cout <<"||=================================||\n";
		cout <<"|| Magick     |" << string(elixirVal/10, '*') << string(10 - elixirVal/10, ' ')<< "| " << elixirVal << "/100\n";
		cout <<"||=================================||\n";
	}
	void drawPet() override{
	cout <<" \\    /\n"
         <<" )\\__/(\n"
         <<"(_\\  /_)\n"
         <<" \\@  @/\n"
         <<" |\\../|\n"
         <<"  \\VV/\n";
		cout << getName() << " the dragon" << endl;
	}
private:
	int elixirVal;
	

};
