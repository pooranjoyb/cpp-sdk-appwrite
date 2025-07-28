#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "68839412003728db85ef";
    std::string apiKey = "standard_8ff625c3676f021de65f2cbb9b97f89b3a55752cac67b97e8d47cc3f7662cda4024836fa4250e98fbcb11cab69a481b3c390b4fa0acc6441e01777b0c852e61f0c38ec9f76b41268c26cae8674732672ce396d4153804df51c1ffbefe35889852360228a2fbabd156d54967e6162f52b9107e53d73e6b39bc2052133d403ac9b";
    std::string messageId = "6887958c003deaf180a2";

    Appwrite appwrite(projectId, apiKey);

    try {
        std::string response = appwrite.getMessaging().updateMessage(
            messageId,
            "Updated Subject",
            "Updated content for the email message."
        );
        std::cout << "Message Updated!\nResponse: " << response << std::endl;
    } catch (const AppwriteException& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
