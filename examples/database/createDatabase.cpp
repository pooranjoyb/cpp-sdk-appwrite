#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "66fbb5a100070a3a1d19";
    std::string apiKey = "";
    std::string databaseId = "database123";
    std::string name = "sampledb";
    bool enabled = true;

    Appwrite appwrite(projectId, apiKey);

    try {
        std::string response = appwrite.getDatabases().create(databaseId, name, enabled);
        std::cout << "Database created successfully! \nResponse: " << response << std::endl;
    } catch (const AppwriteException& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
