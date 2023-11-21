#ifndef STATUSMACHINE_H
#define STATUSMACHINE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h> 

using namespace std;


class STATUSMACHINE {
private:
    //attributes
    int idMachine;
    string name;
    static string greenStatus;
    static string yellowStatus;
    // this state means that the machine is in the middle of a game
    static string redStatus;
protected:
public:
    STATUSMACHINE();// construtor
      //NUMBERGUESSING(string pName, int pAmnt, int pBidamnt, int pGuess, int pDice, char pChoice);
    ~STATUSMACHINE();// destrutor
      // gets e sets
    string GetId();
    void SetId(int pId);
    string GetName();
    void SetName(string pName);
    int GetGreenStatus();
    void SetGreenStatus(string pGreenStatus = "ON");
    int GetYellowStatus();
    void SetYellowStatus(string pYellowStatus = "DAMAGED");
    int GetRedStatus();
    void SetRedStatus(string pRedStatus = "OFF");
    // functions to be called in main
    void Show();

};

#endif