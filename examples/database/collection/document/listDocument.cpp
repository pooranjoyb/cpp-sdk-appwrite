#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "66fbb5a100070a3a1d19";
    std::string apiKey = ""; 
    std::string databaseId = "database123";
    std::string collectionId = "test1234";

    Appwrite appwrite(projectId, apiKey);

    try {
        Queries queries;
		queries.queryLimit(50);
        std::string response = appwrite.getDatabases().listDocument(databaseId, collectionId, queries);
        std::cout << "Documents listed successfully! \nResponse: " << response << std::endl;
    } catch (const AppwriteException& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
