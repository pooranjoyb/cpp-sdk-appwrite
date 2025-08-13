#include "Appwrite.hpp"
#include <iostream>
int main() {
    std::string projectId = "68853010003a3f4fc106";
    std::string apiKey = "";
    std::string providerId = "689a4547001864da9330";
    try {
        Messaging messaging(projectId, apiKey);
        std::string response = messaging.getProvider(providerId);
        std::cout << "provider Fetched!\nResponse: " << response << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}