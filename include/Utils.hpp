#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

class Utils {
public:
    static int postRequest(const std::string& url, const std::string& payload, const std::vector<std::string>& headers, std::string& response);
    static int putRequest(const std::string& url, const std::string& payload, const std::vector<std::string>& headers, std::string& response);
    static int patchRequest(const std::string& url, const std::string& payload, const std::vector<std::string>& headers, std::string& response);
    static int getRequest(const std::string& url, const std::vector<std::string>& headers, std::string& response);
    static int deleteRequest(const std::string &url, const std::vector<std::string> &headers, std::string &response);
    static std::string urlEncode(const std::string& value);
    static std::string escapeJsonString(const std::string &input);
    static std::string boolToString (bool value);
};

#endif
