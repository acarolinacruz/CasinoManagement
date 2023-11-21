#ifndef Wheel_H
#define Wheel_H
#include <time.h>
#include <cstdlib> 
#include <iostream> 
using namespace std;

class Wheel {
private:
    int slots[9];
    int internalPtr;

public:
    Wheel();// construtor
    ~Wheel();// destrutor
    void spin();
    int* read();

};


#endif