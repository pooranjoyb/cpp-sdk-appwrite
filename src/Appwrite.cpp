#include "Appwrite.hpp"

Appwrite::Appwrite(const std::string& projectId, const std::string& apiKey)
    : projectId(projectId), apiKey(apiKey), account(projectId),
      databases(projectId, apiKey), storage(projectId, apiKey), health(projectId, apiKey), messaging(projectId, apiKey) {}


Account& Appwrite::getAccount() {
    return account;
}

Databases& Appwrite::getDatabases() {
    return databases;
}

Storage& Appwrite::getStorage() {
    return storage;
}

Health& Appwrite::getHealth() {
    return health;
}

Messaging& Appwrite::getMessaging() {
    return messaging;
}