/// @file Account.hpp
/// @brief Handles user account-related operations like creation and session
/// management.

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "Utils.hpp"
#include "enums/HttpStatus.hpp"
#include "exceptions/AppwriteException.hpp"
#include <string>

/**
 * @class Account
 * @brief Handles user account-related operations like creation and session
 * management.
 */
class Account {
  public:
    /**
     * @brief Constructs an Account object with a specified project ID.
     * @param projectId The Appwrite project ID.
     */
    explicit Account(const std::string &projectId);

    /**
     * @brief Creates a new user account.
     * @param email User's email address.
     * @param password User's password.
     * @param userId Unique ID for the user.
     * @param name User's display name.
     * @return True if account creation is successful, false otherwise.
     */
    bool createAccount(const std::string &email, const std::string &password,
                       const std::string &userId, const std::string &name);

    /**
     * @brief Creates a new session for a user.
     * @param email User's email address.
     * @param password User's password.
     * @return Session token as a string.
     */
    std::string createSession(const std::string &email,
                              const std::string &password);

  private:
    std::string projectId; ///< The project ID used for API calls.
};

#endif
