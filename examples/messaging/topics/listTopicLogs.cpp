#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "";
    std::string apiKey = "";
    Appwrite appwrite(projectId, apiKey);

    std::string topicId = "";

    std::vector<std::string> queries = {};

    try {
        std::string response = appwrite.getMessaging().listTopicLogs(topicId, queries);

        std::cout << "Topic Logs: " << response << std::endl;
    } catch (const AppwriteException &e) {
        std::cerr << "Appwrite error: " << e.what() << std::endl;
    }
    return 0;
}
