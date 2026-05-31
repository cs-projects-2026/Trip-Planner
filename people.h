#ifndef PEOPLE_h
#define PEOPLE_h
#include <string>
using namespace std;

class Debt;

class People{
private:
    string name;
    int id;
    Debt* debt;

public:
    People(string name);

};


#endif 