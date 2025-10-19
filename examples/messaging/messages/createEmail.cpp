#include "Appwrite.hpp"
#include <chrono>
#include <iostream>

int main() {
    std::string projectId = "";
    std::string apiKey = "";

    Appwrite appwrite(projectId, apiKey);

    std::string messageId = "email001";
    std::string subject = "Hello from C++ Appwrite SDK!";
    std::string content =
        "Testing Email message creation with topics, users, and targets.";

    std::vector<std::string> topics = {};
    std::vector<std::string> users = {};
    std::vector<std::string> targets = {};
    std::vector<std::string> cc = {};
    std::vector<std::string> bcc = {};
    std::vector<std::string> attachments = {};

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
    bool html = false;

    try {
        std::string response = appwrite.getMessaging().createEmail(
            messageId, subject, content, topics, users, targets, cc, bcc,
            attachments, draft, html, scheduled_at);
        std::cout << "Email Message Created!\nResponse: " << response
                  << std::endl;
    } catch (const AppwriteException &ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}