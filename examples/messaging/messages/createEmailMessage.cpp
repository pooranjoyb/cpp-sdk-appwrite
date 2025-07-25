#include "classes/Messaging.hpp"
#include <iostream>

int main() {
    try {
        Messaging messaging("your-project-id", "your-api-key");

        std::string response = messaging.createEmailMessage(
            "Welcome to the platform!",
            "Thank you for signing up. Stay tuned for updates.",
            "welcome-topic-id",
            "admin@example.com",
            "Admin Team"
        );

        std::cout << "Email created: " << response << std::endl;
    } catch (const AppwriteException &e) {
        std::cerr << "Appwrite error: " << e.what() << std::endl;
    }

    return 0;
}
