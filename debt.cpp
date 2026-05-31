#include "debt.h"
#include <iostream>

Debt::Debt(People* owee, People* ower, double amount = 0){
    this->ower = ower;
    this->owee = owee;
    this->amount = amount;
}

void Debt::addDebt(double newAmount){
    amount += newAmount;
}

void Debt::removeDebt(double newAmount){
    amount -= newAmount;
}

void Debt::setDebt(double newAmount){
    amount = newAmount;
}

void Debt::clearDebt(){
    amount = 0;
}

void Debt::changeOwee(People* newOwee){
    owee = newOwee; 
}


