#include <curl/curl.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

namespace Utils
{

    // Callback function to write the response into the provided string
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *userp)
    {
        size_t totalSize = size * nmemb;
        userp->append((char *)contents, totalSize);
        return totalSize;
    }

    int postRequest(const std::string &url, const std::string &payload, const std::vector<std::string> &headers, std::string &response)
    {
        CURL *curl = curl_easy_init();
        if (!curl)
        {
            std::cerr << "cURL initialization failed!" << std::endl;
            return -1; // Return -1 if initialization fails
        }

        // Set the URL and payload for the POST request
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());

        // Set the headers for the request
        struct curl_slist *chunk = NULL;
        for (const std::string &header : headers)
        {
            chunk = curl_slist_append(chunk, header.c_str());
        }
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

        // Set up the response handling
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the request and check for errors
        CURLcode res = curl_easy_perform(curl);
        long httpCode = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode); // Get the HTTP response code

        if (res != CURLE_OK)
        {
            std::cerr << "cURL request failed: " << curl_easy_strerror(res) << std::endl;
        }

        // Clean up
        curl_slist_free_all(chunk);
        curl_easy_cleanup(curl);

        return (res == CURLE_OK) ? static_cast<int>(httpCode) : -1;
    }

    int getRequest(const std::string &url, const std::vector<std::string> &headers, std::string &response)
    {
        CURL *curl = curl_easy_init();
        if (!curl)
        {
            std::cerr << "cURL initialization failed!" << std::endl;
            return -1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        struct curl_slist *chunk = NULL;
        for (const std::string &header : headers)
        {
            chunk = curl_slist_append(chunk, header.c_str());
        }
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

        // Setting up response handling
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Performing the GET request
        CURLcode res = curl_easy_perform(curl);
        long httpCode = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

        if (res != CURLE_OK)
        {
            std::cerr << "cURL request failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_slist_free_all(chunk);
        curl_easy_cleanup(curl);

        return (res == CURLE_OK) ? static_cast<int>(httpCode) : -1;
    }

    int putRequest(const std::string &url, const std::string &payload, const std::vector<std::string> &headers, std::string &response)
    {
        CURL *curl = curl_easy_init();
        if (!curl)
        {
            std::cerr << "cURL initialization failed!" << std::endl;
            return -1; // Return -1 if initialization fails
        }

        // Set the URL and payload for the PUT request
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());

        // Set the headers for the request
        struct curl_slist *chunk = NULL;
        for (const std::string &header : headers)
        {
            chunk = curl_slist_append(chunk, header.c_str());
        }
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

        // Set up the response handling
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the request and check for errors
        CURLcode res = curl_easy_perform(curl);
        long httpCode = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode); // Get the HTTP response code

        if (res != CURLE_OK)
        {
            std::cerr << "cURL request failed: " << curl_easy_strerror(res) << std::endl;
        }

        // Clean up
        curl_slist_free_all(chunk);
        curl_easy_cleanup(curl);

        return (res == CURLE_OK) ? static_cast<int>(httpCode) : -1;
    }

    int patchRequest(const std::string &url, const std::string &payload, const std::vector<std::string> &headers, std::string &response)
    {
        CURL *curl = curl_easy_init();
        if (!curl)
        {
            std::cerr << "cURL initialization failed!" << std::endl;
            return -1; // Return -1 if initialization fails
        }

        // Set the URL and payload for the PATCH request
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PATCH");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());

        // Set the headers for the request
        struct curl_slist *chunk = NULL;
        for (const std::string &header : headers)
        {
            chunk = curl_slist_append(chunk, header.c_str());
        }
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

        // Set up the response handling
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the request and check for errors
        CURLcode res = curl_easy_perform(curl);
        long httpCode = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode); // Get the HTTP response code

        if (res != CURLE_OK)
        {
            std::cerr << "cURL request failed: " << curl_easy_strerror(res) << std::endl;
        }

        // Clean up
        curl_slist_free_all(chunk);
        curl_easy_cleanup(curl);

        return (res == CURLE_OK) ? static_cast<int>(httpCode) : -1;
    }

    int deleteRequest(const std::string &url, const std::vector<std::string> &headers, std::string &response)
    {
        CURL *curl = curl_easy_init();
        if (!curl)
        {
            std::cerr << "cURL initialization failed!" << std::endl;
            return -1;
        }

        // Set the URL for the DELETE request
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");

        // Set the headers for the request
        struct curl_slist *chunk = NULL;
        for (const std::string &header : headers)
        {
            chunk = curl_slist_append(chunk, header.c_str());
        }
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

        // Set up the response handling
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the request
        CURLcode res = curl_easy_perform(curl);
        long httpCode = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode); // Get the HTTP response code

        // Error handling
        if (res != CURLE_OK)
        {
            std::cerr << "cURL request failed: " << curl_easy_strerror(res) << std::endl;
            return -1;
        }

        // Clean up
        curl_slist_free_all(chunk);
        curl_easy_cleanup(curl);

        return static_cast<int>(httpCode);
    }

    std::string urlEncode(const std::string &value)
    {
        std::ostringstream escaped;
        escaped << std::hex << std::setfill('0');

        for (char c : value)
        {
            if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~')
            {
                escaped << c;
            }
            else
            {
                escaped << '%' << std::setw(2) << (static_cast<int>(c) & 0xFF);
            }
        }

        return escaped.str();
    }

    std::string escapeJsonString(const std::string &input)
    {
        std::ostringstream ss;
        for (auto c : input)
        {
            switch (c)
            {
            case '\"':
                ss << "\\\"";
                break;
            case '\\':
                ss << "\\\\";
                break;
            case '\b':
                ss << "\\b";
                break;
            case '\f':
                ss << "\\f";
                break;
            case '\n':
                ss << "\\n";
                break;
            case '\r':
                ss << "\\r";
                break;
            case '\t':
                ss << "\\t";
                break;
            default:
                if ('\x00' <= c && c <= '\x1f')
                {
                    ss << "\\u"
                       << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(c);
                }
                else
                {
                    ss << c;
                }
            }
        }
        return ss.str();
    }
}
