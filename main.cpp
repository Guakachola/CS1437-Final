#include <iostream>
#include "Dragon.h"
#include "Cat.h"
#include "Dog.h"
#include <cstdlib>
#include <fstream>
using namespace std;

void actionMenu(Pet* pet);
void cleanup(Pet* &pet){
	if (pet) {
		delete pet;
		pet = nullptr;
	}
}
Pet* createNewPet();
Pet* loadPet();

int main (){
	srand(time(0));
	bool running = true;
	Pet* pet = nullptr;

	while(running) {
		cout << "\n=== TAMAGOTCHI ==="
				<< "\n1. New Pet"
				<< "\n2. Load Pet"
				<< "\n3. Exit"
				<< "\nChoice: ";

			int choice;

			if (!(cin >> choice)) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input! Try again.\n";
				continue;
			}
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

			

			// if (cin.fail()) {
			// 	cin.clear();
			// 	cin.ignore(10000, '\n');
			// 	cout << "Invalid input!\n";
			// 	continue; // try again instead of quitting
			// }

			switch (choice) {
				case 1:
					pet = createNewPet();
					actionMenu(pet);
					delete pet;
					break;
				case 2:
					cleanup(pet);
					pet = loadPet();
					if (pet) actionMenu(pet);
					break;
				case 3:
					cleanup(pet);
					running = false;
					break;
				default: 
					cout << "Invalid input!\n";
					running = false;
					break;
			}
	}
	return 0;
}



Pet* createNewPet() {
	cout << "\n=== CHOSE PET TYPE ==="
				<<"\n1. Dragon"
				<<"\n2. Cat"
				<<"\n3. Dog"
				<<"\nChoice: ";

	int type;
	cin >> type;

	string name;
	string color;
	cout << "Enter pet name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter pet color: ";
	getline(cin, color);

	// Stat time
	Pet* pet = nullptr;

	switch (type) {
		case 1:
			pet = new Dragon(
					name,
					color,
					3,
					rand() % 30,
					rand() % 30,
					rand() % 30,
					70 + rand() % 31
				);
			break;
		case 2:
			pet = new Cat(
					name,
					color,
					3,
					rand() % 30,
					rand() % 30,
					rand() % 30,
					70 + rand() % 31
				);
			break;
		case 3:
			pet = new Dog(
					name,
					color,
					3,
					rand() % 30,
					rand() % 30,
					rand() % 30,
					70 + rand() % 31
				);
			break;
		case 4:
			cout << "Defaulting to Dragon\n";
			pet = new Dragon(name, "Red");
	}

	cout << "\nMeet your new pet " << pet->getName() << "!\n";
	return pet;
}

Pet* loadPet(){
	cout << "Enter save filename: \n";
	string filename; 
	cin >> filename;
	cin.ignore(); 

	ifstream file(filename);
	if (!file) {
		cout << "Error: File not found!\n";
		return nullptr;
	}

	//read from file
	string type;
	getline(file, type, ',');
	file.close();

	Pet* pet = nullptr;
	if (type == "Dragon") {
		pet = new Dragon();
	} else if(type == "Cat"){
		pet = new Cat();
	} else if(type == "Dog"){
		pet = new Dog();
	}

	else {
		cout << "Unknown pet type in save file!\n";
		return nullptr;
	}

	if(pet->load(filename)){
		cout << "Successfully loaded " << pet->getName() << "!\n";
		return pet;
	} else {
		cout << "Failed to load pet data!\n";
		delete pet;
		return nullptr;
	}
	

}

void actionMenu(Pet* pet){
	bool inMenu = true;
	string files; 
	while (inMenu) {
		cout << "\n=== " << pet->getName() << " ===\n"
			<< "||=================================||\n"
			<< "||                                 ||\n"
			<< "|| 1. Feed                         ||\n"
			<< "|| 2. Play                         ||\n"
			<< "|| 3. Sleep                        ||\n"
			<< "|| 4. Train                        ||\n"
			<< "|| 5. Cuddle                       ||\n";
		if(pet->getType() == "Dragon"){
			cout
			<< "|| 6. Cast Magick                  ||\n";
		}else if(pet->getType() == "Cat"){
			cout
			<< "|| 6. Purr                         ||\n";
		}else if(pet->getType() == "Dog"){
			cout
			<< "|| 6. Bark                         ||\n";
		}
		cout <<"|| 7. View Stats                   ||\n"
			<< "|| 8. Show Pet                     ||\n"
			<< "||                                 ||\n"
			<< "|| N. Next Hour                    ||\n"
			<< "|| S. Save & Quit                  ||\n"
			<< "|| Q. Quit Without Saving          ||\n"
			<< "||=================================||\n"
			<< "   Actions left: " << pet->getActionsLeft() << "\n"
			<< "Choice: ";

		char choice;
		cin >> choice;
		// check for the next hour
		if (pet->getActionsLeft() <= 0 && tolower(choice) != 'n' && tolower(choice) != 's' 
		&& tolower(choice) != 'q' && choice != '7' && choice != '8'){
			cout << "No actions left, you are exhausted. Choose 'N' to advance to the next hour.\n";
			cout << "\nPress Enter to continue...";
			cin.ignore();
			cin.get();
			continue;
			}

		switch (tolower(choice)) {
			case '1' : 
				pet->feed(); 
				pet->actionUse();
				break;
			case '2' : 
				pet->play();
				pet->actionUse();
				break;
			case '3' : 
				pet->sleep();
				pet->actionUse();
				break;
			case '4' : 
				pet->train(); 
				pet->actionUse();
				break;
			case '5' : 
				pet->cuddle(); 
				pet->actionUse();
				break;
			case '6' : 
				if (pet->getType() == "Dragon") {
					dynamic_cast<Dragon*>(pet)->cast();
				} else if(pet->getType() == "Cat") {
				dynamic_cast<Cat*>(pet)->purr();
				} else if(pet->getType() == "Dog") {
				dynamic_cast<Dog*>(pet)->bark();
				}else{
					cout << "Invalid choice for this pet type!\n";
				}
				pet->actionUse();
				break;
			case '7':
				pet->displayStats();
				break;
			case '8':
				pet->drawPet();
				break;
			case 'n':
				if (pet->getActionsLeft() < 3){
					cout << "\n=== Advancing to the next hour ===\n";
					pet->nextHour();
					pet->setActionsLeft(3); 
				}else{
					cout << "You haven't used any actions this hour!\n";
				}
				break;
			case 's' : 
				cout << "Enter save filename: \n";
				cin >> files;
				cin.ignore(); 
					if(pet->save(files)){
					cout << "Saved successfully!\n";
					} else {
						cout << "Save failed!\n";
					}
					inMenu = false;
					break;
			case 'q' :
				cout << "Exiting...\n";
				inMenu=false;
				break;
			default :
				cout << "Invlaid input!\n";
				break;
		}
		if (inMenu) {
			cout << "\nPress Enter to continue...";
			cin.ignore();
			cin.get();
		}
	}
}
