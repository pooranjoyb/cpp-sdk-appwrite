#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "66fbb5a100070a3a1d19";
    std::string apiKey = ""; 
    std::string databaseId = "database123";
    std::string collectionId = "test1234";
    std::string attributeId = "IPA123"; 
    bool required = true;  
    std::string defaultValue = "";

    Appwrite appwrite(projectId);
    Databases& databases = appwrite.getDatabases();
    
    databases.setup(apiKey, projectId);

    try {
        std::string response = databases.createIPaddressAttribute(databaseId, collectionId, attributeId, required, defaultValue);
        std::cout << "IP Addresss attribute created successfully! \nResponse: " << response << std::endl;
    } catch (const AppwriteException& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
