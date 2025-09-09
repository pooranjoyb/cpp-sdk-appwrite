#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "6884bd56002f5a20341f";
    std::string apiKey = "standard_31ceb812f9444de5efc0991fdcfe1c67af3717ff4aebb85bf82f5c76c386d5854c259cfee4f68c139ccc6fa19b85b3f9f4541449dd77971e6a1114373c5c8d911b88fce9e24456446108b54c2262813c8b3d2badb80e81824f3f31a76beb12281ce1faa61a03189791255f4d5e1762dcf8f6c922e4b8a8197d56902a148914de";
    Appwrite appwrite(projectId, apiKey);

    std::string topicId = "6884bde100084222e873";

    std::vector<std::string> queries = {};

    try {
        std::string response = appwrite.getMessaging().listTopicLogs(topicId, queries);

        std::cout << "Topic Logs: " << response << std::endl;
    } catch (const AppwriteException &e) {
        std::cerr << "Appwrite error: " << e.what() << std::endl;
    }
    return 0;
}
