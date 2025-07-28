/// @file Validator.hpp
/// @brief Contains input validation logic for arguments passed to SDK methods.

#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include <regex>
#include <stdexcept>
#include <string>

/**
 * @class Validator
 * @brief Provides static validation methods for common input parameters.
 */
class Validator {
  public:
    /**
     * @brief Validates an email address using a regular expression.
     *
     * @param email Email string to validate.
     * @return true if email is valid, false otherwise.
     */
    static bool isValidEmail(const std::string &email);

    /**
     * @brief Validates a phone number using a regular expression.
     *
     * @param phone Phone number string to validate.
     * @return true if phone number is valid, false otherwise.
     */
    static bool isValidPhone(const std::string &phone);

    /**
     * @brief Validates email, password, and user ID for account creation.
     *
     * @param email User's email.
     * @param password User's password.
     * @param userId Unique user ID.
     *
     * @throws std::invalid_argument if any parameter is invalid.
     */
    static void validateAccountParams(const std::string &email,
                                      const std::string &password,
                                      const std::string &userId);

    /**
     * @brief Validates email and password for account login or creation.
     *
     * @param email User's email.
     * @param password User's password.
     *
     * @throws std::invalid_argument if any parameter is invalid.
     */
    static void validateAccountParams(const std::string &email,
                                      const std::string &password);

    /**
     * @brief Validates database ID and name for database creation or updates.
     *
     * @param databaseId Unique ID of the database.
     * @param name Name of the database.
     *
     * @throws std::invalid_argument if any parameter is invalid.
     */
    static void validateDatabaseParams(const std::string &databaseId,
                                       const std::string &name);

    /**
     * @brief Validates both bucket ID and name for storage bucket operations.
     *
     * @param bucketId ID of the storage bucket.
     * @param name Name of the bucket.
     *
     * @throws std::invalid_argument if any parameter is invalid.
     */
    static void validateStorageParams(const std::string &bucketId,
                                      const std::string &name);

    /**
     * @brief Validates only the bucket ID for basic storage operations.
     *
     * @param bucketId ID of the storage bucket.
     *
     * @throws std::invalid_argument if the bucket ID is invalid.
     */
    static void validateStorageParams(const std::string &bucketId);
};

#endif
