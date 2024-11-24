#include <iostream>
#include<fstream>
#include <cstring>
#include "car.h"
#include "admin.h"
#include "client.h"
#include "electroCar.h"
#include "order.h"

using namespace std;

void printAbc(Car* c) {
    c->abc();
}

void printAdminInfo(Person* p) {
    p->printInfo(); // Поліморфний виклик
}

void processRequest(Person* p, const string& request) {
    p->approveRequest(request); // Поліморфний виклик
}




void displayMenu() {
    cout << "\n==== MENU ====\n";
    cout << "1. Show static persons\n";
    cout << "2. Show dynamic persons\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

void Service(Person& person, const string& filename, bool writeMode) {
    try {
        if (writeMode) {
            // Запис у файл
            ofstream file(filename, ios::out | ios::binary);
            if (!file.is_open()) {
                throw runtime_error("Failed to open file for writing.");
            }

            file << person.getName() << endl
                << person.getAge() << endl
                << person.getID() << endl
                << person.getStatus() << endl
                << person.getAddress() << endl
                << person.getNumber() << endl;

            if (file.fail()) {
                throw runtime_error("Error occurred while writing to file.");
            }

            file.close();
            cout << "Data written to file successfully." << endl;
        }
        else {
            // Читання з файлу
            ifstream file(filename, ios::in | ios::binary);
            if (!file.is_open()) {
                throw runtime_error("Failed to open file for reading.");
            }

            string name, status, address;
            int age, id, number;

            if (!(getline(file, name) && file >> age && file >> id && file.ignore() &&
                getline(file, status) && getline(file, address) && file >> number)) {
                throw runtime_error("Invalid data format in file.");
            }

            if (file.fail()) {
                throw runtime_error("Error occurred while reading from file.");
            }

            file.close();

            // Оновлення даних об'єкта
            person.setName(name);
            person.setAge(age);
            person.setID(id);
            person.setStatus(status);
            person.setAddress(address);
            person.setNumber(number);

            cout << "Data read from file successfully." << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Service error: " << e.what() << endl;
        throw;
    }
}

int main() {
    // Демонстрація роботи класу Admin
    Admin admin1("Koi Winter", 19, 101, "Active", "123 Street, City", 5551234, "Pending");
    Admin admin2 = admin1; // Виклик конструктора копіювання
    cout << "Admin Info:" << endl;
    admin1.printAdminInfo();

    try {
        Person::printStaticPersons();

        Person::Service_Static(35);
        Person::printStaticPersons();

        Person::createDynamicPersons();
        Person::printDynamicPersons();

        Person::Service_Dynamic(30);
        Person::printDynamicPersons();

        Person::deleteDynamicPersons();
    }
    catch (const exception& e) {
        cerr << "Exception occurred: " << e.what() << endl;
    }

    try {
        // Створення об'єкта Person
        Person person("Koi Mark", 20, 104, "Active", "987 Pine St", 5551234);
        string filename = "person_data.txt";

        // Використання функції Service для запису
        Service(person, filename, true);

        // Використання функції Service для читання
        Service(person, filename, false);

        // Виведення даних, які були прочитані
        person.printInfo();
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }


    int choice; 

        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nStatic Persons:\n";
            Person::printStaticPersons();
            break;

        case 2:
            cout << "\nDynamic Persons:\n";
            Person::printDynamicPersons();
            break;

        case 3:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

        Admin admin("Kate", 40, 2, "Admin", "456 Elm St", 202, "Pending"); 
        printAdminInfo(&admin); 



    return 0;
}