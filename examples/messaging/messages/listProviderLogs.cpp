#include "Appwrite.hpp"
#include <iostream>
int main() {
    std::string projectId = "68853010003a3f4fc106";
    std::string apiKey = "";
    std::string providerId = "68bf146d003761d36496";
    Appwrite appwrite(projectId, apiKey);
    Queries queries;
    queries.queryLimit(50);
    try {
        std::string response =
            appwrite.getMessaging().listProviderLogs(providerId, queries);
        std::cout << "provider logs fetched! \nResponse: " << response
                  << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}