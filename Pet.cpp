#include "Pet.h"

using namespace std;

Pet::Pet() : name("Unknown"), color("Unknown"),
            actionsLeft(3),
            hungerVal(100), sleepyVal(100),
            boredVal(100), happyVal(100), hours(0)  {}

Pet::Pet(string n, string c) : name(n), color(c), 
            actionsLeft(3), 
            hungerVal(100), sleepyVal(100),
            boredVal(100), happyVal(100), hours(0) {}

void Pet::nextHour(){
    hungerVal = max(hungerVal - 5, 0);
    sleepyVal = max(sleepyVal - 7, 0);
    boredVal = max(boredVal - 5, 0);
    happyVal = max(happyVal - 5, 0);
    
    if(isHungry()){
        cout << name << " is getting hungry! (Fullness: " << hungerVal << "/100)" << endl;
    }
    if(isSleepy()){
        cout << name << " is getting sleepy! (Alertness: " << sleepyVal << "/100)" << endl;
    }
    if(isBored()){
        cout << name << " is getting bored! (Engagement: " << boredVal << "/100)" << endl;
    }
    if(!isHappy()){
        cout << name << " isn't very happy! (Happiness: " << happyVal << "/100)" << endl;
    }
    hours++;
}

void Pet::feed(){
    cout << name << " was fed! " << name << " feels more full, but a little more sleepy..." << endl;
    hungerVal = min(hungerVal + 20, 100);
    sleepyVal = max(sleepyVal - 10, 0);
}

void Pet::play(){
    cout << name << " played! " << name << " feels more engaged and happy, but a bit more tired..." << endl;
    happyVal = min(happyVal + 20, 100);
    boredVal = min(boredVal + 20, 100);
    sleepyVal = max(sleepyVal - 20, 0);
}

void Pet::sleep(){
    cout << name << " slept! " << name << " feels more awake, but a little more bored and hungry..." << endl;
    sleepyVal = min(sleepyVal + 30, 100);
    boredVal = max(boredVal - 10, 0);
    hungerVal = max(hungerVal - 10, 0);
}

void Pet::train(){
    cout << name << " trained! " << name << " feels more engaged but more tired and less happy..." << endl;
    boredVal = min(boredVal + 35, 100);
    sleepyVal = max(sleepyVal - 25, 0);
    happyVal = max(happyVal - 35, 0);
}

void Pet::cuddle(){
    cout << name << " was cuddled! " << name << " feels happier and more awake, but a little less engaged..." << endl;
    happyVal = min(happyVal + 40, 100);
    sleepyVal = min(sleepyVal + 40, 100);
    boredVal = max(boredVal - 30, 0);
}

void Pet::displayStats() {
    cout <<"||=================================||\n";
    cout <<"|| " << name <<  "'s STATUS (" << getType() << ") and is " << hours << " hour/s old.\n";
    cout <<"||=================================||\n";
    cout <<"|| Fullness:  |" << string(hungerVal/10, '+') << string(10 - hungerVal/10, ' ') << "| " << hungerVal << "/100\n";
    cout <<"|| Alertness: |" << string(sleepyVal/10, '+') << string(10 - sleepyVal/10, ' ') << "| " << sleepyVal << "/100\n";
    cout <<"|| Engagement:|" << string(boredVal/10, '+') << string(10 - boredVal/10, ' ') << "| " << boredVal << "/100\n";
    cout <<"|| Happiness: |" << string(happyVal/10, '+') << string(10 - happyVal/10, ' ') << "| " << happyVal << "/100\n";
}