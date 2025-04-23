#ifndef MESSAGING_HPP
#define MESSAGING_HPP

#include "Utils.hpp"
#include "enums/HttpStatus.hpp"
#include "exceptions/AppwriteException.hpp"
#include <string>

class Messaging {
  public:
    Messaging(const std::string &projectId, const std::string &apiKey);

    std::string getTopic(const std::string &topicId);
    std::string createTopic(const std::string &topicId, const std::string &name,
                            const std::vector<std::string> &subscribe);

  private:
    std::string projectId;
    std::string apiKey;
};

#endif
