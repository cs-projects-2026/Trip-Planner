#ifndef DEBT_h
#define DEBT_h
#include <string>
using namespace std;

class People;

class Debt{
private:
    People* ower;
    People* owee;
    double amount;

public:
    Debt();


};


#endif 