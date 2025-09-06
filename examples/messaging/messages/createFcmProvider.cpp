#include "Appwrite.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
int main() {
    std::string projectId = "68853010003a3f4fc106";
    std::string apiKey = "";
    std::string providerId = "68a22c7b00325882e4e5";
    std::string name = "";
    std::ifstream file("");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string service_account_json = buffer.str();
    bool enabled = true;
    try {
        Messaging messaging(projectId, apiKey);
        std::string response = messaging.createFcmProvider(
            providerId, name, service_account_json, enabled);
        std::cout << "FCM Provider Created!\nResponse: " << response << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}
