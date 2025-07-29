/// @file Databases.hpp
/// @brief Provides database management APIs: databases, collections,
/// attributes, documents, and indexes.

#ifndef DATABASES_HPP
#define DATABASES_HPP

#include "Utils.hpp"
#include "classes/Query.hpp"
#include "enums/HttpStatus.hpp"
#include "exceptions/AppwriteException.hpp"
#include <string>

/**
 * @class Databases
 * @brief Provides CRUD operations for databases, collections, documents,
 * attributes, and indexes.
 */
class Databases {
  public:
    /**
     * @brief Constructor for Databases class.
     * @param projectId Appwrite project ID.
     * @param apiKey Appwrite API key.
     */
    Databases(const std::string &projectId, const std::string &apiKey);

    // ------------------- Database APIs -------------------

    /**
     * @brief List all databases.
     * @return JSON string of database list.
     */
    std::string list();

    /**
     * @brief Get a database by ID.
     * @param databaseId Unique ID of the database.
     * @return JSON string of the database.
     */
    std::string get(const std::string &databaseId);

    /**
     * @brief Create a new database.
     * @param databaseId Unique ID for the new database.
     * @param name Name of the database.
     * @param enabled Whether the database is active.
     * @return JSON response of created database.
     */
    std::string create(const std::string &databaseId, const std::string &name,
                       bool enabled);

    /**
     * @brief Update an existing database.
     * @param databaseId ID of the database to update.
     * @param name New name of the database.
     * @param enabled Enable or disable the database.
     * @return JSON response.
     */
    std::string update(const std::string &databaseId, const std::string &name,
                       bool enabled);

    /**
     * @brief Get usage statistics of a database.
     * @param databaseId ID of the database.
     * @param range Time range for usage stats.
     * @return JSON usage data.
     */
    std::string getDatabaseUsage(const std::string &databaseId,
                                 const std::string &range);

    /**
     * @brief Get usage stats of a collection.
     * @param databaseId ID of the database.
     * @param collectionId ID of the collection.
     * @param range Time range for usage.
     * @return JSON usage data.
     */
    std::string getCollectionUsage(const std::string &databaseId,
                                   const std::string &collectionId,
                                   const std::string &range);

    // ------------------- Collection APIs -------------------

    /**
     * @brief List all collections in a database.
     * @param databaseId ID of the database.
     * @return JSON string of collections.
     */
    std::string listCollection(const std::string &databaseId);

    /**
     * @brief Create a new collection.
     * @param databaseId ID of the database.
     * @param collectionId Unique ID for the collection.
     * @param name Name of the collection.
     * @param enabled Whether the collection is enabled.
     * @return JSON response.
     */
    std::string createCollection(const std::string &databaseId,
                                 const std::string &collectionId,
                                 const std::string &name, bool enabled);

    /**
     * @brief Get a collection by ID.
     * @param databaseId ID of the database.
     * @param collectionId ID of the collection.
     * @return JSON string of collection details.
     */
    std::string getCollection(const std::string &databaseId,
                              const std::string &collectionId);

    /**
     * @brief Update collection metadata.
     * @param databaseId ID of the database.
     * @param collectionId ID of the collection.
     * @param name New name of the collection.
     * @param enabled New status of the collection.
     * @return JSON response.
     */
    std::string updateCollection(const std::string &databaseId,
                                 const std::string &collectionId,
                                 const std::string &name, bool enabled);

    /**
     * @brief Delete a collection by ID.
     * @param databaseId ID of the database.
     * @param collectionId ID of the collection.
     * @return JSON response.
     */
    std::string deleteCollection(const std::string &databaseId,
                                 const std::string &collectionId);

    // ------------------- Attribute APIs -------------------

    /**
     * @brief List all attributes in a collection.
     * @param databaseId ID of the database.
     * @param collectionId ID of the collection.
     * @return JSON list of attributes.
     */
    std::string listAttributes(const std::string &databaseId,
                               const std::string &collectionId);

    /**
     * @brief Create a boolean attribute.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param attributeId Unique ID for the attribute.
     * @param defaultValue Default value of the attribute.
     * @param required Whether this field is required.
     * @return JSON response.
     */
    std::string createBooleanAttribute(const std::string &databaseId,
                                       const std::string &collectionId,
                                       const std::string &attributeId,
                                       bool defaultValue, bool required);

