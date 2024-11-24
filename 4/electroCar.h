#pragma once
#include "car.h"
class electroCar : private Car
{
	using Car::getCarModel;
    using Car::getIdCar;


private:
    int batteryCapacity;  // Ємність батареї (в кВт·год)
    int range;            // Запас ходу (в км)

public:
    // Конструктор з параметрами
    electroCar(int iO, bool cO, int dL, string cM, string IdCar, int rP, int bC, int r)
        : Car(iO, cO, dL, cM, IdCar, rP), batteryCapacity(bC), range(r) {}

    // Конструктор за замовчуванням
    electroCar() : Car(), batteryCapacity(75), range(400) {}

    // Метод для отримання ємності батареї
    int getBatteryCapacity() const {
        return batteryCapacity;
    }

    // Метод для отримання запасу ходу
    int getRange() const {
        return range;
    }

    // Метод для виведення інформації про електромобіль
    void displayInfo() const {
        cout << "ElectroCar Model: " << getCarModel() << endl;
        cout << "ID: " << getIdCar() << endl;
        cout << "Rental Price: " << getRentalPrice() << " UAH" << endl;
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
        cout << "Range: " << range << " km" << endl;
    }

    // Метод для підрахунку оренди з урахуванням типу електромобіля
    int calculateRentalPrice() const {
        int basePrice = getRentalPrice();
        return basePrice + (batteryCapacity / 10); // Додаємо 10% від ємності батареї
    }

    void abc() const override {
        cout << "ElectroCar Model: " << getCarModel() << endl; 
    }

};

