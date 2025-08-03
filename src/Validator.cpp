#include "Validator.hpp"

bool Validator::isValidEmail(const std::string &email) {
    const std::regex pattern(R"(([^@\s]+)@([^\s@]+)\.([^\s@]+))");
    return std::regex_match(email, pattern);
}

bool Validator::isValidPhone(const std::string &phone) {
    const std::regex pattern(R"(^\+\d{1,15}$)");
    return std::regex_match(phone, pattern);
}

void Validator::validateAccountParams(const std::string &email,
                                      const std::string &password,
                                      const std::string &userId) {
    if (!isValidEmail(email)) {
        throw std::invalid_argument("Invalid email format.");
    }
    if (password.length() < 8) {
        throw std::invalid_argument(
            "Password must be at least 8 characters long.");
    }
    if (userId.empty()) {
        throw std::invalid_argument("User ID cannot be empty.");
    }
}

void Validator::validateAccountParams(const std::string &email,
                                      const std::string &password) {
    if (!isValidEmail(email)) {
        throw std::invalid_argument("Invalid email format.");
    }
    if (password.length() < 8) {
        throw std::invalid_argument(
            "Password must be at least 8 characters long.");
    }
}

void Validator::validateDatabaseParams(const std::string &databaseId,
                                       const std::string &name) {
    std::regex databaseIdPattern("^[a-zA-Z0-9][a-zA-Z0-9._-]{0,35}$");

    if (!std::regex_match(databaseId, databaseIdPattern)) {
        throw std::invalid_argument(
            "Invalid databaseId. Must start with an alphanumeric character and "
            "can contain only alphanumeric characters, periods, hyphens, and "
            "underscores, with a max length of 36 characters.");
    }

    if (name.length() > 128) {
        throw std::invalid_argument(
            "Invalid name. Must be 128 characters or less.");
    }
}

void Validator::validateStorageParams(const std::string &bucketId,
                                      const std::string &name) {
    std::regex bucketIdPattern("^[a-zA-Z0-9][a-zA-Z0-9._-]{0,35}$");

    if (!std::regex_match(bucketId, bucketIdPattern)) {
        throw std::invalid_argument(
            "Invalid bucketId. Must start with an alphanumeric character and "
            "can contain only alphanumeric characters, periods, hyphens, and "
            "underscores, with a max length of 36 characters.");
    }

    if (name.empty()) {
        throw std::invalid_argument("Bucket Name is required field.");
    }
}

void Validator::validateStorageParams(const std::string &bucketId) {
    std::regex bucketIdPattern("^[a-zA-Z0-9][a-zA-Z0-9._-]{0,35}$");

    if (!std::regex_match(bucketId, bucketIdPattern)) {
        throw std::invalid_argument(
            "Invalid bucketId. Must start with an alphanumeric character and "
            "can contain only alphanumeric characters, periods, hyphens, and "
            "underscores, with a max length of 36 characters.");
    }
}
