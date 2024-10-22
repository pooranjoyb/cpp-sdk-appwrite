#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "66fbb5a100070a3a1d19";
    std::string apiKey = "";
    std::string threshold = "5";

    Appwrite appwrite(projectId);
    Health& health = appwrite.getHealth();
    
    health.setup(apiKey, projectId);

    try {
        std::string response = health.getQueueMails(threshold);
        std::cout << "Health Check Done! \nResponse: " << response << std::endl;
    } catch (const AppwriteException& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}