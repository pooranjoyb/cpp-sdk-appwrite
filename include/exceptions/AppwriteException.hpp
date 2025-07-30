/// @file AppwriteException.hpp
/// @brief Declares the base exception class used to represent Appwrite SDK
/// errors.
#ifndef APPWRITEEXCEPTION_HPP
#define APPWRITEEXCEPTION_HPP

#include <exception>
#include <string>

class AppwriteException : public std::exception {
  public:
    explicit AppwriteException(const std::string &message) : message(message) {}
    const char *what() const noexcept override { return message.c_str(); }

  private:
    std::string message;
};

#endif
