#include "Appwrite.hpp"
#include "classes/Messaging.hpp"
#include <iostream>

int main() {
    std::string projectId = "66fbb5a100070a3a1d19"; 
    std::string apiKey = ""; 
    Appwrite appwrite(projectId, apiKey); 
  
    std::string topicId = "67b3048600077f40b8a7"; 

    Messaging messaging(projectId,apiKey);
    try {

        std::string response = messaging.createPush(
            "push-001",
            "Hello!",
            "This is a push notification.",
            topicId
        );

        std::cout << "Push created: " << response << std::endl;
    } catch (const AppwriteException &e) {
        std::cerr << "Appwrite error: " << e.what() << std::endl;
    }

    return 0;
}
