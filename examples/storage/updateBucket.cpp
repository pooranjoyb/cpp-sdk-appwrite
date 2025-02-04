#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "66fbb5a100070a3a1d19";
    std::string apiKey = "";
    std::string bucketId = "bucket12322";
    std::string name = "testBucketupdated";

    Appwrite appwrite(projectId, apiKey);
    
    std::vector<std::string> permissions = {"read(\"any\")", "write(\"any\")"};
    bool fileSecurity = false;
    bool enabled = true;
    int maximumFileSize = 30000000;
    std::vector<std::string> allowedFileExtensions = {"jpg", "png"};
    std::string compression = "gzip";
    bool antivirus = true;
    bool encryption = false;

    try {
        std::string response = appwrite.getStorage().updateBucket(
            bucketId, 
            name, 
            permissions, 
            fileSecurity, 
            enabled, 
            maximumFileSize, 
            allowedFileExtensions, 
            compression, 
            encryption, 
            antivirus
        );
        std::cout << "Bucket updated successfully! \nResponse: " << response << std::endl;
    } catch (const AppwriteException& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
