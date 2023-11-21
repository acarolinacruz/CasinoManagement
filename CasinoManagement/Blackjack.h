#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>

// Declare namespace
using namespace std;

class BLACKJACK {
	// attributes
	// Declare global Variables

	int id;
	int topCard = 0;
	float win = 1.00;
	int level;

	// Prototype functions.
	int getRandomNumber(int low, int high);
	int CardValue(int card);
	int getTopCard(int deck[]);
	int getHandValue(const int hand[]);
	bool playAnotherHand(char&);
	bool userWantsToDraw(char&);
	void initializeDeck(int deck[]);
	void dumpDeck(int deck[], int size);
	void shuffle(int deck[], int size);
	void ShowCard(int card);
	void showCards(const int cards[], int numCards, bool hideFirstCard);
	void whoWins(const int pHand[], const int dHand[]);
	void checkBust(const int pHand[], const int dHand[], char Play);
	void blackJack(const int pHand[], const int dHand[], char Play);
	void naturalBlackJack(const int pHand[], const int dHand[], char Play);
	void scoreBoard(const int pHand[], const int dHand[]);
	void backdoorKenny(const int hand[]);
	void checkSoftOrHard(int pHand[]);
	void softOrHardAI(int dHand[], int pHand[]);
	void addToHand(int hand[], int cardToAdd);
	void hitUntilStand(int dHand[], int deck[], int pHand[]);
	void drawLine(int n, char symbol);

protected:
public:
	BLACKJACK(); // construtor
	// BLACKJACK(int pTopCard, float pWin);//, int pLevel);
	~BLACKJACK(); // destrutor
	// gets e sets
	int GetId();
	void SetId();
	int GetTopCard();
	void SetTopCard(int pTopCard);
	float GetWin();
	void SetWin(float pWin);
	int GetLevel();
	void SetLevel(int pLevel);
	// functions to be called in main
	void showRules();
	void chooseLevelOfDificulty();
	void playOneHand();
};

#endif