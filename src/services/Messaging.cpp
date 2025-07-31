#include "classes/Messaging.hpp"
#include "Utils.hpp"
#include "Validator.hpp"
#include "classes/Query.hpp"
#include "config/Config.hpp"
#include "enums/HttpStatus.hpp"
#include "exceptions/AppwriteException.hpp"
#include <iostream>
#include <sstream>

Messaging::Messaging(const std::string &projectId, const std::string &apiKey)
    : projectId(projectId), apiKey(apiKey) {}

std::string Messaging::listMessages(Queries &queries) {
    std::string url =
        Config::API_BASE_URL + "/messaging/messages" + queries.to_string();

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error listing messages. Status code: " +
                                std::to_string(statusCode) +
                                "\n\nResponse: " + response);
    }
}

std::string Messaging::getMessages(const std::string &messageId) {
    if (messageId.empty()) {
        throw AppwriteException("Missing required parameter: 'messageId'");
    }

    std::string url = Config::API_BASE_URL + "/messaging/messages/" + messageId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error fetching message. Status code: " +
                                std::to_string(statusCode) +
                                "\n\nResponse: " + response);
    }
}

std::string Messaging::listMessageLogs(const std::string &messageId,
                                       Queries &queries) {
    if (messageId.empty()) {
        throw AppwriteException("Missing required parameter: messageId");
    }

    std::string url =
        Config::API_BASE_URL + "/messaging/messages/" + messageId + "/logs";
    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error listing message logs. Status code: " +
                                std::to_string(statusCode) +
                                "\nResponse: " + response);
    }
}

