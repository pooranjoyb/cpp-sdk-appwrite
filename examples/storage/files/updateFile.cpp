#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "66fbb5a100070a3a1d19";
    std::string apiKey = "";
    std::string bucketId = "bucketnew";
    std::string fileId = "68065a960022c73ad785";
    std::string name = "pingu123updated";

    Appwrite appwrite(projectId, apiKey);
    std::vector<std::string> permissions = {"read(\"any\")", "write(\"any\")"};

    try {
        std::string response = appwrite.getStorage().updateFile(
            bucketId, fileId, name, permissions);
        std::cout << "Bucket updated successfully! \nResponse: " << response
                  << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
