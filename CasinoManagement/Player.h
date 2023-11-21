#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <map>
#include <list>


using namespace std;

class  PLAYER {
private: // attributes
	int id;
	string name;
	string city;
	int age;
protected:
public:
	// PLAYER();// construtor
	PLAYER(int pId, string pName, string pCity, int pAge);
	PLAYER(string, int);
	~PLAYER();// destrutor
  //Creating a player object 
	PLAYER* objPlayer = new PLAYER( id,  name,  city,  age);
	// gets e sets
	int GetId();
	void SetId(int pId);
	string GetName();
	void SetName(string pName);
	string GetCity();
	void SetCity(string pCity);
	int GetAge();
	void SetAge(int pAge);
	void Show(); // presents information about the player
};



#endif