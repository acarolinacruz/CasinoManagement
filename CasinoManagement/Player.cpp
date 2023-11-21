#include "Player.h"
#include <iostream>
#include <string>
using namespace std;
/*
PLAYER::PLAYER() { // construtor
  //cout << "Constructing the 'Player' object...\n";
}*/

PLAYER::PLAYER(int pId, string pName, string pCity, int pAge) {
    //cout << "Constructing the 'Player' object with parameters...\n";
    id = pId;
    name = pName;
    city = pCity;
    age = pAge;
}

PLAYER::PLAYER(string pName, int pAge) {
    id = 0;
    name = pName;
    city = "not identified";
    age = pAge;
}

PLAYER::~PLAYER() { }

// gets e sets
int PLAYER::GetId() { return id; }
void PLAYER::SetId(int pId) { id = pId; }
string PLAYER::GetName() { return name; }
void PLAYER::SetName(string pName) { name = pName; }
string PLAYER::GetCity() { return city; }
void PLAYER::SetCity(string pCity) { city = pCity; }
int PLAYER::GetAge() { return age; }
void PLAYER::SetAge(int pAge) {
    if (pAge < 0 || pAge > 130)
        cout << "Invalid age!!!" << endl;
    else
        age = pAge;
}
void PLAYER::Show() { // presents the player information
    cout << " # PLAYER #" << endl;
    cout << "Id: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "City: " << city << endl;
    cout << "Age: " << age << endl;
}
