#include "Appwrite.hpp"
#include <iostream>
#include <string>

int main() {
    std::string projectId = "66fbb5a100070a3a1d19";
    std::string apiKey = "";
    std::string databaseId = "database123";
    std::string collectionId = "test1234";
    std::string documentId = "document1231";

    std::string rawData = R"({
        "new_email_attribute": "pou@email.com",
        "new_enum_attribute": ["element1234"],
        "UpdatedFloat123": 9.0,
        "UpdatedInteger123": 123,
        "UpdatedIPaddress123": "192.168.1.1",
        "UpdatedString123": ["abc", "def"]
    })";

    Appwrite appwrite(projectId, apiKey);

    try {
        std::string response = appwrite.getDatabases().createDocument(
            databaseId, collectionId, documentId, rawData);
        std::cout << "Document created successfully!\nResponse: " << response
                  << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
