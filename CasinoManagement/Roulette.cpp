#include "Roulette.h"
#include <iostream>
using namespace std;


ROULETTE::ROULETTE() {

    // cout << __FUNCTION__ << endl;
}
ROULETTE::~ROULETTE() {
    /* cout << __FUNCTION__ << endl;
     //scroll through the map and list freeing up allocated memory
     map <string,list<PLAYER*>*>::iterator itMAP;
     for (itMAP = Dados.begin(); itMAP != Dados.end();++itMAP) {


       for (list<PLAYER*>::iterator itLISTA = itMAP->second->begin(); itLISTA != itMAP->second->end();++itLISTA) { // scroll through the players list
         delete ((*itLISTA)); // freeing up allocated memory of a player
       }
       // freeing up allocated memory of the list
       delete(itMAP->second);
     }*/
     /// DADOS não foi alocado por nós GC
}





/**
  * Simulates spinning the roulette wheel a specified number of times.
  *
  * @param numSpins The number of spins to simulate.
  */
void ROULETTE::SpinWheel(int numSpins) {
    // Creating a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 36);

    // Spinning the wheel and storing the results
    for (int i = 0; i < numSpins; i++) {
        int spin = dis(gen);
        spins.push_back(spin);
    }
}

/**
* Prints the spins with their corresponding index.
*/
void ROULETTE::PrintSpins() {
    std::cout << "Spins:\n";
    for (int i = 0; i < spins.size(); i++) {
        std::cout << "Spin " << i + 1 << ": " << spins[i] << "\n";
    }
}

/**
* Calculates the sum of the spun numbers.
*
* @return int The sum of the spun numbers.
*/
int ROULETTE::CalculateSum() {
    int sum = 0;
    for (int spin : spins) {
        sum += spin;
    }
    return sum;
}

/**
* Calculates the average of the spun numbers.
*
* @return double The average of the spun numbers.
*/
double ROULETTE::CalculateAverage() {
    int sum = CalculateSum();
    double average = static_cast<double>(sum) / spins.size();
    return average;
}

/**
* Counts the number of times the number 11 was spun.
*
* @return int The count of spins resulting in the number 11.
*/
int ROULETTE::CountElevenSpins() {
    int count = 0;
    for (int spin : spins) {
        if (spin == 11) {
            count++;
        }
    }
    return count;
}