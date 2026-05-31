#ifndef PEOPLE_h
#define PEOPLE_h
#include "all_includes.h"
using namespace std;

class Debt;
class Timetable;

class People{
private:
    string name;
    int id;

    struct DebtNode {
        Debt* debt;
        DebtNode* next;
        DebtNode(Debt* d) : debt(d), next(nullptr) {}
    };

    DebtNode* head;
    DebtNode* tail;

public:
    People(string name);
    void printName();
    void setName(string name);
    void printId();
    string getName();
    int getId();

    void clearDebts();
    void addDebt(Debt* debt);
    void removeLastDebt();
    void removeDebtById(int id);
    void removeDebtByName(string name);

};


#endif 