#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "68853010003a3f4fc106";
    std::string apiKey = "";
    std::string messageId = "68878905002f6e61ff07";

    try {
        Messaging messaging(projectId, apiKey);
        std::string response = messaging.deleteMessages(messageId);
        std::cout << "Message Fetched!\nResponse: " << response << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
