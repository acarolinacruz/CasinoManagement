#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H
#include "Wheel.h"
#include <iostream>    // Include the necessary headers for input-output stream functionality.
#include <cstdlib>     // Include for random number generation.
#include <ctime>       // Include for seeding the random number generator.


using namespace std;

/*
class SlotMachine : public MACHINE
{
    string type;
    public:
        SlotMachine(PLAYER *_tit, float _comi, float _saldo = 0);
        virtual ~SlotMachine();
        string QuemEs() { return "SlotMachine"; }
        void Show();
        int Memoria();
};
*/


// Class declaration for our slot machine.
class SLOTMACHINE {
public:
    enum Image {
        orange = 1,
        watermelon,
        luckyseven,
        lemon,
        bar,
        doublebar,
        triplebar,
        cherry,
        plum
    };

    int id;

    SLOTMACHINE();
    ~SLOTMACHINE();
    void spin();
    void bet(int);
    void insertcoin();
    void insertbill(double);
    void printscreen();
    void MachineSlot();


private:
    void loadscreen(int, int*);
    void checkwinnings();
    int checkline(int line[3]);
    int credits;
    int betAmount;
    int screen[3][3];

    Wheel* wheels[3];
};


/*
class SLOTMACHINE {
//attributes
int id;
string name;

protected:
public:
SLOTMACHINE();// construtor
  //NUMBERGUESSING(string pName, int pAmnt, int pBidamnt, int pGuess, int pDice, char pChoice);
  ~SLOTMACHINE();// Destructor
  // gets e sets
  int GetId();
  void SetId();
  string GetName();
  void SetName(string pName);
  // functions to be called in main
  void spin();
  void loadscreen(int col, int *wheelcolumn);
  void printscreen();
  void bet(int lines);
  void insertcoin();
  void insertbill(double billAmount);
  void checkwinnings();
  int checkline(int line[3]);
  void MachineSlot();
};

*/






























/**
 * @brief Represents a slot machine.
 *
 * The SlotMachine class simulates a simple slot machine with three reels. Each reel has
 * six symbols: cherry, lemon, orange, plum, bell, and seven. The player can pull the lever
 * to spin the reels and try to match three symbols to win.
 */
 /*
 class SLOTMACHINE {
 private:
     const std::string symbols[6] = {"cherry", "lemon", "orange", "plum", "bell", "seven"}; // Array of symbols.
     int balance;    // Player's balance.

 public:
 SLOTMACHINE() {
     balance = 100;
 }
 //SLOTMACHINE();// construtor
 //NUMBERGUESSING(string pName, int pAmnt, int pBidamnt, int pGuess, int pDice, char pChoice);
 ~SLOTMACHINE();// Destructor

     // @brief Constructs a SlotMachine object with an initial balance of 100.



     void pullLever();
 */
 /**
  * @brief Prompts the user to pull the lever and play the slot machine.
  *
  * The SlotMachineTrigger function serves as the entry point to the program. It interacts with the user
  * through the console, creates a SlotMachine object, and allows the user to pull the lever
  * to play the slot machine.
  *
  * @return int indicating the status of the program execution (0 for successful execution).
  */
  /*
  int SlotMachineTrigger() {
      srand(time(0)); // Seed the random number generator with the current time.

    SLOTMACHINE slotMachine; // Create a SlotMachine object.

      char choice; // Variable to hold user's choice.

      do {
          // Prompt user to pull the lever.
          std::cout << "Pull the lever? (y/n): ";
          std::cin >> choice;

          if (choice == 'y' || choice == 'Y') {
              slotMachine.pullLever(); // Pull the lever.
          } else if (choice != 'n' && choice != 'N') {
              std::cout << "Invalid choice. Please try again." << std::endl;
          }
      } while (choice != 'n' && choice != 'N');

      return 0; // Indicate successful execution.
  }


  };
  */




































#endif // SLOTMACHINE_H
