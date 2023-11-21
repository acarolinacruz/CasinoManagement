#ifndef ROULETTE_H
#define ROULETTE_H
#include <iostream>
#include <random>
#include <vector>

/**
 * Simulates the spinning of a roulette wheel and performs calculations on the
 * results.
 */
class ROULETTE {
private:
    int id;
    std::vector<int> spins; // Stores the numbers spun on the roulette wheel

public:
    ROULETTE(); // construtor
    // NUMBERGUESSING(string pName, int pAmnt, int pBidamnt, int pGuess, int
    // pDice, char pChoice);
    ~ROULETTE(); // destrutor

    // gets and sets
    int GetId();
    void SetId();

    // functions
    void SpinWheel(int numSpins);
    void PrintSpins();
    int CalculateSum();
    double CalculateAverage();
    int CountElevenSpins();
    int RouletteTrigger() {

        ROULETTE simulator;
        int numSpins = 12;

        simulator.SpinWheel(numSpins);
        simulator.PrintSpins();

        int sum = simulator.CalculateSum();
        double average = simulator.CalculateAverage();
        std::cout << "Sum of spins: " << sum << "\n";
        std::cout << "Average of spins: " << average << "\n";

        int elevenCount = simulator.CountElevenSpins();
        if (elevenCount > 0) {
            std::cout << "The number 11 was spun " << elevenCount << " times.\n";
        }
        else {
            std::cout << "The number 11 was not spun.\n";
        }

        return 0;
    }
};

#endif