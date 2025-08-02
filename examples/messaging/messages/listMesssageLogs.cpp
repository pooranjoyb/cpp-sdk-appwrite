#include "Appwrite.hpp"
#include <iostream>
int main() {
    std::string projectId = "68853010003a3f4fc106";
    std::string apiKey = "standard_"
        "50c2aa7697484afc2eeda7d9c289df216a2498d8dee455a6fc7c5a0d7ae477600dd349"
        "6490784034269349bb21d571f16749abf550f4f32cc3c1e8eee5d7314cd1105288cffc"
        "c4e33e31a7008cbd29f9046a676e848cf51d383eb7259a96394764141206777d2e701b"
        "d985d345fcc1c1601659e277669155580dba56908569e7";
    std::string messageId = "688e98ba00107a10f041";
    Appwrite appwrite(projectId, apiKey);
    Queries queries;
    queries.queryLimit(50);
    try {
        std::string response = appwrite.getMessaging().listMessageLogs(messageId,queries);
        std::cout << "Message logs fetched! \nResponse: " << response << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}
