#include <iostream>
#include "classes/Databases.hpp"
#include "Validator.hpp"
#include <json.hpp>
#include "Utils.hpp"
#include "config/Config.hpp"
#include "enums/HttpStatus.hpp"
#include "exceptions/AppwriteException.hpp"

void Databases::setup(const std::string &apiKey, const std::string &projectId) {
    this->apiKey = apiKey;
    this->projectId = projectId;
}

std::string Databases::create(const std::string &databaseId, const std::string &name, bool enabled = false) {

    Validator::validateDatabaseParams(databaseId, name);

    std::string url = Config::API_BASE_URL + "/databases";
    std::string payload = "{\"databaseId\": \"" + databaseId +
                          "\", \"name\": \"" + name +
                          "\", \"enabled\": " + (enabled ? "true" : "false") + "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::CREATED) {
        return response;
    }
    else {
        throw AppwriteException("Error creating database. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}


std::string Databases::get(const std::string& databaseId) {

    if (databaseId.empty()) {
        throw AppwriteException("Missing required parameter: 'databaseId'");
    }

    std::string url = Config::API_BASE_URL + "/databases/" + databaseId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    }
    else {
        throw AppwriteException("Error fetching database. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }

}

std::string Databases::list(){
    std::string url = Config::API_BASE_URL + "/databases";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    }
    else {
        throw AppwriteException("Error listing databases. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::update(const std::string &databaseId, const std::string &name, bool enabled = false) {

    Validator::validateDatabaseParams(databaseId, name);

    std::string url = Config::API_BASE_URL + "/databases/" + databaseId;
    std::string payload = "{\"name\": \"" + name +
                          "\", \"enabled\": " + (enabled ? "true" : "false") + "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::putRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    }
    else {
        throw AppwriteException("Error updating database. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::listCollection(){
    std::string url = Config::API_BASE_URL + "/databases";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    }
    else {
        throw AppwriteException("Error listing collections. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::createCollection(const std::string& databaseId, const std::string& collectionId, const std::string& name,  bool enabled) {

    Validator::validateDatabaseParams(databaseId, name);

    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections";
    std::string payload = "{\"databaseId\": \"" + databaseId +
                          "\", \"collectionId\": \"" + collectionId +
                          "\", \"name\": \"" + name +
                          "\", \"enabled\": " + (enabled ? "true" : "false") + "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::CREATED) {
        return response;
    }
    else {
        throw AppwriteException("Error creating collection. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}


std::string Databases::createDocument(const std::string& databaseId, const std::string& collectionId, const std::string& documentId, const json& data) {

    if (databaseId.empty()) {
        throw AppwriteException("Missing required parameter: 'databaseId'");
    }
    if (collectionId.empty()) {
        throw AppwriteException("Missing required parameter: 'collectionId'");
    }
    if (documentId.empty()) {
        throw AppwriteException("Missing required parameter: 'documentId'");
    }
    if (data.is_null()) {
        throw AppwriteException("Missing required parameter: 'data'");
    }

    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/documents";

    json payloadJson = {
        {"databaseId", databaseId},
        {"collectionId", collectionId},
        {"documentId", documentId},
        {"data", data}
    };

    std::string payload = payloadJson.dump();
    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);
    
    std::string response;
    // std::cout << "Payload: " << payload << "\n";

    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::CREATED) {
        return response;
    } else {
        throw AppwriteException("Error creating document. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::getCollection(const std::string& databaseId, const std::string& collectionId){

    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    }
    else {
        throw AppwriteException("Error listing collections. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::updateCollection(const std::string &databaseId, const std::string &collectionId, const std::string &name, bool enabled) {

    Validator::validateDatabaseParams(databaseId, name);

    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId;
    std::string payload = "{\"name\": \"" + name +
                          "\", \"enabled\": " + (enabled ? "true" : "false") + "}";
   
    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::putRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    }
    else {
        throw AppwriteException("Error updating collection. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::deleteCollection(const std::string& databaseId, const std::string& collectionId) {
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::deleteRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) { 
        return response; 
    } else {
        throw AppwriteException("Error deleting collection. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}
