#ifndef DATABASES_HPP
#define DATABASES_HPP

#include "Utils.hpp"
#include "classes/Query.hpp"
#include "enums/HttpStatus.hpp"
#include "exceptions/AppwriteException.hpp"
#include <string>

/**
 * @class Databases
 * @brief Provides CRUD operations for databases, collections, documents, and
 * attributes.
 */
class Databases {
  public:
    /**
     * @brief Constructor for Databases class.
     * @param projectId Appwrite project ID.
     * @param apiKey Appwrite API key.
     */
    Databases(const std::string &projectId, const std::string &apiKey);

    // Database APIs

    /// List all databases.
    std::string list();

    /// Get a database by ID.
    std::string get(const std::string &databaseId);

    /// Create a new database.
    std::string create(const std::string &databaseId, const std::string &name,
                       bool enabled);

    /// Update a database’s name and status.
    std::string update(const std::string &databaseId, const std::string &name,
                       bool enabled);

    /// Get database usage stats for a given range.
    std::string getDatabaseUsage(const std::string &databaseId,
                                 const std::string &range);

    /// Get collection usage stats within a database.
    std::string getCollectionUsage(const std::string &databaseId,
                                   const std::string &collectionId,
                                   const std::string &range);

    // Collection APIs

    /// List all collections in a database.
    std::string listCollection(const std::string &databaseId);

    /// Create a new collection.
    std::string createCollection(const std::string &databaseId,
                                 const std::string &collectionId,
                                 const std::string &name, bool enabled);

    /// Get details of a collection.
    std::string getCollection(const std::string &databaseId,
                              const std::string &collectionId);

    /// Update collection metadata.
    std::string updateCollection(const std::string &databaseId,
                                 const std::string &collectionId,
                                 const std::string &name, bool enabled);

    /// Delete a collection.
    std::string deleteCollection(const std::string &databaseId,
                                 const std::string &collectionId);

    // Attribute APIs

    /// List all attributes in a collection.
    std::string listAttributes(const std::string &databaseId,
                               const std::string &collectionId);

    /// Create a boolean attribute.
    std::string createBooleanAttribute(const std::string &databaseId,
                                       const std::string &collectionId,
                                       const std::string &attributeId,
                                       bool defaultValue, bool required);

    /// Create an email attribute.
    std::string createEmailAttribute(const std::string &databaseId,
                                     const std::string &collectionId,
                                     const std::string &attributeId,
                                     bool required,
                                     const std::string &defaultValue);

    /// Create an enum attribute.
    std::string createEnumAttribute(const std::string &databaseId,
                                    const std::string &collectionId,
                                    const std::string &attributeId,
                                    bool required,
                                    const std::string &defaultValue,
                                    const std::vector<std::string> &elements);

    /// Create a float attribute.
    std::string createFloatAttribute(const std::string &databaseId,
                                     const std::string &collectionId,
                                     const std::string &attributeId,
                                     bool required, double min, double max,
                                     const std::string &defaultValue);

    /// Create an integer attribute.
    std::string createIntegerAttribute(const std::string &databaseId,
                                       const std::string &collectionId,
                                       const std::string &attributeId,
                                       bool required, int min, int max,
                                       const std::string &defaultValue);

    /// Create an IP address attribute.
    std::string createIPaddressAttribute(const std::string &databaseId,
                                         const std::string &collectionId,
                                         const std::string &attributeId,
                                         bool required,
                                         const std::string &defaultValue);

    /// Create a string attribute.
    std::string createStringAttribute(const std::string &databaseId,
                                      const std::string &collectionId,
                                      const std::string &attributeId,
                                      bool required,
                                      const std::string &defaultValue,
                                      const std::vector<std::string> &elements,
                                      int size);

    // Update Attributes

    /// Update a boolean attribute.
    std::string updateBooleanAttribute(const std::string &databaseId,
                                       const std::string &collectionId,
                                       const std::string &attributeId,
                                       bool defaultValue, bool required,
                                       const std::string &new_key);

    /// Update an email attribute.
    std::string updateEmailAttribute(const std::string &databaseId,
                                     const std::string &collectionId,
                                     const std::string &attributeId,
                                     bool required,
                                     const std::string &defaultValue,
                                     std::string &new_key);

    /// Update an enum attribute.
    std::string updateEnumAttribute(const std::string &databaseId,
                                    const std::string &collectionId,
                                    const std::string &attributeId,
                                    bool required,
                                    const std::string &defaultValue,
                                    const std::vector<std::string> &elements,
                                    std::string &new_key);

    /// Update a float attribute.
    std::string updateFloatAttribute(const std::string &databaseId,
                                     const std::string &collectionId,
                                     const std::string &attributeId,
                                     bool required, double min, double max,
                                     const std::string &defaultValue,
                                     std::string &new_key);

    /// Update an integer attribute.
    std::string updateIntegerAttribute(const std::string &databaseId,
                                       const std::string &collectionId,
                                       const std::string &attributeId,
                                       bool required, int min, int max,
                                       const std::string &defaultValue,
                                       std::string &new_key);

    /// Update an IP address attribute.
    std::string updateIPaddressAttribute(const std::string &databaseId,
                                         const std::string &collectionId,
                                         const std::string &attributeId,
                                         bool required,
                                         const std::string &defaultValue,
                                         const std::string &new_key);

    /// Update a string attribute.
    std::string updateStringAttribute(const std::string &databaseId,
                                      const std::string &collectionId,
                                      const std::string &attributeId,
                                      bool required,
                                      const std::string &defaultValue,
                                      const std::vector<std::string> &elements,
                                      int size, std::string &new_key);

    // Document APIs

    /// Create a document in the given collection.
    std::string createDocument(const std::string &databaseId,
                               const std::string &collectionId,
                               const std::string &documentId,
                               const std::string &rawData);

    /// List documents in a collection using query filters.
    std::string listDocument(const std::string &databaseId,
                             const std::string &collectionId, Queries &queries);

    /// Delete a document by ID.
    std::string deleteDocument(const std::string &databaseId,
                               const std::string &collectionId,
                               const std::string &documentId);

    /// Get a document by ID.
    std::string getDocument(const std::string &databaseId,
                            const std::string &collectionId,
                            const std::string &documentId);

    // Index APIs

    /// List all indexes for a collection.
    std::string listIndexes(const std::string &databaseId,
                            const std::string &collectionId);

    /// Create a new index.
    std::string createIndexes(const std::string &databaseId,
                              const std::string &collectionId,
                              const std::string &key, const std::string &type,
                              const std::vector<std::string> &attributes);

    /// Delete an index.
    std::string deleteIndexes(const std::string &databaseId,
                              const std::string &collectionId,
                              const std::string &key);

    /// Get details of a specific index.
    std::string getIndexes(const std::string &databaseId,
                           const std::string &collectionId,
                           const std::string &key);

  private:
    std::string apiKey;    ///< API key for Appwrite authentication
    std::string projectId; ///< Appwrite project ID
};

#endif
