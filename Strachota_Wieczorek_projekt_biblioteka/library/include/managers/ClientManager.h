//
// Created by student on 27.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTMANAGER_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTMANAGER_H


#include "typedefs.h"
#include <memory>
#include <vector>
#include <repositories/ClientRepository.h>
#include "repositories/Templates.h"


class clientManager {
    ClientRepository clientRepo;
public:
    ClientPtr getClient(const std::string&);
    ClientPtr registerClient(const std::string &firstName, const std::string &lastName, const std::string& personalID,
                             const AddressPtr &address, const ClientTypePtr &type);
    std::vector<ClientPtr> findClients(const ClientPredicate&);

    std::vector<ClientPtr> findAllClients();
    void unregisterClient(const ClientPtr& toDel);
    void saveAllClientsInfoToFile();
    void saveClientsToFileByPredicate(const ClientPredicate&);
    int countClientRent();

};







#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_CLIENTMANAGER_H