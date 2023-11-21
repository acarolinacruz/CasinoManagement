// CasinoManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Blackjack.h"
#include "Casino.h"
#include "NumberGuessing.h"
#include "Player.h"
#include "Roulette.h"
#include "SlotMachine.h"
#include "XMLWriter.h"
#include <cstdlib> // Needed to use random numbers
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string.h> // Needed to use strings

using namespace std;

void drawLine(int n, char symbol);
void rules();
string playerName;
int game;   // hold game selected
int amount; // hold player's balance amount

// change this machine slot !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// MACHINE SLOT
void MachineSlot() {
    // Create our slot machine
    SLOTMACHINE* slotmachine = new SLOTMACHINE();

    // Insert a five
    slotmachine->insertbill(5.00);

    // Plus a coin for good luck
    slotmachine->insertcoin();

    // Go for it all and bet five lines
    // Then spin!
    slotmachine->bet(5);
    slotmachine->spin();

    // Win or lose, lets bet five lines again
    // Then spin!
    slotmachine->bet(5);
    slotmachine->spin();

    // Ok, we had enough of the slot machine.
    delete (slotmachine);
}

int main() {

    BLACKJACK* B = new BLACKJACK();
    // SLOTMACHINE *s = new SLOTMACHINE();
    NUMBERGUESSING* NS = new NUMBERGUESSING();
    ROULETTE* RL = new ROULETTE();

    cout << "Welcome to the best Casino's game!\n";
    cout << "Are a registed player?!\n";

    PLAYER* P1 = new PLAYER(2, "rui", "viseu", 12);
    PLAYER* P2 = new PLAYER(3, "mauro", "lisboa", 27);
    PLAYER* P3 = new PLAYER(4, "maria", "porto", 21);

    P1->Show();
    P2->Show();
    P3->Show();

    // player name
    cout << "\n\nEnter Your Name : ";
    getline(cin, playerName);

    // how much will player deposite on game
    cout << "\n\nEnter Deposit amount to play game : $";
    cin >> amount;

    // selec the casino game
    cout << "\n\nWhich Casino Game do you wanna play?: ";
    cout << "\n\nGAME 1 : Slot Machine";
    cout << "\n\nGAME 2 : Number Guessing";
    cout << "\n\nGAME 3 : Blackjack";
    cout << "\n\nGAME 4 : Roulette";
    cout << "\n\nSelect a number: ";
    cin >> game;

    switch (game) {

    case 1:
        cout << "\nGAME 1 : Slot Machine\n";
        // s-> SlotMachineTrigger();
        void MachineSlot();
        break;
    case 2:
        cout << "\nGAME 2 : Number Guessing\n";
        // pointer that points to the number guessing class and
        // calls show() and rules() functions
        NS->Show();
        NS->rules();
        break;
    case 3:
        cout << "\nGAME 3 : Blackjack\n";
        B->showRules();
        B->chooseLevelOfDificulty();
        B->playOneHand();
        break;
    case 4:
        cout << "\nGAME 4 : Roulette\n";
        RL->RouletteTrigger();

        break;
    case 5:
        cout << "GAME 6 : Slot Machine";
        break;
    case 6:
        cout << "Saturday";
        break;
    case 7:
        cout << "Sunday";
        break;
    }

    /*
    //selec the casino game
     cout << "\n\nWhich Casino Game do you wanna play?: ";
     cout << "\n\nSelect a number between the 1 to 4: ";
     cin >> game;
     */

     /*
     PLAYER *P0 = new PLAYER();
     PLAYER *P1 = new PLAYER(2,"rui", "viseu", 12);
     PLAYER *P2 = new PLAYER(3,"mauro", "lisboa", 27);
     PLAYER *P3 = new PLAYER(4,"maria", "porto", 21);
     */
     /*
       P0->Show();
       P1->Show();
       P2->Show();
       P3->Show();

       delete P0;
       delete P1;
       delete P2;
       delete P3;
     */
     /*
       XMLWriter XX;
       XX.WriteStartDocument("FicheiroDados.xml");
       XX.WriteStartElement("DADOS");
       XX.WriteStartElement("PLAYER"); // Abre o Elemento “PESSOA”
       XX.WriteElementString("NAME","Carolina Cruz");
       XX.WriteElementString("AGE","24");
       XX.WriteEndElement(); // Fecha o Elemento “PESSOA”
       XX.WriteStartElement("PLAYER"); // Abre o Elemento “PESSOA”
       XX.WriteElementString("NAME","Jose Lopes");
       XX.WriteElementString("AGE","34");
       XX.WriteEndElement(); // Fecha o Elemento “PESSOA”
       XX.WriteStartElement("PLAYER"); // Abre o Elemento “PESSOA”
       XX.WriteElementString("NAME","Luis Caiado");
       XX.WriteElementString("AGE","27");
       XX.WriteEndElement(); // Fecha o Elemento “PESSOA”

       XX.WriteEndElement(); // Fecha o Elemento “DADOS”
       XX.WriteEndDocument(); // Fecha o Elemento Documento

     */

    CASINO* C = new CASINO("Casino Viseu");

    // C->ReadFile("dados.txt");
    // C->Show();
    cout << endl << "Machine more played: " << C->GetMachineMorePlayed() << endl;
    delete (C);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
