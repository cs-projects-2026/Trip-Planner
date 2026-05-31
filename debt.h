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
    Debt(People*, People*, double);
    void addDebt(double amount);
    void removeDebt(double amount);
    void setDebt(double amount);
    void clearDebt();
    void changeOwee(People* newOwee);
};


#endif 