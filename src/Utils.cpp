#include <curl/curl.h>
#include <string>
#include<iostream>
#include<vector>

namespace Utils {

// Callback function to write the response into the provided string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    size_t totalSize = size * nmemb;
    userp->append((char*)contents, totalSize);
    return totalSize;
}

int postRequest(const std::string& url, const std::string& payload, const std::vector<std::string>& headers, std::string& response) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "cURL initialization failed!" << std::endl;
        return -1;  // Return -1 if initialization fails
    }

    // Set the URL and payload for the POST request
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());

    // Set the headers for the request
    struct curl_slist* chunk = NULL;
    for (const std::string& header : headers) {
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

    if (res != CURLE_OK) {
        std::cerr << "cURL request failed: " << curl_easy_strerror(res) << std::endl;
    }

    // Clean up
    curl_slist_free_all(chunk);
    curl_easy_cleanup(curl);

    return (res == CURLE_OK) ? static_cast<int>(httpCode) : -1;
}

}
