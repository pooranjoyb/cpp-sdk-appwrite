#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "<your_project_id>";  
    std::string apiKey = "<your_api_key>";

    Appwrite appwrite(projectId, apiKey);   

    std::string messageId = "<your_message_id>";
    std::string subject = "Hello from C++ Appwrite SDK!";
    std::string content = "Testing email message creation with topics and targets.";

    std::vector<std::string> topics = {"<topic_id>"};     
    std::vector<std::string> targets = {"<target_id>"};   

    try {
        std::string response = appwrite.getMessaging().createMessage(
            messageId, subject, content, topics, targets
        );
        std::cout << "Email Message Created!\nResponse: " << response << std::endl;
    } catch (const AppwriteException& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}