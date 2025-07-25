/// @file Messaging.hpp
/// @brief Provides messaging-related operations (messages, topics, subscribers)
#ifndef MESSAGING_HPP
#define MESSAGING_HPP

#include "Query.hpp"
#include "Utils.hpp"
#include "enums/HttpStatus.hpp"
#include "exceptions/AppwriteException.hpp"
#include <string>

/**
 * @class Messaging
 * @brief Provides APIs to manage messaging: messages, topics, subscribers.
 */
class Messaging {
  public:
    /**
     * @brief Constructor for Messaging service.
     * @param projectId Appwrite project ID
     * @param apiKey Appwrite API key
     */
    Messaging(const std::string &projectId, const std::string &apiKey);

    std::string listMessages(Queries &queries);
    std::string getMessages(const std::string &messageId);

    std::string getTopic(const std::string &topicId);
    std::string listTopics(Queries &queries);
    std::string deleteTopic(const std::string &topicId);
    std::string createTopic(const std::string &topicId, const std::string &name,
                            const std::vector<std::string> &subscribe);
    std::string updateTopic(const std::string &topicId, const std::string &name,
                            const std::vector<std::string> &subscribe = {});

    std::string getSubscriber(const std::string &topicId,
                              const std::string &subscriberId);
    std::string listSubscribers(const std::string &topicId, Queries &queries);
    std::string deleteSubscribers(const std::string &topicId,
                                  const std::string &subscriberId);
    std::string createSubscribers(const std::string &topicId,
                                  const std::string &name,
                                  const std::string &targetId,
                                  const std::string &subscriberId);

  private:
    std::string projectId; ///< Project ID
    std::string apiKey;    ///< API Key
};

#endif