#include <string>
#include "model/Client.h"
#include "model/Rent.h"

//using namespace std;

Client::Client() {
    firstName = "exampleFirstName";
    lastName = "exampleLastName";
    personalID = "example personalID";
}


Client::Client(const std::string &imie, const std::string &nazwisko, const std::string &id, Address *caddress) : firstName(imie), lastName(nazwisko), personalID(id), CAddress(caddress){}


Client::~Client() {
    //delete CAddress;
}


std::string Client::getClientInfo() {
    std::string chain;
    chain = firstName + " " + lastName + " " + personalID + " " + CAddress->getAddressInfo();
    return chain;
}

void Client::setFirstName(const std::string &newFirstName) {
    if(newFirstName == "") {
        std::cout << "invalid output given to firstName!" << std::endl;
    } else {
        firstName = newFirstName;
    }
}

void Client::setLastName(const std::string &newLastName) {
    if(newLastName == "") {
        std::cout << "invalid output given to lastName!" << std::endl;
    } else {
        lastName = newLastName;
    }
}

void Client::setAddress(Address *newAddress) {
    if(newAddress == nullptr) {
        std::cout << "Invalid output. One mustn't pass nullptr as a parameter" << std::endl;
    } else {

        CAddress = newAddress;
        //CAddress->setCity(newAddress->getCity());
        //CAddress->setStreet(newAddress->getStreet());
        //CAddress->setNumber(newAddress->getNumber());

    }
}

const std::string &Client::getFirstName() const {
    return firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

const std::string &Client::getPersonalId() const {
    return personalID;
}

const Address *Client::getAddress() const {
    std::string text;
    text = CAddress->getCity() + " " + CAddress->getStreet() + " " + CAddress->getNumber();
    return CAddress;
}



void Client::addRent(Rent *r) {
    currentRents.push_back(r);
}

std::string Client::allRents() {
    std::string text;
    for(int i=0; i<currentRents.size(); i++)
    {
        text += currentRents[i]->getRentInfo();
        text += '\n';
    }
    return text;
}

std::string Client::getFullClientInfo() {


    std::string nie_za_maz;
    nie_za_maz = getClientInfo();
    std::string taniec;
    taniec = allRents() + getClientInfo();
    return taniec;
}

const Rent *Client::getRent(int number) const {
    return currentRents[number];
}


void Client::eraseRent(Rent *r) {
    remove(currentRents.begin(), currentRents.end(), r);
}