#include "Appwrite.hpp"
#include <iostream>
int main() {
    std::string projectId = "68853010003a3f4fc106";
    std::string apiKey = "";
    std::string messageId = "";
    try {
        Appwrite appwrite(projectId, apiKey);
        std::string response =
            appwrite.getMessaging().deleteMessages(messageId);
        std::cout << "Message deleted successfully! \nResponse: " << response
                  << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}