#include "classes/Storage.hpp"
#include "Utils.hpp"
#include "Validator.hpp"
#include "config/Config.hpp"
#include "enums/HttpStatus.hpp"
#include "exceptions/AppwriteException.hpp"
#include <iostream>
#include <sstream>

Storage::Storage(const std::string &projectId, const std::string &apiKey)
    : projectId(projectId), apiKey(apiKey) {}

std::string
Storage::createBucket(const std::string &bucketId, const std::string &name,
                      const std::vector<std::string> &permissions,
                      bool fileSecurity, bool enabled, int maximumFileSize,
                      const std::vector<std::string> &allowedFileExtensions,
                      const std::string &compression, bool encryption,
                      bool antivirus) {
    Validator::validateStorageParams(bucketId, name);

    std::string url = Config::API_BASE_URL + "/storage/buckets";

    auto toJsonArray = [](const std::vector<std::string> &vec) {
        std::string result = "[";
        for (const auto &item : vec) {
            result += "\"";

            for (char ch : item) {
                if (ch == '"')
                    result += "\\\"";
                else
                    result += ch;
            }

            result += "\",";
        }
        if (!vec.empty())
            result.pop_back();
        result += "]";
        return result;
    };

    std::string permissionsStr = toJsonArray(permissions);
    std::string extensionsStr = toJsonArray(allowedFileExtensions);

    std::string payload =
        R"({"bucketId":")" + bucketId + R"(","name":")" + name +
        R"(","permissions":)" + permissionsStr + R"(,"fileSecurity":)" +
        (fileSecurity ? "true" : "false") + R"(,"enabled":)" +
        (enabled ? "true" : "false") + R"(,"maximumFileSize":)" +
        std::to_string(maximumFileSize) + R"(,"allowedFileExtensions":)" +
        extensionsStr + R"(,"compression":")" + compression + "\"" +
        R"(,"encryption":)" + (encryption ? "true" : "false") +
        R"(,"antivirus":)" + (antivirus ? "true" : "false") + "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::postRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::CREATED) {
        return response;
    } else {
        throw AppwriteException("Error creating storage bucket. Status code: " +
                                std::to_string(statusCode) +
                                "\n\nResponse: " + response);
    }
}

std::string
Storage::updateBucket(const std::string &bucketId, const std::string &name,
                      const std::vector<std::string> &permissions,
                      bool fileSecurity, bool enabled, int maximumFileSize,
                      const std::vector<std::string> &allowedFileExtensions,
                      const std::string &compression, bool encryption,
                      bool antivirus) {
    Validator::validateStorageParams(bucketId, name);

    std::string url = Config::API_BASE_URL + "/storage/buckets/" + bucketId;

    std::string permissionsStr = "[";
    for (const auto &perm : permissions) {
        permissionsStr += "\"" + Utils::escapeJsonString(perm) + "\",";
    }

    if (!permissions.empty())
        permissionsStr.pop_back();
    permissionsStr += "]";

    std::string extensionsStr = "[";
    for (const auto &ext : allowedFileExtensions) {
        extensionsStr += "\"" + Utils::escapeJsonString(ext) + "\",";
    }

    if (!allowedFileExtensions.empty())
        extensionsStr.pop_back();
    extensionsStr += "]";

    std::string payload =
        R"({"name":")" + Utils::escapeJsonString(name) + R"(",)" +
        R"("permissions":)" + permissionsStr + "," + R"("fileSecurity":)" +
        Utils::boolToString(fileSecurity) + "," + R"("enabled":)" +
        Utils::boolToString(enabled) + "," + R"("maximumFileSize":)" +
        std::to_string(maximumFileSize) + "," + R"("allowedFileExtensions":)" +
        extensionsStr + "," + R"("compression":")" +
        Utils::escapeJsonString(compression) + R"(",)" + R"("encryption":)" +
        Utils::boolToString(encryption) + "," + R"("antivirus":)" +
        Utils::boolToString(antivirus) + "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::putRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error updating storage bucket. Status code: " +
                                std::to_string(statusCode) +
                                "\n\nResponse: " + response);
    }
}

std::string Storage::listBuckets() {

    std::string url = Config::API_BASE_URL + "/storage/buckets/";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error fetching buckets. Status code: " +
                                std::to_string(statusCode) +
                                "\n\nResponse: " + response);
    }
}

std::string Storage::getBucket(std::string &bucketId) {

    Validator::validateStorageParams(bucketId);

    std::string url = Config::API_BASE_URL + "/storage/buckets/" + bucketId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException("Error fetching bucket. Status code: " +
                                std::to_string(statusCode) +
                                "\n\nResponse: " + response);
    }
}

