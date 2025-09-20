#include "Appwrite.hpp"
#include <chrono>
#include <iostream>

int main() {
    std::string projectId = "";
    std::string apiKey = "";

    Appwrite appwrite(projectId, apiKey);

    std::string messageId = "6b309k4016e14b8";
    std::string subject = "Hello from C++ Appwrite SDK!";
    std::string content =
        "Testing SMS message creation with topics, users, and targets.";

    std::vector<std::string> topics = {};
    std::vector<std::string> users = {};
    std::vector<std::string> targets = {};

    auto now = std::chrono::system_clock::now();
    auto future_time = now + std::chrono::minutes(5);
    auto time_t = std::chrono::system_clock::to_time_t(future_time);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                  future_time.time_since_epoch()) %
              1000;

    std::stringstream ss;
    ss << std::put_time(std::gmtime(&time_t), "%Y-%m-%dT%H:%M:%S");
    ss << "." << std::setfill('0') << std::setw(3) << ms.count() << "+00:00";
    std::string scheduled_at = ss.str();

    bool draft = true;

    try {
        std::string response = appwrite.getMessaging().createSms(
            messageId, content, topics, users, targets, draft, scheduled_at);
        std::cout << "SMS Message Created!\nResponse: " << response
                  << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}