#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "<your_project_id>";
    std::string apiKey = "<your_api_key>";

    Appwrite appwrite(projectId, apiKey);

    std::string recipient = "<recipient_number>";   // e.g., +911234567890
    std::string message   = "Hello from C++ Appwrite SDK! (SMS Test)";

    try {
        std::string response = appwrite.getMessaging().createSms(
            recipient, message
        );
        std::cout << "SMS Message Created!\nResponse: " << response << std::endl;
    } catch (const AppwriteException& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
