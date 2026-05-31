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
    Debt* debt;

public:
    People(string name);

};


#endif 