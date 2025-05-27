#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <string>
#include "Utils.hpp"
#include "exceptions/AppwriteException.hpp"
#include "enums/HttpStatus.hpp"


class Storage
{
public:
    Storage(const std::string& projectId, const std::string& apiKey);

    //core
    std::string listBuckets();
    std::string getBucket(std::string &bucketId);
    std::string createBucket(const std::string &bucketId, const std::string &name, const std::vector<std::string> &permissions = {}, bool fileSecurity = false, bool enabled = true, int maximumFileSize = 0, const std::vector<std::string> &allowedFileExtensions = {}, const std::string &compression = "none", bool encryption = false, bool antivirus = false);
    std::string updateBucket(const std::string &bucketId, const std::string &name, const std::vector<std::string> &permissions = {}, bool fileSecurity = false, bool enabled = true, int maximumFileSize = 0, const std::vector<std::string> &allowedFileExtensions = {}, const std::string &compression = "none", bool encryption = false, bool antivirus = false);
    std::string deleteBucket(std::string &bucketId);

    //files
    std::string getFile(const std::string &bucketId, const std::string &fileId);
    std::string getFileView(const std::string &bucketId, const std::string &fileId);
    std::string updateFile(const std::string &bucketId, const std::string &fileId, const std::string &name = "", const std::vector<std::string> &permissions = {});
    std::string deleteFile(const std::string &bucketId, const std::string &fileId);
    std::string getFileDownload(const std::string &bucketId, const std::string &fileId);
    std::string createFile(const std::string &bucketId, const std::string &fileName, const std::string &fileContent, const std::vector<std::string> &permissions);
    
private:
    std::string apiKey;
    std::string projectId;
};

#endif
