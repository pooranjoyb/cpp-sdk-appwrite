#ifndef APPWRITE_HPP
#define APPWRITE_HPP

#include "classes/Account.hpp"
#include "classes/Query.hpp"
#include "classes/Databases.hpp"
#include "classes/Storage.hpp"
#include "classes/Health.hpp"

class Appwrite {
public:
    Appwrite(const std::string& projectId, const std::string& apiKey = "");
    Account& getAccount();
    Databases& getDatabases();
    Storage& getStorage();
    Health& getHealth();
    
private:
    std::string projectId;
    std::string apiKey;
    Account account;
    Databases databases;
    Storage storage;
    Health health;
};

#endif