    /**
     * @brief Create an email attribute.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param attributeId Attribute ID.
     * @param required Required field.
     * @param defaultValue Default email.
     * @return JSON response.
     */
    std::string createEmailAttribute(const std::string &databaseId,
                                     const std::string &collectionId,
                                     const std::string &attributeId,
                                     bool required,
                                     const std::string &defaultValue);

    /**
     * @brief Create an enum attribute.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param attributeId Attribute ID.
     * @param required Required field.
     * @param defaultValue Default value.
     * @param elements Valid enum values.
     * @return JSON response.
     */
    std::string createEnumAttribute(const std::string &databaseId,
                                    const std::string &collectionId,
                                    const std::string &attributeId,
                                    bool required,
                                    const std::string &defaultValue,
                                    const std::vector<std::string> &elements);

    /**
     * @brief Create a float attribute.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param attributeId Attribute ID.
     * @param required Required field.
     * @param min Minimum value.
     * @param max Maximum value.
     * @param defaultValue Default float value.
     * @return JSON response.
     */
    std::string createFloatAttribute(const std::string &databaseId,
                                     const std::string &collectionId,
                                     const std::string &attributeId,
                                     bool required, double min, double max,
                                     const std::string &defaultValue);

    /**
     * @brief Create an integer attribute.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param attributeId Attribute ID.
     * @param required Required field.
     * @param min Minimum value.
     * @param max Maximum value.
     * @param defaultValue Default integer value.
     * @return JSON response.
     */
    std::string createIntegerAttribute(const std::string &databaseId,
                                       const std::string &collectionId,
                                       const std::string &attributeId,
                                       bool required, int min, int max,
                                       const std::string &defaultValue);

    /**
     * @brief Create an IP address attribute.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param attributeId Attribute ID.
     * @param required Required field.
     * @param defaultValue Default IP address.
     * @return JSON response.
     */
    std::string createIPaddressAttribute(const std::string &databaseId,
                                         const std::string &collectionId,
                                         const std::string &attributeId,
                                         bool required,
                                         const std::string &defaultValue);

    /**
     * @brief Create a string attribute.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param attributeId Attribute ID.
     * @param required Required field.
     * @param defaultValue Default string value.
     * @param elements Allowed string values (for enum-like behavior).
     * @param size Maximum length of the string.
     * @return JSON response.
     */
    std::string createStringAttribute(const std::string &databaseId,
                                      const std::string &collectionId,
                                      const std::string &attributeId,
                                      bool required,
                                      const std::string &defaultValue,
                                      const std::vector<std::string> &elements,
                                      int size);

    /**
     * @brief Update a boolean attribute.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param attributeId Attribute ID.
     * @param defaultValue New default value.
     * @param required Required field.
     * @param new_key New key for the attribute.
     * @return JSON response.
     */
    std::string updateBooleanAttribute(const std::string &databaseId,
                                       const std::string &collectionId,
                                       const std::string &attributeId,
                                       bool defaultValue, bool required,
                                       const std::string &new_key);

    /**
     * @brief Update an email attribute.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param attributeId Attribute ID.
     * @param required Required field.
     * @param defaultValue New default email.
     * @param new_key New key for the attribute.
     * @return JSON response.
     */
    std::string updateEmailAttribute(const std::string &databaseId,
                                     const std::string &collectionId,
                                     const std::string &attributeId,
                                     bool required,
                                     const std::string &defaultValue,
                                     std::string &new_key);

    /**
     * @brief Update an enum attribute.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param attributeId Attribute ID.
     * @param required Required field.
     * @param defaultValue New default value.
     * @param elements Allowed values.
     * @param new_key New key for the attribute.
     * @return JSON response.
     */
    std::string updateEnumAttribute(const std::string &databaseId,
                                    const std::string &collectionId,
                                    const std::string &attributeId,
                                    bool required,
                                    const std::string &defaultValue,
                                    const std::vector<std::string> &elements,
                                    std::string &new_key);

