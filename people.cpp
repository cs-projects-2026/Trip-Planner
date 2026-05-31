#include "all_includes.h"

People::People(string name){
    this->name = name;
    this->id = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

void People::printName(){
    cout << name << endl;
}

void People::setName(string name){
    this->name = name;
}

void People::printId(){
    cout << id << endl;
}

string People::getName(){
    return name;
}

int People::getId(){
    return id;
}

void People::clearDebts(){
    DebtNode* current = head;
    while (current != nullptr) {
        DebtNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

void People::addDebt(Debt* debt){
    DebtNode* newNode = new DebtNode(debt);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void People::removeLastDebt(){
    if (head == nullptr) return;

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    DebtNode* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = nullptr;
}

void People::removeDebtById(int id){
    DebtNode* current = head;
    DebtNode* prev = nullptr;

    while (current != nullptr) {
        if (current->debt->getOwer()->getId() == id || current->debt->getOwee()->getId() == id) {
            DebtNode* toDelete = current;
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            if (current == tail) {
                tail = prev;
            }
            current = current->next;
            delete toDelete;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void People::removeDebtByName(string name){
    DebtNode* current = head;
    DebtNode* prev = nullptr;

    while (current != nullptr) {
        if (current->debt->getOwer()->getName() == name || current->debt->getOwee()->getName() == name) {
            DebtNode* toDelete = current;
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            if (current == tail) {
                tail = prev;
            }
            current = current->next;
            delete toDelete;
        } else {
            prev = current;
            current = current->next;
        }
    }
}
