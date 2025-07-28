/// @file Appwrite.hpp
/// @brief Root header to import all core Appwrite SDK modules for easy access.

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
     *
     * @param projectId The Appwrite project ID.
     * @param apiKey Optional API key for authenticated requests.
     */
    Appwrite(const std::string &projectId, const std::string &apiKey = "");

    /**
     * @brief Get the Account module to manage user accounts.
     *
     * @return Account& Reference to Account object.
     */
    Account &getAccount();

    /**
     * @brief Get the Databases module to perform database operations.
     *
     * @return Databases& Reference to Databases object.
     */
    Databases &getDatabases();

    /**
     * @brief Get the Storage module for file and bucket operations.
     *
     * @return Storage& Reference to Storage object.
     */
    Storage &getStorage();

    /**
     * @brief Get the Health module to check Appwrite server status.
     *
     * @return Health& Reference to Health object.
     */
    Health &getHealth();

    /**
     * @brief Get the Messaging module for managing topics, subscribers, and
     * emails.
     *
     * @return Messaging& Reference to Messaging object.
     */
    Messaging &getMessaging();

  private:
    std::string projectId;
    std::string apiKey;
    Account account;
    Databases databases;
    Storage storage;
    Health health;
    Messaging messaging;
};

#endif
