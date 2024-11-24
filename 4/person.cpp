#include "Person.h"
#include <stdexcept>

// Конструктор
Person::Person(string n, int a, int id, string s, string addr, int num) {
    if (a < 0) throw invalid_argument("Age cannot be negative!");
    if (id <= 0) throw invalid_argument("ID must be a positive integer!");

    name = n;
    age = a;
    ID = id;
    status = s;
    address = addr;
    number = num;
}

// Методи доступу
string Person::getName() const { return name; }
void Person::setName(const string& n) { name = n; }

int Person::getAge() const { return age; }
void Person::setAge(int a) {
    if (a < 0) throw invalid_argument("Age cannot be negative!");
    age = a;
}

int Person::getID() const { return ID; }
void Person::setID(int id) {
    if (id <= 0) throw invalid_argument("ID must be a positive integer!");
    ID = id;
}

string Person::getStatus() const { return status; }
void Person::setStatus(const string& s) { status = s; }

string Person::getAddress() const { return address; }
void Person::setAddress(const string& addr) { address = addr; }

int Person::getNumber() const { return number; }
void Person::setNumber(int num) {
    if (num <= 0) throw invalid_argument("Number must be positive!");
    number = num;
}

void Person::printInfo() const {
    cout << "Name: " << name
        << ", Age: " << age
        << ", ID: " << ID
        << ", Status: " << status
        << ", Address: " << address
        << ", Number: " << number
        << endl;
}

// Ініціалізація статичних об'єктів
Person Person::staticPersons[3] = {
    Person("Alice", 30, 101, "Active", "123 Main St", 5551234),
    Person("Bob", 40, 102, "Inactive", "456 Elm St", 5555678),
    Person("Charlie", 25, 103, "Pending", "789 Oak St", 5559101)
};

// Ініціалізація динамічних об'єктів
Person* Person::dynamicPersons[3] = { nullptr, nullptr, nullptr };

void Person::printStaticPersons() { //завдання 10
    for (int i = 0; i < 3; ++i) {
        cout << "Static Person " << (i + 1) << ":\n";
        staticPersons[i].printInfo();
    }
}

void Person::createDynamicPersons() {
    try {
        dynamicPersons[0] = new Person("Kai", 28, 201, "Active", "101 Dynamic St", 5551001);
        dynamicPersons[1] = new Person("Adam", 35, 202, "Inactive", "202 Dynamic St", 5551002);
        dynamicPersons[2] = new Person("Ben", 22, 203, "Pending", "303 Dynamic St", 5551003);
    }
    catch (const bad_alloc& e) {
        cerr << "Memory allocation failed: " << e.what() << endl;
        for (int i = 0; i < 3; ++i) {
            delete dynamicPersons[i];
            dynamicPersons[i] = nullptr;
        }
    }
}

void Person::deleteDynamicPersons() {
    for (int i = 0; i < 3; ++i) {
        delete dynamicPersons[i];
        dynamicPersons[i] = nullptr;
    }
}

void Person::printDynamicPersons() { //завдання 10
    for (int i = 0; i < 3; ++i) {
        if (dynamicPersons[i]) {
            cout << "Dynamic Person " << (i + 1) << ":\n";
            dynamicPersons[i]->printInfo();
        }
        else {
            cout << "Dynamic Person " << (i + 1) << " is null.\n";
        }
    }
}

void Person::Service_Static(int minAge) {
    bool found = false;
    for (int i = 0; i < 3; ++i) {
        if (staticPersons[i].age > minAge) {
            cout << "Static Person " << (i + 1) << " marked as inactive.\n";
            staticPersons[i].status = "Removed";
            found = true;
        }
    }
    if (!found) {
        throw runtime_error("No static persons found with age greater than the criterion.");
    }
}

void Person::Service_Dynamic(int minAge) {
    bool found = false;
    for (int i = 0; i < 3; ++i) {
        if (dynamicPersons[i] && dynamicPersons[i]->age > minAge) {
            delete dynamicPersons[i];
            dynamicPersons[i] = nullptr;
            cout << "Dynamic Person " << (i + 1) << " deleted.\n";
            found = true;
        }
    }
    if (!found) {
        throw runtime_error("No dynamic persons found with age greater than the criterion.");
    }
}
