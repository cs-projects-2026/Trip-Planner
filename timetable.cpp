#include "all_includes.h"

//helper function, checking if dates are valid 
static bool isValidDate(const Date& date){
    if(date.month < 1 || date.month > 12 || date.day < 1 || date.day > 31)
        return false; 
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //index represents the month, ignore 0, since month 0 does not exist, eg. index 1 is Jan with 31 days 

    //checking for leap year
    if(date.month == 2){
        bool isLeap = (date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0);
        if(isLeap) 
            daysInMonth[2] = 29; 
    }
    
    return date.day <= daysInMonth[date.month];
}

Timetable::Timetable(int start, int end){
    startYear = start; 
    endYear = end; 
}

void Timetable::setAvailability(const Date& date, bool availablity){
    if(!isValidDate(date) || date.year < startYear || date.year > endYear) 
        return; 
    if(availablity){
        cout << "[-] removed " << date.day << "/" << date.month << "/" << date.year << "from unavailableDates set" << endl; 
        unavailableDates.erase(date);
    }
    if(!availablity){
        cout << "[+] added " << date.day << "/" << date.month << "/" << date.year << "to unavailableDates set" << endl;
        unavailableDates.insert(date); 
    }
}

bool Timetable::getAvailability(const Date& date) const{ 
    if(!isValidDate(date) || date.year < startYear || date.year > endYear){
        cout << "[!] getAvailability() | " << date.day << "/" << date.month << "/" << date.year << " | returned false by error, invalid date or year out of bounds" <<endl; 
        return false; 
    }
    return unavailableDates.find(date) == unavailableDates.end();
    /* 
    if found (meaning it's an unavailable date) then unavailableDates.find(date) != unavailableDates.end() returns false (unavaiable date exists)
    if not found (unavailable date doesn't exist) then unavailableDates.find(date) returns .end() so unavailableDates.find(date) != unavailableDates.end() returns true
    */
}

int Timetable::getStartYear() const{
    return startYear;
}

int Timetable::getEndYear() const{
    return endYear;
}