#ifndef MESSAGING_HPP
#define MESSAGING_HPP

#include "Query.hpp"
#include "Utils.hpp"
#include "enums/HttpStatus.hpp"
#include "exceptions/AppwriteException.hpp"
#include <string>

class Messaging {
  public:
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
    std::string createPush(const std::string &messageId,
                                  const std::string &title,
                                  const std::string &body,
                                  const std::string &topicId);                              

  private:
    std::string projectId;
    std::string apiKey;
};

#endif
