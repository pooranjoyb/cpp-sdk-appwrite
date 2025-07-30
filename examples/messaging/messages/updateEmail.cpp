#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "<project-id>";
    std::string apiKey = "<api-key>";

    Appwrite appwrite(projectId, apiKey);

    std::string messageId = "<existing-email-message-id>";
    std::string subject = "Updated Subject from C++";
    std::string content = "Updated content of the email from C++ SDK.";

    try {
        std::string response = appwrite.getMessaging().updateEmail(
            messageId, subject, content
        );
        std::cout << "Email Message Updated!\nResponse: " << response << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
