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
                                const std::vector<std::string> &topicId,
                                const std::vector<std::string> &userId,
                                bool draft){
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

    if (userId.empty()) {
        throw AppwriteException("Missing required parameter: 'userId'");
    }
    
    std::string topicIdJson = "[";
    for (size_t i = 0; i < topicId.size(); ++i) {
        topicIdJson += "\"" + Utils::escapeJsonString(topicId[i]) + "\"";
        if (i < topicId.size() - 1) topicIdJson += ",";
    }
    topicIdJson += "]";
    
    std::string userIdJson = "[";
    for (size_t i = 0; i < userId.size(); ++i) {
        userIdJson += "\"" + Utils::escapeJsonString(userId[i]) + "\"";
        if (i < userId.size() - 1) userIdJson += ",";
    }
    userIdJson += "]";
    
    
    std::string url = Config::API_BASE_URL + "/messaging/messages/push";
    std::string payload =
        R"({"messageId":")" + Utils::escapeJsonString(messageId) +
        R"(","title":")" + Utils::escapeJsonString(title) +
        R"(","body":")" + Utils::escapeJsonString(body) +
        R"(","topicId":)" + topicIdJson +
        R"(,"userId":)" + userIdJson +
        R"(,"draft":)" + (draft ? "true" : "false") +
        "}";

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

std::string Messaging::createMessage(const std::string& messageId,
                                          const std::string& subject,
                                          const std::string& content,
                                          const std::vector<std::string>& topics,
                                          const std::vector<std::string>& targets) {
    if (messageId.empty()) {
        throw AppwriteException("Missing required parameter: 'messageId'");
    }
    if (subject.empty()) {
        throw AppwriteException("Missing required parameter: 'subject'");
    }
    if (content.empty()) {
        throw AppwriteException("Missing required parameter: 'content'");
    }
    if (topics.empty() && targets.empty()) {
        throw AppwriteException("At least one of 'topics' or 'targets' must be provided");
    }

    std::string payload = R"({"messageId":")" + Utils::escapeJsonString(messageId) +
                          R"(","subject":")" + Utils::escapeJsonString(subject) +
                          R"(","content":")" + Utils::escapeJsonString(content) + R"(")";

    if (!topics.empty()) {
        payload += R"(,"topics":[)";
        for (size_t i = 0; i < topics.size(); ++i) {
            payload += "\"" + Utils::escapeJsonString(topics[i]) + "\"";
            if (i != topics.size() - 1) payload += ",";
        }
        payload += "]";
    }

    if (!targets.empty()) {
        payload += R"(,"targets":[)";
        for (size_t i = 0; i < targets.size(); ++i) {
            payload += "\"" + Utils::escapeJsonString(targets[i]) + "\"";
            if (i != targets.size() - 1) payload += ",";
        }
        payload += "]";
    }

    payload += "}";

    std::string url = Config::API_BASE_URL + "/messaging/messages/email";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);
    headers.push_back("Content-Type: application/json");

    std::string response;

    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::CREATED || statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error creating email message. Status code: " +
                                std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Messaging::updatePush(const std::string &messageId,
                                  const std::string &title,
                                  const std::string &body,
                                  const std::vector<std::string> &topicId,
                                  const std::vector<std::string> &userId) {
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

    if (userId.empty()) {
        throw AppwriteException("Missing required parameter: 'userId'");
    }

    std::string topicIdJson = "[";
    for (size_t i = 0; i < topicId.size(); ++i) {
        topicIdJson += "\"" + Utils::escapeJsonString(topicId[i]) + "\"";
        if (i < topicId.size() - 1) topicIdJson += ",";
    }
    topicIdJson += "]";
    
    std::string userIdJson = "[";
    for (size_t i = 0; i < userId.size(); ++i) {
        userIdJson += "\"" + Utils::escapeJsonString(userId[i]) + "\"";
        if (i < userId.size() - 1) userIdJson += ",";
    }
    userIdJson += "]";
    
    std::string url = Config::API_BASE_URL + "/messaging/messages/push/" + messageId;
    std::string payload =
        R"({"title":")" + Utils::escapeJsonString(title) +
        R"(","body":")" + Utils::escapeJsonString(body) +
        R"(","topicId":)" + topicIdJson +
        R"(,"userId":)" + userIdJson +
        "}";
    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);
    headers.push_back("Content-Type: application/json");
    std::string response;
  
  int statusCode = Utils::patchRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException(
            "Error updating push message. Status code: " + std::to_string(statusCode) +
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
        throw AppwriteException("Error listing message logs. Status code: " +std::to_string(statusCode) + "\nResponse: " + response);
    }
}

std::string Messaging::deleteMessages(const std::string &messageId) {
    if (messageId.empty()) {
        throw AppwriteException("Missing required parameter: messageId");
    }
    std::string url = Config::API_BASE_URL + "/messaging/messages/" + messageId;
    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);
    std::string response;
    int statusCode = Utils::deleteRequest(url, headers, response);
    if (statusCode == HttpStatus::DELETED) {
        return "Message deleted.";
    } else {
        throw AppwriteException("Failed to delete message. Status code: " +
                                std::to_string(statusCode) +
                                "\nResponse: " + response);
    }
}

std::string Messaging::listTargets(const std::string &messageId, 
                                   const std::vector<std::string> &queries) {
    if (messageId.empty()) {
        throw AppwriteException("Missing required parameter: 'messageId'");
    }
    
    std::string url = Config::API_BASE_URL + "/messaging/messages/" + messageId + "/targets";
    std::string queryParam = "";
    if (!queries.empty()) {
        queryParam += "?queries[]=" + Utils::urlEncode(queries[0]);
        for (size_t i = 1; i < queries.size(); ++i) {
            queryParam += "&queries[]=" + Utils::urlEncode(queries[i]);
        }
    }
    
    url += queryParam;
    
    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException(
            "Error fetching message targets. Status code: " + std::to_string(statusCode) +
            "\n\nResponse: " + response);
    }
}