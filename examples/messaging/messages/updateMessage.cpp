#include "classes/Messaging.hpp"
#include <iostream>

int main() {
    std::string projectId = "<your-project-id>";
    std::string apiKey = "<your-api-key>";
    std::string messageId = "<existing-message-id>";

    Messaging messaging(projectId, apiKey);

    try {
        std::string updated = messaging.updateMessage(
            messageId,
            "New subject from C++ SDK",
            "Updated content body using updateMessage()"
        );

        std::cout << "Message updated: " << updated << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Appwrite error: " << ex.what() << std::endl;
    }

    return 0;
}
