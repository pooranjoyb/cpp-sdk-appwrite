#include "classes/Messaging.hpp"
#include "Utils.hpp"
#include "Validator.hpp"
#include "config/Config.hpp"
#include "enums/HttpStatus.hpp"
#include "exceptions/AppwriteException.hpp"
#include <iostream>
#include <sstream>

Messaging::Messaging(const std::string &projectId, const std::string &apiKey)
    : projectId(projectId), apiKey(apiKey) {}

std::string Messaging::getTopic(const std::string &topicId) {
    if (topicId.empty()) {
        throw AppwriteException("Missing required parameter: 'topicId'");
    }

    std::string url = Config::API_BASE_URL + "/messaging/topics/" + topicId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);
    std::cout << response;

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error fetching health. Status code: " +
                                std::to_string(statusCode) +
                                "\n\nResponse: " + response);
    }
}

std::string Messaging::createTopic(const std::string &topicId,
                                   const std::string &name,
                                   const std::vector<std::string> &subscribe) {
    if (topicId.empty()) {
        throw AppwriteException("Missing required parameter: 'topicId'");
    }

    if (name.empty()) {
        throw AppwriteException("Missing required parameter: 'name'");
    }

    std::string url = Config::API_BASE_URL + "/messaging/topics/";

    std::string subscribeStr = "[";
    for (const auto &ext : subscribe) {
        subscribeStr += "\"" + Utils::escapeJsonString(ext) + "\",";
    }

    if (!subscribe.empty())
        subscribeStr.pop_back();
    subscribeStr += "]";

    std::string payload = R"({"topicId":")" + Utils::escapeJsonString(topicId) +
                          R"(",)" + R"("name":")" +
                          Utils::escapeJsonString(name) + "," +
                          R"("subscribe":)" + subscribeStr + R"("})";

    std::cout << payload;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::CREATED) {
        return response;
    } else {
        throw AppwriteException(
            "Error Creating Topic. Status code: " + std::to_string(statusCode) +
            "\n\nResponse: " + response);
    }
}
