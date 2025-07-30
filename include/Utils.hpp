/// @file Utils.hpp
/// @brief Provides utility functions and helpers used across the SDK.

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

/**
 * @class Utils
 * @brief Provides static utility functions for HTTP requests and data
 * formatting.
 */
class Utils {
  public:
    /**
     * @brief Make an HTTP POST request.
     *
     * @param url Endpoint URL.
     * @param payload JSON payload to send.
     * @param headers List of HTTP headers.
     * @param response Output string to store server response.
     * @return int HTTP response code.
     */
    static int postRequest(const std::string &url, const std::string &payload,
                           const std::vector<std::string> &headers,
                           std::string &response);

    /**
     * @brief Make an HTTP PUT request.
     *
     * @param url Endpoint URL.
     * @param payload JSON payload to send.
     * @param headers List of HTTP headers.
     * @param response Output string to store server response.
     * @return int HTTP response code.
     */
    static int putRequest(const std::string &url, const std::string &payload,
                          const std::vector<std::string> &headers,
                          std::string &response);

    /**
     * @brief Make an HTTP PATCH request.
     *
     * @param url Endpoint URL.
     * @param payload JSON payload to send.
     * @param headers List of HTTP headers.
     * @param response Output string to store server response.
     * @return int HTTP response code.
     */
    static int patchRequest(const std::string &url, const std::string &payload,
                            const std::vector<std::string> &headers,
                            std::string &response);

    /**
     * @brief Make an HTTP GET request.
     *
     * @param url Endpoint URL.
     * @param headers List of HTTP headers.
     * @param response Output string to store server response.
     * @return int HTTP response code.
     */
    static int getRequest(const std::string &url,
                          const std::vector<std::string> &headers,
                          std::string &response);

    /**
     * @brief Make an HTTP DELETE request.
     *
     * @param url Endpoint URL.
     * @param headers List of HTTP headers.
     * @param response Output string to store server response.
     * @return int HTTP response code.
     */
    static int deleteRequest(const std::string &url,
                             const std::vector<std::string> &headers,
                             std::string &response);

    /**
     * @brief URL-encode a string.
     *
     * @param value Input string.
     * @return std::string URL-encoded string.
     */
    static std::string urlEncode(const std::string &value);

    /**
     * @brief Escape special characters in a JSON string.
     *
     * @param input Input string.
     * @return std::string Escaped JSON string.
     */
    static std::string escapeJsonString(const std::string &input);

    /**
     * @brief Convert a boolean to a string ("true"/"false").
     *
     * @param value Boolean value.
     * @return std::string "true" or "false".
     */
    static std::string boolToString(bool value);
};

#endif