    /**
     * @brief Update a float attribute.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param attributeId Attribute ID.
     * @param required Required field.
     * @param min Minimum value.
     * @param max Maximum value.
     * @param defaultValue New default value.
     * @param new_key New key for the attribute.
     * @return JSON response.
     */
    std::string updateFloatAttribute(const std::string &databaseId,
                                     const std::string &collectionId,
                                     const std::string &attributeId,
                                     bool required, double min, double max,
                                     const std::string &defaultValue,
                                     std::string &new_key);

    /**
     * @brief Update an integer attribute.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param attributeId Attribute ID.
     * @param required Required field.
     * @param min Minimum value.
     * @param max Maximum value.
     * @param defaultValue New default value.
     * @param new_key New key for the attribute.
     * @return JSON response.
     */
    std::string updateIntegerAttribute(const std::string &databaseId,
                                       const std::string &collectionId,
                                       const std::string &attributeId,
                                       bool required, int min, int max,
                                       const std::string &defaultValue,
                                       std::string &new_key);

    /**
     * @brief Update an IP address attribute.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param attributeId Attribute ID.
     * @param required Required field.
     * @param defaultValue New default IP address.
     * @param new_key New key for the attribute.
     * @return JSON response.
     */
    std::string updateIPaddressAttribute(const std::string &databaseId,
                                         const std::string &collectionId,
                                         const std::string &attributeId,
                                         bool required,
                                         const std::string &defaultValue,
                                         const std::string &new_key);

    /**
     * @brief Update a string attribute.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param attributeId Attribute ID.
     * @param required Required field.
     * @param defaultValue New default value.
     * @param elements Allowed string values.
     * @param size Maximum length.
     * @param new_key New key for the attribute.
     * @return JSON response.
     */
    std::string updateStringAttribute(const std::string &databaseId,
                                      const std::string &collectionId,
                                      const std::string &attributeId,
                                      bool required,
                                      const std::string &defaultValue,
                                      const std::vector<std::string> &elements,
                                      int size, std::string &new_key);

    // ------------------- Document APIs -------------------

    /**
     * @brief Create a document in a collection.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param documentId Document ID.
     * @param rawData JSON string of document data.
     * @return JSON response.
     */
    std::string createDocument(const std::string &databaseId,
                               const std::string &collectionId,
                               const std::string &documentId,
                               const std::string &rawData);

    /**
     * @brief List documents using queries.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param queries Filter and sort queries.
     * @return JSON string of documents.
     */
    std::string listDocument(const std::string &databaseId,
                             const std::string &collectionId, Queries &queries);

    /**
     * @brief Delete a document by ID.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param documentId Document ID.
     * @return JSON response.
     */
    std::string deleteDocument(const std::string &databaseId,
                               const std::string &collectionId,
                               const std::string &documentId);

    /**
     * @brief Get a document by ID.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param documentId Document ID.
     * @return JSON string of document.
     */
    std::string getDocument(const std::string &databaseId,
                            const std::string &collectionId,
                            const std::string &documentId);

    // ------------------- Index APIs -------------------

    /**
     * @brief List all indexes in a collection.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @return JSON string of indexes.
     */
    std::string listIndexes(const std::string &databaseId,
                            const std::string &collectionId);

    /**
     * @brief Create a new index.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param key Index key name.
     * @param type Index type.
     * @param attributes Fields to index.
     * @return JSON response.
     */
    std::string createIndexes(const std::string &databaseId,
                              const std::string &collectionId,
                              const std::string &key, const std::string &type,
                              const std::vector<std::string> &attributes);

    /**
     * @brief Delete an index.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param key Index key.
     * @return JSON response.
     */
    std::string deleteIndexes(const std::string &databaseId,
                              const std::string &collectionId,
                              const std::string &key);

    /**
     * @brief Get details of an index.
     * @param databaseId Database ID.
     * @param collectionId Collection ID.
     * @param key Index key.
     * @return JSON string of index details.
     */
    std::string getIndexes(const std::string &databaseId,
                           const std::string &collectionId,
                           const std::string &key);

  private:
    std::string apiKey;    ///< API key for Appwrite authentication
    std::string projectId; ///< Appwrite project ID
};

#endif
