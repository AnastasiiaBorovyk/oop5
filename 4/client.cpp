#include"client.h"
#include <iostream> 

using namespace std;


//Client::Client(string name, int idUser, int rentalPeriod, string orderStatus)
//    : clientName(name), IdUser(idUser), rentalPeriod(rentalPeriod), orderStatus(orderStatus) {}

string Client::getClientName() const { return clientName; }
void Client::setClientName(const string& name) { clientName = name; }

int Client::getIdUser() const { return IdUser; }
void Client::setIdUser(int id) { IdUser = id; }

int Client::getRentalPeriod() const { return rentalPeriod; }
void Client::setRentalPeriod(int period) { rentalPeriod = period; }

string Client::getOrderStatus() const { return orderStatus; }
void Client::setOrderStatus(const string& status) { orderStatus = status; }

void Client::printClientInfo() const {
    cout << "Client Name: " << clientName << "\nID: " << IdUser << "\nRental Period: " << rentalPeriod
        << "\nOrder Status: " << orderStatus << endl;
}