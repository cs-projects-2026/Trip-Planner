#ifndef TIMETABLE_H
#define TIMETABLE_H
#include <string>

class Timetable{ 
    private: 
        int startYear;
        int endYear;
        bool timetable[5][7];

    public:
        Timetable();
};

#endif