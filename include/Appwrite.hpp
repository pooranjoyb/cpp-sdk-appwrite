/// @file Appwrite.hpp
/// @brief Entry point to access all Appwrite services from the C++ SDK.

#ifndef APPWRITE_HPP
#define APPWRITE_HPP

#include "classes/Account.hpp"
#include "classes/Databases.hpp"
#include "classes/Health.hpp"
#include "classes/Messaging.hpp"
#include "classes/Query.hpp"
#include "classes/Storage.hpp"

/**
 * @class Appwrite
 * @brief Main entry point for accessing Appwrite services via the C++ SDK.
 */
class Appwrite {
  public:
    /**
     * @brief Construct a new Appwrite instance.
     * @param projectId The Appwrite project ID.
     * @param apiKey Optional API key for authenticated requests.
     */
    Appwrite(const std::string &projectId, const std::string &apiKey = "");

    Account &getAccount();     ///< Access Account module
    Databases &getDatabases(); ///< Access Databases module
    Storage &getStorage();     ///< Access Storage module
    Health &getHealth();       ///< Access Health module
    Messaging &getMessaging(); ///< Access Messaging module

  private:
    std::string projectId; ///< Project ID
    std::string apiKey;    ///< API Key
    Account account;
    Databases databases;
    Storage storage;
    Health health;
    Messaging messaging;
};

#endif
