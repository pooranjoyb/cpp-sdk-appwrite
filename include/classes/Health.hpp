#ifndef HEALTH_HPP
#define HEALTH_HPP

#include "Utils.hpp"
#include "enums/HttpStatus.hpp"
#include "exceptions/AppwriteException.hpp"
#include <string>

/**
 * @class Health
 * @brief Monitors the status of Appwrite's internal services.
 */
class Health {
  public:
    /**
     * @brief Constructor for Health class.
     * @param projectId Appwrite project ID.
     * @param apiKey Appwrite API key.
     */
    Health(const std::string &projectId, const std::string &apiKey);

    // Health checks for internal services

    std::string getHealthStatus();
    std::string getAntivirus();
    std::string getCache();
    std::string getDB();
    std::string getPubSub();
    std::string getStorage();
    std::string getStorageLocal();
    std::string getTime();
    std::string getQueue();
    std::string getCertificate(const std::string &domain = "");
    std::string getQueueMails(const std::string &domain = "");
    std::string getQueueCertificates(const std::string &threshold = "");
    std::string getQueueBuilds(const std::string &threshold = "");
    std::string getQueueMessaging(const std::string &threshold = "");
    std::string getQueueMigrations(const std::string &threshold = "");
    std::string getQueueFunctions(const std::string &threshold = "");
    std::string getQueueUsageWebhooks(const std::string &threshold = "");
    std::string getQueueUsageDump(const std::string &threshold = "");

  private:
    std::string apiKey;    ///< Appwrite API key
    std::string projectId; ///< Appwrite project ID
};

#endif