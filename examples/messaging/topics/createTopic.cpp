#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "66fbb5a100070a3a1d19";
    std::string apiKey = "";
    Appwrite appwrite(projectId, apiKey);

    std::string topicId = "test_123";
    std::string name = "pingu_123";
    std::vector<std::string> subscribe = {"users"};

    try {
        std::string response = appwrite.getMessaging().createTopic(topicId, name, subscribe);
        std::cout << "Topic Created! \nResponse: " << response << std::endl;
    } catch (const AppwriteException& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
