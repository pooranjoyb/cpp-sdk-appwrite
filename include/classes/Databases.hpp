#ifndef DATABASES_HPP
#define DATABASES_HPP

#include <string>
#include "Utils.hpp"
#include "classes/Query.hpp"
#include "exceptions/AppwriteException.hpp"
#include "enums/HttpStatus.hpp"


class Databases {
public:
    Databases(const std::string& projectId, const std::string& apiKey);

    // Database
    std::string list();
    std::string get(const std::string& databaseId);
    std::string create(const std::string& databaseId, const std::string& name, bool enabled);
    std::string update(const std::string& databaseId, const std::string& name, bool enabled);
    std::string getDatabaseUsage(const std::string& databaseId, const std::string& range);
    std::string getCollectionUsage(const std::string& databaseId, const std::string& collectionId, const std::string& range);
  
 
    // collections
    std::string listCollection(const std::string& databaseId);
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
    std::string createDocument(const std::string& databaseId,
                                         const std::string& collectionId,
                                         const std::string& documentId,
                                         const std::string& rawData);
    std::string listDocument(const std::string& databaseId, const std::string& collectionId, Queries &queries);
    std::string deleteDocument(const std::string& databaseId, const std::string& collectionId, const std::string& documentId);
    std::string getDocument(const std::string& databaseId, const std::string& collectionId, const std::string& documentId);

    //indexes
    std::string listIndexes(const std::string& databaseId, const std::string& collectionId);
    std::string createIndexes(const std::string& databaseId, const std::string& collectionId, const std::string& key, const std::string& type, const std::vector<std::string> &attributes);
    std::string deleteIndexes(const std::string& databaseId, const std::string& collectionId, const std::string& key);
    std::string getIndexes(const std::string& databaseId, const std::string& collectionId, const std::string& key);

private:
    std::string apiKey;
    std::string projectId;
};

#endif