std::string Storage::deleteBucket(std::string &bucketId) {

    Validator::validateStorageParams(bucketId);

    std::string url = Config::API_BASE_URL + "/storage/buckets/" + bucketId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::deleteRequest(url, headers, response);

    if (statusCode == HttpStatus::DELETED) {
        return response;
    } else {
        throw AppwriteException("Error deleting bucket. Status code: " +
                                std::to_string(statusCode) +
                                "\n\nResponse: " + response);
    }
}

std::string Storage::getFile(const std::string &bucketId,
                             const std::string &fileId) {
    Validator::validateStorageParams(bucketId);

    std::string url = Config::API_BASE_URL + "/storage/buckets/" + bucketId +
                      "/files/" + fileId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException(
            "Error fetching file. Status code: " + std::to_string(statusCode) +
            "\n\nResponse: " + response);
    }
}

std::string Storage::getFileView(const std::string &bucketId,
                                 const std::string &fileId) {
    Validator::validateStorageParams(bucketId);

    std::string url = Config::API_BASE_URL + "/storage/buckets/" + bucketId +
                      "/files/" + fileId + "/view";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException(
            "Error fetching file. Status code: " + std::to_string(statusCode) +
            "\n\nResponse: " + response);
    }
}

std::string Storage::getFileDownload(const std::string &bucketId,
                                     const std::string &fileId) {
    Validator::validateStorageParams(bucketId);

    std::string url = Config::API_BASE_URL + "/storage/buckets/" + bucketId +
                      "/files/" + fileId + "/download";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::getRequest(url, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException(
            "Error fetching file. Status code: " + std::to_string(statusCode) +
            "\n\nResponse: " + response);
    }
}

std::string Storage::deleteFile(const std::string &bucketId,
                                const std::string &fileId) {
    Validator::validateStorageParams(bucketId);

    std::string url = Config::API_BASE_URL + "/storage/buckets/" + bucketId +
                      "/files/" + fileId;

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::deleteRequest(url, headers, response);

    if (statusCode == HttpStatus::DELETED) {
        return response;
    } else {
        throw AppwriteException(
            "Error fetching file. Status code: " + std::to_string(statusCode) +
            "\n\nResponse: " + response);
    }
}

std::string Storage::updateFile(const std::string &bucketId,
                                const std::string &fileId,
                                const std::string &name,
                                const std::vector<std::string> &permissions) {
    Validator::validateStorageParams(bucketId, name);

    std::string url = Config::API_BASE_URL + "/storage/buckets/" + bucketId +
                      "/files/" + fileId;

    std::string permissionsStr = "[";
    for (const auto &perm : permissions) {
        permissionsStr += "\"" + Utils::escapeJsonString(perm) + "\",";
    }

    if (!permissions.empty())
        permissionsStr.pop_back();
    permissionsStr += "]";

    std::string payload = R"({"name":")" + Utils::escapeJsonString(name) +
                          R"(",)" + R"("permissions":)" + permissionsStr + "}";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);

    std::string response;

    int statusCode = Utils::putRequest(url, payload, headers, response);

    if (statusCode == HttpStatus::OK) {
        return response;
    } else {
        throw AppwriteException(
            "Error updating file. Status code: " + std::to_string(statusCode) +
            "\n\nResponse: " + response);
    }
}

std::string Storage::createFile(const std::string &bucketId,
                                const std::string &fileName,
                                const std::string &fileContent,
                                const std::vector<std::string> &permissions) {
    Validator::validateStorageParams(bucketId, fileName);

    std::string url =
        Config::API_BASE_URL + "/storage/buckets/" + bucketId + "/files";

    std::string boundary = "----AppwriteBoundary";
    std::ostringstream payload;

    // preparing the multipart-formdata
    payload << "--" << boundary << "\r\n"
            << "Content-Disposition: form-data; name=\"fileId\"\r\n\r\n"
            << fileName << "\r\n";

    payload << "--" << boundary << "\r\n"
            << "Content-Disposition: form-data; name=\"file\"; filename=\""
            << fileName << "\"\r\n"
            << "Content-Type: text/plain\r\n\r\n"
            << fileContent << "\r\n";

    payload << "--" << boundary << "--\r\n";

    std::vector<std::string> headers = Config::getHeaders(projectId);
    headers.push_back("X-Appwrite-Key: " + apiKey);
    headers.push_back("Content-Type: multipart/form-data; boundary=" +
                      boundary);

    std::string response;
    int statusCode = Utils::postRequest(url, payload.str(), headers, response);

    if (statusCode == HttpStatus::OK || statusCode == HttpStatus::CREATED) {
        return response;
    } else {
        throw AppwriteException(
            "Error creating file. Status code: " + std::to_string(statusCode) +
            "\n\nResponse: " + response);
    }
}
