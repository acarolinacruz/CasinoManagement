#include "SlotMachine.h"
#include "Wheel.h"
#include <iostream>
using namespace std;

Wheel* wheels = new Wheel[3]; // Use dynamic allocation with the new keyword to allocate memory for 3 Wheel objects

SLOTMACHINE::SLOTMACHINE() {

    //wheels = new Wheel[3]; // Use dynamic allocation with the new keyword to allocate memory for 3 Wheel objects


    /*int credits = 0;
    int betAmount = 0;

    for (int i = 0; i < 3; i++) {
      wheels[i] = Wheel(); // Initialize each Wheel object
    }

    // Initialize the screen
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        screen[i][j] = 0;
      }
    }
    */
}

SLOTMACHINE::~SLOTMACHINE() {
    /*
    delete(wheels[0]);
    delete(wheels[1]);
    delete(wheels[2]);
    */
}


/**
 * @brief Pulls the lever to spin the reels and determine the outcome.
 *
 * This function generates three random numbers between 0 and 5 to represent the
 * symbols on each reel. It then checks if the player has won and adjusts the balance
 * accordingly.
 *
 * @return void
 */
 /*  void SLOTMACHINE::pullLever() {
       // Generate random numbers between 0 and 5 for each reel.
       int reel1 = rand() % 6;
       int reel2 = rand() % 6;
       int reel3 = rand() % 6;

       // Display the outcome.
       std::cout << "Reel 1: " << symbols[reel1] << std::endl;
       std::cout << "Reel 2: " << symbols[reel2] << std::endl;
       std::cout << "Reel 3: " << symbols[reel3] << std::endl;

       // Check if the player has won and adjust the balance accordingly.
       if (reel1 == reel2 && reel2 == reel3) {
           std::cout << "Congratulations! You won!" << std::endl;
           balance += 50;
       } else {
           std::cout << "Sorry, you lost." << std::endl;
           balance -= 10;
       }

       // Display the current balance.
       std::cout << "Current balance: " << balance << std::endl;
   }
*/








/*

SLOTMACHINE::SLOTMACHINE() {
  Wheel *wheels;
  int credits = 0;
  int betAmount = 0;

  wheels[0] = new Wheel();
  wheels[1] = new Wheel();
  wheels[2] = new Wheel();

  // Initialize screen
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      screen[i][j] = 0;
    }
  }
}
*/







/*
SLOTMACHINE::~SLOTMACHINE() {
  delete(wheels[0]);
  delete(wheels[1]);
  delete(wheels[2]);
}*/

// Spins the wheels and calls the loading of each wheel's results.
// Then calls to check for winnings.
void SLOTMACHINE::spin() {
    if (betAmount > 0) {
        wheels[0]->spin();
        wheels[1]->spin();
        wheels[2]->spin();

        int* column1 = wheels[0]->read();
        int* column2 = wheels[1]->read();
        int* column3 = wheels[2]->read();


        loadscreen(0, column1);
        loadscreen(1, column2);
        loadscreen(2, column3);

        printscreen();
        checkwinnings();

        betAmount = 0;


        delete[] column1;
        delete[] column2;
        delete[] column3;

        column1 = column2 = column3 = NULL;

    }
    else { cout << "Please make a bet before spinning." << endl; }
}

// Loads a wheel into the respective column of the screen
void SLOTMACHINE::loadscreen(int col, int* wheelcolumn) {
    for (int i = 0; i < 3; i++) {
        screen[i][col] = wheelcolumn[i];
    }
}

// Simply prints the screen
void SLOTMACHINE::printscreen() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
}

// Bet function takes the number of lines the user wants to bet on (3 horizontal, 2 diagonals)
// and checks if they have enough credits to bet that much.
void SLOTMACHINE::bet(int lines) {
    if ((lines < 1) || (lines > 5)) {
        cout << "You may only bet between 1 and 5 lines. Please try again." << endl;
    }
    else if ((credits - lines) < 0) {
        cout << "You have " << credits << " credits available. Try adding more money." << endl;
    }
    else {
        betAmount = lines;
        credits -= betAmount;
    }
}

// Adds a credit
void SLOTMACHINE::insertcoin() {
    credits++;

    cout << "You now have " << credits << " credits." << endl;
}

// Adds multiple credits based on the bill denomination.
void SLOTMACHINE::insertbill(double billAmount) {
    if ((billAmount >= 1.00) && (billAmount <= 20.00)) {
        int newcredits = (int)(billAmount / .25);
        credits += newcredits;

        cout << "You now have " << credits << " credits." << endl;
    }
}


// Checks lines for wins and adds credits earned.
void SLOTMACHINE::checkwinnings() {
    int lineValues[3];
    int winnings = 0;

    // Check line middle line
    if (betAmount >= 1) {
        for (int i = 0; i < 3; i++) {
            lineValues[i] = screen[1][i];
        }

        winnings += checkline(lineValues);
    }

    // Check line top line
    if (betAmount >= 2) {
        for (int i = 0; i < 3; i++) {
            lineValues[i] = screen[0][i];
        }

        winnings += checkline(lineValues);
    }

    // Check bottom line
    if (betAmount >= 3) {
        for (int i = 0; i < 3; i++) {
            lineValues[i] = screen[2][i];
        }

        winnings += checkline(lineValues);
    }

    // Check left to right diagonal
    if (betAmount >= 4) {
        for (int i = 0; i < 3; i++) {
            lineValues[i] = screen[i][i];
        }

        winnings += checkline(lineValues);
    }

    // Check right to left diagonal
    if (betAmount == 5) {
        for (int i = 2; i >= 0; i--) {
            lineValues[i] = screen[i][i];
        }

        winnings += checkline(lineValues);
    }

    if (winnings > 0) {
        cout << "You won " << winnings << " credits!" << endl;
        credits += winnings;
    }
    else {
        cout << "Sorry, you did not win anything." << endl;
    }

    cout << "You have " << credits << " credits left." << endl << endl;
}


// Determines the winning sequences. 
// 3 of a kind wins something
// Two cherries and something else wins as does two luckysevens and something else.
int SLOTMACHINE::checkline(int line[3]) {
    if (line[0] == this->luckyseven && line[1] == this->luckyseven && line[2] == this->luckyseven) { return 1000; }
    if (line[0] == this->watermelon && line[1] == this->watermelon && line[2] == this->watermelon) { return 800; }
    if (line[0] == this->triplebar && line[1] == this->triplebar && line[2] == this->triplebar) { return 600; }
    if (line[0] == this->doublebar && line[1] == this->doublebar && line[2] == this->doublebar) { return 500; }
    if (line[0] == this->bar && line[1] == this->bar && line[2] == this->bar) { return 400; }
    if (line[0] == this->cherry && line[1] == this->cherry && line[2] == this->cherry) { return 375; }
    if (line[0] == this->orange && line[1] == this->orange && line[2] == this->orange) { return 350; }
    if (line[0] == this->plum && line[1] == this->plum && line[2] == this->plum) { return 300; }
    if (line[0] == this->luckyseven && line[1] == this->luckyseven) { return 200; }
    if (line[0] == this->cherry && line[1] == this->cherry) { return 50; }
    if (line[0] == this->lemon && line[1] == this->lemon && line[2] == this->lemon) { return 5; }


    return 0;
}

//MACHINE SLOT 
void SLOTMACHINE::MachineSlot() {
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
    delete(slotmachine);

}
