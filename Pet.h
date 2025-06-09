// headers below:
#ifndef PET_H
#define PET_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Pet{
public:
	Pet();
	Pet(string n, string c); 
	Pet(string n, string c, int a, int h, int sl, int b, int ha) : name(n), color (c), actionsLeft(a), hungerVal(h), sleepyVal(sl), boredVal(b), happyVal(ha), hours(0){}

	string getName() const {return name;}
	void setName(string& n) {name = n;}
	string getColor() const {return color;}
	void setColor(string& c) {color = c;}
	int getActionsLeft() const {return actionsLeft; }
	void setActionsLeft(int a)  {actionsLeft = a;}
	int getHours() const {return hours;}
	void setHours(int h) {hours = h;}
	int getHungerVal() const {return hungerVal;} 
	void setHungerVal(int v) {hungerVal = v;}
	int getSleepyVal() const {return sleepyVal;}
	void setSleepyVal(int v) {sleepyVal = v;}
	int getBoredVal() const {return boredVal;}
	void setBoredVal(int v) {boredVal = v;}
	int getHappyVal() const {return happyVal;}
	void setHappyVal(int v) {happyVal = v;}

	bool isHungry() const {return hungerVal < 60; } 
	bool isSleepy() const {return sleepyVal < 60; }
	bool isBored() const {return boredVal < 60; }
	bool isHappy() const {return happyVal > 40; }

	virtual void feed();
	virtual void play();
	virtual void sleep();
	virtual void train();
	virtual void cuddle();

	void actionUse() {actionsLeft--;}

	virtual void nextHour();
	
	virtual string getType() const {return "Pet";}
	virtual bool save(const string& filename) {
		ofstream file(filename);
		if(!file.is_open()) return false;

		file << getType() << ","
				 << name << ","
				 << color << ","
				 << actionsLeft << ","
				 << hungerVal << "," 
				 << sleepyVal << ","
				 << boredVal << ","
				 << happyVal << ","
				 << hours;
		return true;
	}

	virtual void drawPet() = 0;
	
	virtual bool load(const string& filename)  {
		ifstream file(filename);
		if (!file.is_open()) return false;

		string type;
		getline(file, type, ',');
		if (type != getType()) return false;

		getline(file, name, ',');
		getline(file, color, ',');

		string val;
		getline(file, val, ','); actionsLeft = stoi(val);
		getline(file, val, ','); hungerVal = stoi(val);
		getline(file, val, ','); sleepyVal = stoi(val);
		getline(file, val, ','); boredVal = stoi(val);
		getline(file, val, ','); happyVal = stoi(val);
		getline(file, val, ','); hours = stoi(val);

		return true;
	}
 	virtual void displayStats();
private:
	string name;
	string color;

	int hungerVal;
	int sleepyVal;
	int boredVal;
	int happyVal;

	int actionsLeft;
	int hours;
};

#endif 
