#include "Appwrite.hpp"
#include <iostream>
int main() {
    std::string projectId = "68853010003a3f4fc106";
    std::string apiKey = "";
    Appwrite appwrite(projectId, apiKey);
    Queries queries;
    queries.queryLimit(50);
    try {
        std::string response = appwrite.getMessaging().listProviders(queries);
        std::cout << "providers fetched! \nResponse: " << response << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}
