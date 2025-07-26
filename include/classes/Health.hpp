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

    /// Check overall Appwrite health.
    std::string getHealthStatus();

    /// Check Antivirus service.
    std::string getAntivirus();

    /// Check cache service.
    std::string getCache();

    /// Check database service.
    std::string getDB();

    /// Check pub/sub service.
    std::string getPubSub();

    /// Check storage service.
    std::string getStorage();

    /// Check local storage service.
    std::string getStorageLocal();

    /// Get server time.
    std::string getTime();

    /// Check job queue service.
    std::string getQueue();

    /// Get SSL certificate status for a domain.
    std::string getCertificate(const std::string &domain = "");

    /// Get queued emails.
    std::string getQueueMails(const std::string &domain = "");

    /// Get queued certificates.
    std::string getQueueCertificates(const std::string &threshold = "");

    /// Get queued build jobs.
    std::string getQueueBuilds(const std::string &threshold = "");

    /// Get queued messaging jobs.
    std::string getQueueMessaging(const std::string &threshold = "");

    /// Get queued database migrations.
    std::string getQueueMigrations(const std::string &threshold = "");

    /// Get queued function executions.
    std::string getQueueFunctions(const std::string &threshold = "");

    /// Get queued usage webhook events.
    std::string getQueueUsageWebhooks(const std::string &threshold = "");

    /// Get queued usage dump jobs.
    std::string getQueueUsageDump(const std::string &threshold = "");

  private:
    std::string apiKey;    ///< Appwrite API key
    std::string projectId; ///< Appwrite project ID
};

#endif
