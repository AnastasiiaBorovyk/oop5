#pragma once
#include <string>
#include <iostream>
using namespace std;

class Car {
protected:
    int insuranceOption;
    bool confirmOrder;
    int damageLiability;
    string carModel;
    string IdCar;

public:
    int rentalPrice;

    Car(int iO, bool cO, int dL, string cM, string idC, int rP);
    Car();
    Car(const Car& other);

    int getInsuranceOption() const;
    bool getConfirmOrder() const;
    int getDamageLiability() const;
    string getCarModel() const;
    string getIdCar() const;
    int getRentalPrice() const;

    void printCarInfo() const;

    virtual void abc() const = 0;
};
