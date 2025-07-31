#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "68853010003a3f4fc106";
    std::string apiKey = "";
    std::string messageId = "688bb84e000a793a646f";
    Appwrite appwrite(projectId, apiKey);

    Queries queries;
    queries.queryLimit(50);

    try {
        std::string response =
            appwrite.getMessaging().listMessageLogs(messageId, queries);
        std::cout << "Message logs fetched successfully! \nResponse: " << response
                  << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
