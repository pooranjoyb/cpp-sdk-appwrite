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

std::string Messaging::getTopic(const std::string &topicId) {
    if (topicId.empty()) {
        throw AppwriteException("Missing required parameter: 'topicId'");
    }

    std::string url = Config::API_BASE_URL + "/messaging/topics/" + topicId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException(
            "Error fetching topic. Status code: " + std::to_string(statusCode) +
            "\n\nResponse: " + response);
    }
}

std::string Messaging::listTopics(Queries &queries) {

    std::string url =
        Config::API_BASE_URL + "/messaging/topics" + queries.to_string();

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException(
            "Error listing topics. Status code: " + std::to_string(statusCode) +
            "\n\nResponse: " + response);
    }
}

std::string Messaging::updateTopic(const std::string &topicId,
                                   const std::string &name,
                                   const std::vector<std::string> &subscribe) {
    if (topicId.empty()) {
        throw AppwriteException("Missing required parameter: 'topicId'");
    }

    if (name.empty()) {
        throw AppwriteException("Missing required parameter: 'name'");
    }

    std::string url = Config::API_BASE_URL + "/messaging/topics/" + topicId;

    std::string subscribeStr = "[";
    for (size_t i = 0; i < subscribe.size(); ++i) {
        subscribeStr += "\"" + Utils::escapeJsonString(subscribe[i]) + "\"";
        if (i < subscribe.size() - 1)
            subscribeStr += ",";
    }
    subscribeStr += "]";

    std::string payload =
        "{\"name\": \"" + Utils::escapeJsonString(name) + "\"";

    if (!subscribe.empty()) {
        payload += ", \"subscribe\": " + subscribeStr;
    }

    payload += "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::patchRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException(
            "Error updating topic. Status code: " + std::to_string(statusCode) +
            "\n\nResponse: " + response);
    }
}

std::string Messaging::deleteTopic(const std::string &topicId) {

    if (topicId.empty()) {
        throw AppwriteException("Missing required parameter: 'topicId'");
    }

    std::string url = Config::API_BASE_URL + "/messaging/topics/" + topicId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::deleteRequest(url, headers, response);

    if (statusCode == HttpStatus::DELETED) {
        return response;
    } else {
        throw AppwriteException(
            "Error deleting topic. Status code: " + std::to_string(statusCode) +
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

std::string Messaging::getSubscriber(const std::string &topicId,
                                     const std::string &subscriberId) {
    if (topicId.empty()) {
        throw AppwriteException("Missing required parameter: 'topicId'");
    }

    if (subscriberId.empty()) {
        throw AppwriteException("Missing required parameter: 'subscriberId'");
    }

    std::string url = Config::API_BASE_URL + "/messaging/topics/" + topicId +
                      "/subscribers/" + subscriberId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error fetching subscribers. Status code: " +
                                std::to_string(statusCode) +
                                "\n\nResponse: " + response);
    }
}

std::string Messaging::listSubscribers(const std::string &topicId,
                                       Queries &queries) {
    if (topicId.empty()) {
        throw AppwriteException("Missing required parameter: 'topicId'");
    }

    std::string url = Config::API_BASE_URL + "/messaging/topics/" + topicId +
                      "/subscribers" + queries.to_string();
    ;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error listing subscribers. Status code: " +
                                std::to_string(statusCode) +
                                "\n\nResponse: " + response);
    }
}

std::string Messaging::deleteSubscribers(const std::string &topicId,
                                         const std::string &subscriberId) {

    if (topicId.empty()) {
        throw AppwriteException("Missing required parameter: 'topicId'");
    }

    if (subscriberId.empty()) {
        throw AppwriteException("Missing required parameter: 'subscriberId'");
    }

    std::string url = Config::API_BASE_URL + "/messaging/topics/" + topicId +
                      "/subscribers/" + subscriberId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::deleteRequest(url, headers, response);

    if (statusCode == HttpStatus::DELETED) {
        return response;
    } else {
        throw AppwriteException("Error deleting subscriber. Status code: " +
                                std::to_string(statusCode) +
                                "\n\nResponse: " + response);
    }
}

std::string Messaging::createSubscribers(const std::string &topicId,
                                         const std::string &name,
                                         const std::string &targetId,
                                         const std::string &subscriberId) {
    if (topicId.empty()) {
        throw AppwriteException("Missing required parameter: 'topicId'");
    }

    if (name.empty()) {
        throw AppwriteException("Missing required parameter: 'name'");
    }

    if (targetId.empty()) {
        throw AppwriteException("Missing required parameter: 'targetId'");
    }

    if (subscriberId.empty()) {
        throw AppwriteException("Missing required parameter: 'subscriberId'");
    }

    std::string url = Config::API_BASE_URL + "/messaging/topics/" +
                      Utils::urlEncode(topicId) + "/subscribers";

    std::string payload =
        R"({"subscriberId":")" + Utils::escapeJsonString(subscriberId) +
        R"(","targetId":")" + Utils::escapeJsonString(targetId) +
        R"(","name":")" + Utils::escapeJsonString(name) + R"("})";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);
    headers.push_back("Content-Type: application/json");

    std::string response;
    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::CREATED) {
        return response;
    } else {
        throw AppwriteException("Error Creating Subscriber. Status code: " +
                                std::to_string(statusCode) +
                                "\n\nResponse: " + response);
    }
}

std::string Messaging::createPush(const std::string &messageId,
                                const std::string &title,
                                const std::string &body,
                                const std::string &topicId){
    if (messageId.empty()) {
        throw AppwriteException("Missing required parameter: 'messageId'");
    }

    if (title.empty()) {
        throw AppwriteException("Missing required parameter: 'title'");
    }

    if (body.empty()) {
        throw AppwriteException("Missing required parameter: 'body'");
    }

    if (topicId.empty()) {
        throw AppwriteException("Missing required parameter: 'topicId'");
    }  

    std::string url = Config::API_BASE_URL + "/messaging/messages/push";

    std::string payload =
        R"({"messageId":")" + Utils::escapeJsonString(messageId) +
        R"(","title":")" + Utils::escapeJsonString(title) +
        R"(","body":")" + Utils::escapeJsonString(body) +
        R"(","topics": [")" + Utils::escapeJsonString(topicId) + R"("]})";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);
    headers.push_back("Content-Type: application/json");    
    
    std::string response;
    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::CREATED) { 
        return response; 
    }  else { 
         throw AppwriteException( 
             "Error fetching topic. Status code: " + std::to_string(statusCode) + 
             "\n\nResponse: " + response); 
    } 
}

