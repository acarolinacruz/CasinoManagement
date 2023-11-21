#ifndef NUMBERGUESSING_H
#define NUMBERGUESSING_H
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void rules();

class NUMBERGUESSING {
	// attributes
	int id;
	string name;
	int amnt;
	int bidamnt;
	int guess;
	int dice;
	char choice;

protected:
public:
	NUMBERGUESSING(); // construtor
	// NUMBERGUESSING(string pName, int pAmnt, int pBidamnt, int pGuess, int
	// pDice, char pChoice);
	~NUMBERGUESSING(); // destrutor
	// gets e sets
	int GetId();
	void SetId();
	string GetName();
	void SetName(string pName);
	int GetAmnt();
	void SetAmnt(int pAmnt);
	int GetBidamnt();
	void SetBidamnt(int pBidamnt);
	int GetGuess();
	void SetGuess(int pGuess);
	int GetDice();
	void SetDice(int pDice);
	char GetChoice();
	void SetChoice(char pChoice);
	// functions to be called in main
	void Show();
	void rules();
};

#endif