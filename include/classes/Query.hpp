/// @file Query.hpp
/// @brief Offers helper methods to construct query parameters for filtering and
/// sorting API responses.

#ifndef QUERY_HPP_INCLUDED
#define QUERY_HPP_INCLUDED

#include <cctype>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <type_traits>

/**
 * @class Queries
 * @brief Utility class to construct and manage Appwrite-style database query
 * filters.
 *
 * Provides methods to build query filters like equal, contains, range-based,
 * null checks, and complex queries for Appwrite API requests.
 */
class Queries {
  public:
    /// Constructor
    Queries();

    /**
     * @brief Add a raw JSON complex query.
     * @param jsonQuery A valid Appwrite-style JSON query string.
     */
    void addComplexQuery(const std::string jsonQuery);

    /**
     * @brief Remove a JSON query by index.
     * @param index The index of the query to remove.
     * @return True if the query was removed, false if index is invalid.
     */
    bool removeJsonQuery(int index);

    /**
     * @brief Add a cursor query to paginate after the given document ID.
     * @param documentId The document ID to start after.
     */
    void queryCursorAfter(const std::string documentId);

    /**
     * @brief Limit the number of documents returned.
     * @param limit The maximum number of documents.
     */
    void queryLimit(int limit);

    /**
     * @brief Filter documents where an attribute is null.
     * @param attributeId The attribute key to filter.
     */
    void queryIsNull(const std::string attributeId);

    /**
     * @brief Filter documents where an attribute is not null.
     * @param attributeId The attribute key to filter.
     */
    void queryIsNotNull(const std::string attributeId);

    /**
     * @brief Filter documents where attribute starts with given value.
     * @param attributeId The attribute key.
     * @param value The starting value to match.
     */
    void queryStartsWith(const std::string attributeId,
                         const std::string &value);

    /**
     * @brief Filter documents where attribute ends with given value.
     * @param attributeId The attribute key.
     * @param value The ending value to match.
     */
    void queryEndsWith(const std::string attributeId, const std::string &value);

    /**
     * @brief Filter documents where attribute contains the value.
     * @param attributeId The attribute key.
     * @param value The substring to match.
     */
    void queryContains(const std::string attributeId, const std::string &value);

    /// Resets the internal query list.
    void reset();

    /**
     * @brief Filter documents where attribute contains any value from list.
     * @tparam T Type of values in the list.
     * @param attributeId The attribute key.
     * @param value List of values to check containment.
     */
    template <typename T>
    void queryContains(const std::string attributeId, std::list<T> &value);

    /**
     * @brief Filter documents where attribute is between two values.
     * @tparam T Comparable value type.
     * @param attributeId The attribute key.
     * @param value1 Lower bound.
     * @param value2 Upper bound.
     */
    template <typename T>
    void queryBetween(const std::string attributeId, const T &value1,
                      const T &value2);

    /**
     * @brief Filter documents where attribute is greater than or equal to
     * value.
     * @tparam T Value type.
     * @param attributeId The attribute key.
     * @param value The lower bound.
     */
    template <typename T>
    void queryGreaterThanEqual(const std::string attributeId, const T &value);

    /**
     * @brief Filter documents where attribute is greater than value.
     * @tparam T Value type.
     * @param attributeId The attribute key.
     * @param value The threshold.
     */
    template <typename T>
    void queryGreaterThan(const std::string attributeId, const T &value);

    /**
     * @brief Filter documents where attribute is less than or equal to value.
     * @tparam T Value type.
     * @param attributeId The attribute key.
     * @param value The upper bound.
     */
    template <typename T>
    void queryLessThanEqual(const std::string attributeId, const T &value);

    /**
     * @brief Filter documents where attribute is less than value.
     * @tparam T Value type.
     * @param attributeId The attribute key.
     * @param value The threshold.
     */
    template <typename T>
    void queryLessThan(const std::string attributeId, const T &value);

    /**
     * @brief Filter documents where attribute equals any value in list.
     * @tparam T Value type.
     * @param attributeId The attribute key.
     * @param values List of accepted values.
     */
    template <typename T>
    void queryEqual(const std::string attributeId, std::list<T> &values);

    /**
     * @brief Filter documents where attribute does not equal any value in list.
     * @tparam T Value type.
     * @param attributeId The attribute key.
     * @param values List of disallowed values.
     */
    template <typename T>
    void notEqual(const std::string attributeId, std::list<T> &values);

    /**
     * @brief Select only certain fields from the result.
     * @param values List of field names to return.
     */
    void querySelect(std::list<std::string> &values);

    /**
     * @brief Serialize all added queries into a JSON string.
     * @return Combined query string.
     */
    std::string to_string();

  private:
    /**
     * @brief URL-encode a string for query safety.
     * @param value Raw string.
     * @return Encoded string.
     */
    std::string url_encode(const std::string &value);

    /// Helper template for string values (adds quotes + encodes).
    template <typename T>
    typename std::enable_if<std::is_same<T, std::string>::value, void>::type
    append_encoded(std::ostringstream &oss, const T &iter);

    /// Helper template for non-string values.
    template <typename T>
    typename std::enable_if<!std::is_same<T, std::string>::value, void>::type
    append_encoded(std::ostringstream &oss, const T &iter);

    /// Specialization for C-string literals.
    inline void append_encoded(std::ostringstream &oss, const char *iter);

    /// Convert list to JSON array (no encoding).
    template <typename T> std::string listToStringNoEncode(std::list<T> &ls);

    /// Convert list to JSON array with encoding.
    template <typename T> std::string listToString(std::list<T> &ls);

    // Iterators to update specific queries in-place
    std::list<std::string>::iterator cursor_iter, limit_iter, equal_iter,
        not_equal_iter, sel_iter, less_than_iter, less_than_equal_iter,
        greater_than_iter, greater_than_equal_iter, between_iter, is_null_iter,
        is_not_null_iter, starts_iter, ends_iter, contains_iter;

    /// Internal list of query strings
    std::list<std::string> queries;
};

#endif
