#ifndef TIMETABLE_H
#define TIMETABLE_H
#include <set> 
#include "all_includes.h"

//Date object 
struct Date {
    int year; 
    int month; 
    int day; 

    /*
    operator< executes only when it detects a comparison between two date objects
    if d1 and d2 are both Date objects 
    d1 < d2 is the same as d1.operator<(d2) 
    */

    bool operator< (const Date& other) const { //this function calculates and returns d1 < d2
        if(year != other.year) 
            return year < other.year;
        if(month != other.month)
            return month < other.month;
        return day < other.day; 
    }

    /*
    similar to above, operator== executes only when it detects a comparison between two date objects
    d1 == d2 is same as d1.operator==(d2)
    */
    bool operator==(const Date& other) const { //returns and calculates d1 == d2 
        return year == other.year && month == other.month && day == other.day; 
    }

};

class Timetable{ 
    private: 
        int startYear;
        int endYear;
        std::set<Date> unavailableDates; 
        //only stores unavailable dates 
        
    public:
        Timetable(int start, int end);
        void setAvailability(const Date& date, bool availability);
        bool getAvailability(const Date& date) const; 
        int getStartYear() const; 
        int getEndYear() const; 
};

#endif