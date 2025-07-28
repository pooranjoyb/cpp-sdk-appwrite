/// @file Health.hpp
/// @brief Exposes health check APIs to verify Appwrite server status and
/// service uptime.
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

    /**
     * @brief Check overall Appwrite health.
     * @return JSON string with health status.
     */
    std::string getHealthStatus();

    /**
     * @brief Check Antivirus service status.
     * @return JSON string with antivirus health.
     */
    std::string getAntivirus();

    /**
     * @brief Check cache service status.
     * @return JSON string with cache health.
     */
    std::string getCache();

    /**
     * @brief Check database service status.
     * @return JSON string with database health.
     */
    std::string getDB();

    /**
     * @brief Check pub/sub service status.
     * @return JSON string with pub/sub health.
     */
    std::string getPubSub();

    /**
     * @brief Check storage service status.
     * @return JSON string with storage health.
     */
    std::string getStorage();

    /**
     * @brief Check local storage service status.
     * @return JSON string with local storage health.
     */
    std::string getStorageLocal();

    /**
     * @brief Get current server time.
     * @return JSON string with server time.
     */
    std::string getTime();

    /**
     * @brief Check job queue service status.
     * @return JSON string with queue health.
     */
    std::string getQueue();

    /**
     * @brief Get SSL certificate status for a domain.
     * @param domain Domain name to check.
     * @return JSON string with certificate status.
     */
    std::string getCertificate(const std::string &domain = "");

    /**
     * @brief Get queued emails.
     * @param domain Optional domain to filter.
     * @return JSON string with email queue.
     */
    std::string getQueueMails(const std::string &domain = "");

    /**
     * @brief Get queued certificate jobs.
     * @param threshold Optional threshold filter.
     * @return JSON string with certificate queue.
     */
    std::string getQueueCertificates(const std::string &threshold = "");

    /**
     * @brief Get queued build jobs.
     * @param threshold Optional threshold filter.
     * @return JSON string with build queue.
     */
    std::string getQueueBuilds(const std::string &threshold = "");

    /**
     * @brief Get queued messaging jobs.
     * @param threshold Optional threshold filter.
     * @return JSON string with messaging queue.
     */
    std::string getQueueMessaging(const std::string &threshold = "");

    /**
     * @brief Get queued database migrations.
     * @param threshold Optional threshold filter.
     * @return JSON string with migration queue.
     */
    std::string getQueueMigrations(const std::string &threshold = "");

    /**
     * @brief Get queued function executions.
     * @param threshold Optional threshold filter.
     * @return JSON string with function queue.
     */
    std::string getQueueFunctions(const std::string &threshold = "");

    /**
     * @brief Get queued usage webhook events.
     * @param threshold Optional threshold filter.
     * @return JSON string with usage webhook queue.
     */
    std::string getQueueUsageWebhooks(const std::string &threshold = "");

    /**
     * @brief Get queued usage dump jobs.
     * @param threshold Optional threshold filter.
     * @return JSON string with usage dump queue.
     */
    std::string getQueueUsageDump(const std::string &threshold = "");

  private:
    std::string apiKey;    ///< Appwrite API key
    std::string projectId; ///< Appwrite project ID
};

#endif
