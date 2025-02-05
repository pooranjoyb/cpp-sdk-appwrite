#include <iostream>
#include "classes/Databases.hpp"
#include "Validator.hpp"
#include <json.hpp>
#include "Utils.hpp"
#include "config/Config.hpp"
#include "enums/HttpStatus.hpp"
#include "exceptions/AppwriteException.hpp"

Databases::Databases(const std::string& projectId, const std::string& apiKey)
    : projectId(projectId), apiKey(apiKey) {}

//database
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

std::string Databases::getDatabaseUsage(const std::string& databaseId, const std::string& range) {
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/usage?range=" + range;
    std::cout << "Request URL: " << url << std::endl;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error fetching database usage. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

//collection
std::string Databases::listCollection(const std::string& databaseId) {
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
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

    if (statusCode == HttpStatus::DELETED) { 
        return response; 
    } else {
        throw AppwriteException("Error deleting collection. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::getCollectionUsage(const std::string& databaseId, const std::string& collectionId, const std::string& range) {
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/usage?range=" + range;
    std::cout << "Request URL: " << url << std::endl;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error fetching collection usage. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}
//attribute
std::string Databases::createBooleanAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool defaultValue, bool required) {
    
    Validator::validateDatabaseParams(databaseId, collectionId);
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes/boolean";

    std::string payload = "{\"key\": \"" + attributeId + "\", \"defaultValue\": " + (defaultValue ? "true" : "false") + ", \"required\": " + (required ? "true" : "false") + "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::ATTRIBUTE_CREATED) {
        return response;
    } else {
        throw AppwriteException("Error creating boolean attribute. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::updateBooleanAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool defaultValue, bool required, const std::string& new_key){
    
    Validator::validateDatabaseParams(databaseId, collectionId);
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes/boolean/" + attributeId;

    std::string payload = "{\"newKey\": \"" + new_key + "\", \"default\": " + (defaultValue ? "true" : "false") + ", \"required\": " + (required ? "true" : "false") + "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::patchRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error updating boolean attribute. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::createEmailAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue) {
    
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes/email";

    std::string payload = "{\"key\": \"" + attributeId + "\", \"required\": " + (required ? "true" : "false") +  ", \"default\": " + (defaultValue.empty() ? "null" : "\"" + defaultValue + "\"") + ", \"array\": false}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::ATTRIBUTE_CREATED) {
        return response;
    } else {
        throw AppwriteException("Error creating email attribute. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::updateEmailAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue, std::string& new_key) {
    
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes/email/" + attributeId;

    std::string payload = "{\"newKey\": \"" + new_key + "\", \"required\": " + (required ? "true" : "false") +  ", \"default\": " + (defaultValue.empty() ? "null" : "\"" + defaultValue + "\"") + ", \"array\": false}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::patchRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error updating email attribute. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::createEnumAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue, const std::vector<std::string>& elements ) {
   
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes/enum" ;

    std::string elementsStr = elements.empty() ? "null" : "[";
    for (size_t i = 0; i < elements.size(); ++i) {
        elementsStr += "\"" + elements[i] + "\"";
        if (i < elements.size() - 1) {
            elementsStr += ",";
        }
    }
    if (!elements.empty()) elementsStr += "]";

    std::string payload = "{" "\"key\": \"" + attributeId + "\", ""\"elements\": " + elementsStr + ", " "\"required\": " + (required ? "true" : "false") + ", "  "\"default\": " + (defaultValue.empty() ? "null" : "\"" + defaultValue + "\"") + ", " "\"array\": " + (elements.empty() ? "false" : "true") + "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::ATTRIBUTE_CREATED) {
        return response;
    } else {
        throw AppwriteException("Error creating Enum attribute. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::updateEnumAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue, const std::vector<std::string>& elements, std::string& new_key) {
  
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes/enum/" + attributeId;

    std::string elementsStr = elements.empty() ? "null" : "[";
    for (size_t i = 0; i < elements.size(); ++i) {
        elementsStr += "\"" + elements[i] + "\"";
        if (i < elements.size() - 1) {
            elementsStr += ",";
        }
    }
    if (!elements.empty()) elementsStr += "]";

    std::string payload = "{\"newKey\": \"" + new_key + "\", \"elements\": " + elementsStr + ", \"required\": " + (required ? "true" : "false") +  ", \"default\": " + (defaultValue.empty() ? "null" : "\"" + defaultValue + "\"") + ", \"array\": false}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::patchRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error updating enum attribute. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::createFloatAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, double min, double max, const std::string& defaultValue) {
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes/float";

    std::string payload = "{" 
        "\"key\": " + (attributeId.empty() ? "null" : "\"" + attributeId + "\"") + ", "
        "\"required\": " + (required ? "true" : "false") + ", "
        "\"min\": " + (min == 0.0 ? "null" : std::to_string(min)) + ", "
        "\"max\": " + (max == 0.0 ? "null" : std::to_string(max)) + ", "
        "\"default\": " + (defaultValue.empty() ? "null" : "\"" + defaultValue + "\"") + ", "
        "\"array\": false"
        "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::ATTRIBUTE_CREATED) {
        return response;
    } else {
        throw AppwriteException("Error creating Float attribute. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::updateFloatAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, double min, double max, const std::string& defaultValue, std::string& new_key) {
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes/float/" + attributeId;

    std::string payload = "{" 
        "\"newKey\": \"" + new_key + "\", "
        "\"required\": " + (required ? "true" : "false") + ", "
        "\"min\": " + (min == 0.0 ? "null" : std::to_string(min)) + ", "
        "\"max\": " + (max == 0.0 ? "null" : std::to_string(max)) + ", "
        "\"default\": " + (defaultValue.empty() ? "null" : "\"" + defaultValue + "\"") + ", "
        "\"array\": false"
        "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::patchRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error updating Float attribute. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::createIntegerAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, int min, int max, const std::string& defaultValue) {
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes/integer";

    std::string payload = "{" 
        "\"key\": " + (attributeId.empty() ? "null" : "\"" + attributeId + "\"") + ", "
        "\"required\": " + (required ? "true" : "false") + ", "
        "\"min\": " + std::to_string(min) + ", " 
        "\"max\": " + std::to_string(max) + ", " 
        "\"default\": " + (defaultValue.empty() ? "null" : "\"" + defaultValue + "\"") + ", "
        "\"array\": false"
        "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::ATTRIBUTE_CREATED) {
        return response;
    } else {
        throw AppwriteException("Error creating Integer attribute. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::updateIntegerAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, int min, int max, const std::string& defaultValue, std::string& new_key) {
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes/integer/" + attributeId;

    std::string payload = "{" 
        "\"newKey\": \"" + new_key + "\", "
        "\"required\": " + (required ? "true" : "false") + ", "
        "\"min\": " + std::to_string(min) + ", " 
        "\"max\": " + std::to_string(max) + ", " 
        "\"default\": " + (defaultValue.empty() ? "null" : "\"" + defaultValue + "\"") + ", "
        "\"array\": false"
        "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::patchRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error updating Integer attribute. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::createIPaddressAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue) {
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes/ip";

    std::string payload = "{" 
        "\"key\": " + (attributeId.empty() ? "null" : "\"" + attributeId + "\"") + ", "
        "\"required\": " + (required ? "true" : "false") + ", "
        "\"default\": " + (defaultValue.empty() ? "null" : "\"" + defaultValue + "\"") + ", "
        "\"array\": false"
        "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::ATTRIBUTE_CREATED) {
        return response;
    } else {
        throw AppwriteException("Error creating IP Address attribute. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::updateIPaddressAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue, const std::string& new_key) {
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes/ip/" + attributeId;

    std::string payload = "{" 
        "\"newKey\": \"" + new_key + "\", "
        "\"required\": " + (required ? "true" : "false") + ", "
        "\"default\": " + (defaultValue.empty() ? "null" : "\"" + defaultValue + "\"") + ", "
        "\"array\": false"
        "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);
    headers.push_back("Content-Type: application/json"); 

    std::string response;
    int statusCode = Utils::patchRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error updating IPAddress attribute. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}


std::string Databases::createStringAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue, const std::vector<std::string>& elements, int size) {
   
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes/string";

    std::string elementsStr = elements.empty() ? "null" : "[";
    for (size_t i = 0; i < elements.size(); ++i) {
        elementsStr += "\"" + elements[i] + "\"";
        if (i < elements.size() - 1) {
            elementsStr += ",";
        }
    }
    if (!elements.empty()) elementsStr += "]";

  std::string payload = "{" 
    "\"key\": \"" + attributeId + "\", "
    "\"elements\": " + elementsStr + ", "
    "\"required\": " + (required ? "true" : "false") + ", "
    "\"default\": " + (defaultValue.empty() ? "null" : "\"" + defaultValue + "\"") + ", "
    "\"array\": " + (elements.empty() ? "false" : "true") + ", "
    "\"size\": " + std::to_string(size) + " "
"}";

    std::cout << "Payload: " << payload << std::endl; 

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::ATTRIBUTE_CREATED) {
        return response;
    } else {
        throw AppwriteException("Error creating String attribute. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::updateStringAttribute( const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue, const std::vector<std::string>& elements, int size, std::string& new_key 
) {
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes/string/" + attributeId;

    std::string elementsStr = elements.empty() ? "null" : "[";
    for (size_t i = 0; i < elements.size(); ++i) {
        elementsStr += "\"" + elements[i] + "\"";
        if (i < elements.size() - 1) {
            elementsStr += ",";
        }
    }
    if (!elements.empty()) elementsStr += "]";

    std::string payload = "{" 
        "\"newKey\": \"" + new_key + "\", "  
        "\"elements\": " + elementsStr + ", "
        "\"required\": " + (required ? "true" : "false") + ", "
        "\"default\": " + (defaultValue.empty() ? "null" : "\"" + defaultValue + "\"") + ", "
        "\"array\": " + (elements.empty() ? "false" : "true") + ", "
        "\"size\": " + std::to_string(size) + 
    "}";

   std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::patchRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error updating Integer attribute. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::listAttributes(const std::string& databaseId, const std::string& collectionId){
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/attributes";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error fetching attributes. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

//document
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

std::string Databases::listDocument(const std::string& databaseId, const std::string& collectionId){
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/documents";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error fetching documents. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::deleteDocument(const std::string& databaseId, const std::string& collectionId, const std::string& documentId) {
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/documents/" + documentId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::deleteRequest(url, headers, response);

    if (statusCode == HttpStatus::DELETED) { 
        return response; 
    } else {
        throw AppwriteException("Error deleting document. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::getDocument(const std::string& databaseId, const std::string& collectionId, const std::string& documentId) {

    if (databaseId.empty()) {
        throw AppwriteException("Missing required parameter: 'documentId'");
    }

    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/documents/" + documentId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    }
    else {
        throw AppwriteException("Error fetching document. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }

}

//idexes
std::string Databases::listIndexes(const std::string& databaseId, const std::string& collectionId){
    Validator::validateDatabaseParams(databaseId, collectionId);
    
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/indexes";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;
    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error fetching indexes. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::createIndexes(const std::string& databaseId, const std::string& collectionId, const std::string& key, const std::string& type, const std::vector<std::string> &attributes){
    if (databaseId.empty()) {
        throw AppwriteException("Missing required parameter: 'databaseId'");
    }
    if (collectionId.empty()) {
        throw AppwriteException("Missing required parameter: 'collectionId'");
    }

    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/indexes";

    std::string attributesStr = "[";
    for(auto attribute : attributes) {
        attributesStr += "\"" + attribute + "\",";
    }
    attributesStr.pop_back();
    attributesStr += "]";
    std::string payload = R"({"databaseId":")" + databaseId 
                            + R"(","collectionId":")" + collectionId 
                            + R"(","key":")" + key 
                            + R"(","type":")" + type 
                            + R"(","attributes":)" + attributesStr + R"(})";
    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);
    
    std::string response;

    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::INDEX_CREATED) {
        return response;
    } else {
        throw AppwriteException("Error creating index. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::deleteIndexes(const std::string& databaseId, const std::string& collectionId, const std::string& key) {
    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/indexes/" + key;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::deleteRequest(url, headers, response);

    if (statusCode == HttpStatus::DELETED) { 
        return response; 
    } else {
        throw AppwriteException("Error deleting index. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }
}

std::string Databases::getIndexes(const std::string& databaseId, const std::string& collectionId, const std::string& key) {

    if (databaseId.empty()) {
        throw AppwriteException("Missing required parameter: 'index key'");
    }

    std::string url = Config::API_BASE_URL + "/databases/" + databaseId + "/collections/" + collectionId + "/indexes/" + key;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    }
    else {
        throw AppwriteException("Error fetching index. Status code: " + std::to_string(statusCode) + "\n\nResponse: " + response);
    }

}
