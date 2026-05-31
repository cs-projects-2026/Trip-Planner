#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

//==========People Class==========

class People{
private:
    string name;
    int id;
    Debt* debt;

public:
    People(string name);

};

//================================



//==========Debt Class============

class Debt{
private:
    People ower;
    People owee;
    double amount;

public:
    Debt();


};
//================================


#endif 