#include "Appwrite.hpp"
#include <iostream>
int main() {
    std::string projectId = "68853010003a3f4fc106";
    std::string apiKey = "";
    std::string providerId = "68a22c7b00325882e4e5";
    try {
        Messaging messaging(projectId, apiKey);
        std::string response = messaging.deleteProvider(providerId);
        std::cout << "provider deleted!\nResponse: " << response << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}
