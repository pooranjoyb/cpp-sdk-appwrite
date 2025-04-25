#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "66fbb5a100070a3a1d19";
    std::string apiKey = "";
    Appwrite appwrite(projectId, apiKey);

    std::string topicId = "680ba54a00105c98862f";

    try {
        std::string response = appwrite.getMessaging().deleteTopic(topicId);
        std::cout << "Topic Deleted!" << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
