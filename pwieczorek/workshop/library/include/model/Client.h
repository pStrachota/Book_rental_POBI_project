#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include <string>
#include <iostream>
#include "model/Address.h"
#include "model/Rent.h"
#include <vector>
#include "typedefs.h"

class Rent;

class Client {

private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    AddressPtr ClientAddress;
    ClientTypePtr clientType;
    bool archive = false;
    //std::vector<RentPtr> currentRents;

public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, AddressPtr ClientAddress, ClientTypePtr clientType);
    //~Client();
    std::string getClientInfo();
    std::string getInfo() const;
    std::string getId() const;
    //std::string getFullClientInfo();
    void setFirstName(const std::string & ) ;
    void setLastName(const std::string & ) ;
    void setIsArchive(bool archive);
    bool isArchive();
    void setAddress(AddressPtr);
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalID() const;
    const AddressPtr getAddress() const;
    const ClientTypePtr getClientType() const;
    int getMaxVehicles();
    double applyDiscount(double);
    void setClientType(ClientTypePtr clientType1);

};

#endif //CARRENTAL_CLIENT_H