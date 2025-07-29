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

    /**
     * @brief List all messages with optional filters.
     * @param queries Query parameters for filtering results
     * @return JSON string of message list
     */
    std::string listMessages(Queries &queries);

    /**
     * @brief Get a specific message by ID.
     * @param messageId ID of the message
     * @return JSON string of the message details
     */
    std::string getMessages(const std::string &messageId);

    /**
     * @brief Get details of a topic by ID.
     * @param topicId ID of the topic
     * @return JSON string of the topic
     */
    std::string getTopic(const std::string &topicId);

    /**
     * @brief List all topics with optional filters.
     * @param queries Query parameters for filtering
     * @return JSON string of topic list
     */
    std::string listTopics(Queries &queries);

    /**
     * @brief Delete a topic by its ID.
     * @param topicId ID of the topic
     * @return JSON response
     */
    std::string deleteTopic(const std::string &topicId);

    /**
     * @brief Create a new topic.
     * @param topicId Unique topic ID
     * @param name Name of the topic
     * @param subscribe List of subscriber IDs
     * @return JSON response
     */
    std::string createTopic(const std::string &topicId, const std::string &name,
                            const std::vector<std::string> &subscribe);

    /**
     * @brief Update an existing topic.
     * @param topicId ID of the topic to update
     * @param name New name for the topic
     * @param subscribe Updated list of subscribers (optional)
     * @return JSON response
     */
    std::string updateTopic(const std::string &topicId, const std::string &name,
                            const std::vector<std::string> &subscribe = {});

    /**
     * @brief Get details of a subscriber to a topic.
     * @param topicId ID of the topic
     * @param subscriberId ID of the subscriber
     * @return JSON string of the subscriber
     */
    std::string getSubscriber(const std::string &topicId,
                              const std::string &subscriberId);

    /**
     * @brief List all subscribers of a topic.
     * @param topicId ID of the topic
     * @param queries Optional query filters
     * @return JSON string of subscriber list
     */
    std::string listSubscribers(const std::string &topicId, Queries &queries);

    /**
     * @brief Delete a subscriber from a topic.
     * @param topicId ID of the topic
     * @param subscriberId ID of the subscriber to remove
     * @return JSON response
     */
    std::string deleteSubscribers(const std::string &topicId,
                                  const std::string &subscriberId);

    /**
     * @brief Add a subscriber to a topic.
     * @param topicId ID of the topic
     * @param name Name of the subscriber
     * @param targetId Target platform/device
     * @param subscriberId Unique ID for the subscriber
     * @return JSON response
     */
    std::string createSubscribers(const std::string &topicId,
                                  const std::string &name,
                                  const std::string &targetId,
                                  const std::string &subscriberId);
    std::string createPush(const std::string &messageId,
                                  const std::string &title,
                                  const std::string &body,
                                  const std::string &topicId);     
    /**
     * @brief Create a new email message.
     * 
     * Sends a new email message to specific topics and/or target recipients.
     * At least one of `topics` or `targets` must be provided.
     *
     * @param messageId Unique ID for the message.
     * @param subject Subject line of the email.
     * @param content Body content of the email.
     * @param topics List of topic IDs to send the message to (optional).
     * @param targets List of target recipients (e.g., email:userId) (optional).
     * @return JSON response.
     */
    std::string createMessage(const std::string& messageId,
                               const std::string& subject,
                               const std::string& content,
                               const std::vector<std::string>& topics = {},
                               const std::vector<std::string>& targets = {});                         

  private:
    std::string projectId; ///< Project ID
    std::string apiKey;    ///< API Key
};

#endif
