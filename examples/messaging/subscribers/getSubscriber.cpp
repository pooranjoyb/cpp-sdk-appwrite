#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "66fbb5a100070a3a1d19";
    std::string apiKey = "";
    Appwrite appwrite(projectId, apiKey);

    std::string topicId = "67b3048600077f40b8a7";
    std::string subscriberId = "67b3065e001584698384";

    try {
        std::string response =
            appwrite.getMessaging().getSubscriber(topicId, subscriberId);
        std::cout << "Subscriber Fetched! \nResponse: " << response
                  << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
