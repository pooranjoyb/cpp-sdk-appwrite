/// @file Config.hpp
/// @brief Contains configuration settings such as endpoint, project ID, and
/// authentication keys.

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <vector>

namespace Config {
const std::string API_BASE_URL = "https://cloud.appwrite.io/v1";
static std::vector<std::string> getHeaders(const std::string &projectId) {
    return {"Content-Type: application/json", "Accept: application/json",
            "X-Appwrite-Project: " + projectId};
}
} // namespace Config

#endif
