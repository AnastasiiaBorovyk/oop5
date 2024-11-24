#pragma once
#include "car.h"
#include"person.h"
#include<iostream>

using namespace std;

class Admin : public Person {
public:

    string requestStatus;


    // Конструктор з параметрами
    Admin(const string& name, int age, int id, const string& status,
        const string& address, int number, const string& reqStatus)
        : Person(name, age, id, status, address, number), requestStatus(reqStatus) {}

    // Конструктор копіювання
    Admin(const Admin& other)
        : Person(other), requestStatus(other.requestStatus) {}

    // Деструктор
    ~Admin() {
        cout << "Admin destructor called for " << getName() << endl;
    }

    // Метод для виведення інформації
    void printAdminInfo() const {
        printInfo();
        cout << "Request Status: " << requestStatus << endl;
    }

    // Метод для оновлення статусу запиту
    void updateRequestStatus(const string& newStatus) {
        requestStatus = newStatus;
    }

    // Віртуальний деструктор
    virtual void cleanUp() {
        cout << "Admin-specific cleanup completed." << endl;
    }

    // Унікальна віртуальна функція
    virtual void approveRequest(const string& request) const {
        cout << "Admin " << getName() << " approved request: " << request << endl;
    }


    void printInfo() const override {
        Person::printInfo(); // Виклик базової реалізації
        cout << "Request Status: " << requestStatus << endl;
    }

};
