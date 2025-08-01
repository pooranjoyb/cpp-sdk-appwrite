#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "66fbb5a100070a3a1d19";
    std::string apiKey = "";
    std::string messageId = "67b30694001dc16a7eb8";

    Appwrite appwrite(projectId, apiKey);

    Queries queries;
    queries.queryLimit(50);

    try {
        std::string response =
            appwrite.getMessaging().listMessageLogs(messageId, queries);
        std::cout << "Message logs fetched! \nResponse: " << response
                  << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
