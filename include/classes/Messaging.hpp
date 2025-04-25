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

    std::string getTopic(const std::string &topicId);
    std::string listTopics(Queries &queries);
    std::string deleteTopic(const std::string &topicId);
    std::string createTopic(const std::string &topicId, const std::string &name,
                            const std::vector<std::string> &subscribe);
    std::string getSubscriber(const std::string &topicId,
                              const std::string &subscriberId);
    std::string listSubscribers(const std::string &topicId, Queries &queries);

  private:
    std::string projectId;
    std::string apiKey;
};

#endif
