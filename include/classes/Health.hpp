#ifndef HEALTH_HPP
#define HEALTH_HPP

#include <string>
#include "Utils.hpp"
#include "exceptions/AppwriteException.hpp"
#include "enums/HttpStatus.hpp"

class Health {
public:
    void setup(const std::string& apiKey, const std::string& projectId);

    // core
    std::string getHealth();
    std::string getAntivirus();
    std::string getCache();
    std::string getDB();
    std::string getPubSub();
    std::string getStorage();
    std::string getStorageLocal();
    std::string getTime();
    std::string getQueue();
    std::string getCertificate(const std::string& domain = "");
    std::string getQueueCertificates(const std::string& threshold = "");
    std::string getQueueBuilds(const std::string& threshold = "");
    std::string getQueueUsageWebhooks(const std::string& threshold = "");
    std::string getQueueUsageDump(const std::string& threshold = "");

    
private:
    std::string apiKey;
    std::string projectId;
};

#endif