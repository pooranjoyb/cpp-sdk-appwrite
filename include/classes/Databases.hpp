#ifndef DATABASES_HPP
#define DATABASES_HPP

#include <string>
#include "Utils.hpp"
#include "json.hpp"
#include "exceptions/AppwriteException.hpp"
#include "enums/HttpStatus.hpp"

using json = nlohmann::json;

class Databases {
public:
    void setup(const std::string& apiKey, const std::string& projectId);

    // Database
    std::string list();
    std::string get(const std::string& databaseId);
    std::string create(const std::string& databaseId, const std::string& name, bool enabled);
    std::string update(const std::string& databaseId, const std::string& name, bool enabled);

    // collections
    std::string listCollection();
    std::string createCollection(const std::string& databaseId, const std::string& collectionId, const std::string& name,  bool enabled);
    std::string getCollection(const std::string& databaseId, const std::string& collectionId);
    std::string updateCollection(const std::string& databaseId,const std::string& collectionId, const std::string& name, bool enabled);
    std::string deleteCollection(const std::string& databaseId, const std::string& collectionId);
    
    //attribute
    std::string listAttributes(const std::string& databaseId, const std::string& collectionId);
    std::string createBooleanAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool defaultValue, bool required);
    std::string createEmailAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue);
    std::string createEnumAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue, const std::vector<std::string>& elements );
    std::string createFloatAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, double min, double max, const std::string& defaultValue);
    std::string createIntegerAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, int min, int max, const std::string& defaultValue);
    std::string createIPaddressAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue);
    std::string createStringAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue, const std::vector<std::string>& elements, int size);
 
    std::string updateBooleanAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool defaultValue, bool required, const std::string& new_key);
    std::string updateEmailAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue, std::string& new_key);
    std::string updateEnumAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue, const std::vector<std::string>& elements, std::string& new_key);
    std::string updateFloatAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, double min, double max, const std::string& defaultValue, std::string& new_key);
    std::string updateIntegerAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, int min, int max, const std::string& defaultValue, std::string& new_key); 
    std::string updateIPaddressAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue, const std::string& new_key);
    std::string updateStringAttribute(const std::string& databaseId, const std::string& collectionId, const std::string& attributeId, bool required, const std::string& defaultValue, const std::vector<std::string>& elements, int size, std::string& new_key);
 
    // document
    std::string createDocument(const std::string& databaseId, const std::string& collectionId, const std::string& documentId, const json& data);
    std::string listDocument(const std::string& databaseId, const std::string& collectionId);
    std::string deleteDocument(const std::string& databaseId, const std::string& collectionId, const std::string& documentId);
    std::string getDocument(const std::string& databaseId, const std::string& collectionId, const std::string& documentId);

    //indexes
    std::string listIndexes(const std::string& databaseId, const std::string& collectionId);
    std::string createIndex(const std::string& databaseId, const std::string& collectionId, const std::string& key, const std::string& type, const std::vector<std::string> &attributes);


private:
    std::string apiKey;
    std::string projectId;
};

#endif
