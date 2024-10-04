#ifndef APPWRITE_HPP
#define APPWRITE_HPP

#include "classes/Account.hpp"
#include "classes/Databases.hpp"

class Appwrite {
public:
    Appwrite(const std::string& projectId);
    Account& getAccount();
    Databases& getDatabases();
    
private:
    std::string projectId;
    Account account;
    Databases databases;
};

#endif
