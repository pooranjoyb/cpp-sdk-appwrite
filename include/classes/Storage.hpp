/// @file Storage.hpp
/// @brief Manages file storage operations like upload, download, delete, and
/// preview.
#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "Utils.hpp"
#include "enums/HttpStatus.hpp"
#include "exceptions/AppwriteException.hpp"
#include <string>

/**
 * @class Storage
 * @brief Provides methods to interact with Appwrite's Storage service.
 *
 * Enables management of buckets and files including creation, retrieval,
 * update, and deletion.
 */
class Storage {
  public:
    /**
     * @brief Constructs the Storage client with given project ID and API key.
     * @param projectId The unique identifier of the Appwrite project.
     * @param apiKey The secret API key for authentication.
     */
    Storage(const std::string &projectId, const std::string &apiKey);

    /**
     * @brief Lists all buckets in the project.
     * @return JSON string containing the list of buckets.
     */
    std::string listBuckets();

    /**
     * @brief Retrieves metadata of a specific bucket.
     * @param bucketId ID of the bucket to retrieve.
     * @return JSON string containing bucket details.
     */
    std::string getBucket(std::string &bucketId);

    /**
     * @brief Creates a new storage bucket.
     *
     * @param bucketId Unique ID for the bucket.
     * @param name Name of the bucket.
     * @param permissions Optional permissions list.
     * @param fileSecurity Flag for enabling file-level security.
     * @param enabled Enables or disables the bucket.
     * @param maximumFileSize Optional max file size limit.
     * @param allowedFileExtensions Optional list of allowed file extensions.
     * @param compression Compression type ("none", "gzip", etc.).
     * @param encryption Enable server-side encryption.
     * @param antivirus Enable antivirus scanning.
     * @return JSON string with creation response.
     */
    std::string
    createBucket(const std::string &bucketId, const std::string &name,
                 const std::vector<std::string> &permissions = {},
                 bool fileSecurity = false, bool enabled = true,
                 int maximumFileSize = 0,
                 const std::vector<std::string> &allowedFileExtensions = {},
                 const std::string &compression = "none",
                 bool encryption = false, bool antivirus = false);

    /**
     * @brief Updates an existing storage bucket.
     *
     * @param bucketId Unique ID of the bucket.
     * @param name New name for the bucket.
     * @param permissions Updated permissions list.
     * @param fileSecurity Updated file-level security flag.
     * @param enabled Whether the bucket is enabled.
     * @param maximumFileSize Updated max file size limit.
     * @param allowedFileExtensions Updated list of allowed extensions.
     * @param compression Updated compression type.
     * @param encryption Toggle encryption.
     * @param antivirus Toggle antivirus.
     * @return JSON string with update response.
     */
    std::string
    updateBucket(const std::string &bucketId, const std::string &name,
                 const std::vector<std::string> &permissions = {},
                 bool fileSecurity = false, bool enabled = true,
                 int maximumFileSize = 0,
                 const std::vector<std::string> &allowedFileExtensions = {},
                 const std::string &compression = "none",
                 bool encryption = false, bool antivirus = false);

    /**
     * @brief Deletes a storage bucket.
     * @param bucketId ID of the bucket to delete.
     * @return JSON response string.
     */
    std::string deleteBucket(std::string &bucketId);

    /**
     * @brief Retrieves metadata of a specific file.
     * @param bucketId Bucket ID where file is stored.
     * @param fileId Unique file identifier.
     * @return JSON string containing file metadata.
     */
    std::string getFile(const std::string &bucketId, const std::string &fileId);

    /**
     * @brief Returns a file preview URL.
     * @param bucketId Bucket ID.
     * @param fileId File ID.
     * @return URL string for viewing the file.
     */
    std::string getFileView(const std::string &bucketId,
                            const std::string &fileId);

    /**
     * @brief Updates file metadata and permissions.
     * @param bucketId Bucket ID.
     * @param fileId File ID.
     * @param name New name for the file (optional).
     * @param permissions New permissions list.
     * @return JSON response string.
     */
    std::string updateFile(const std::string &bucketId,
                           const std::string &fileId,
                           const std::string &name = "",
                           const std::vector<std::string> &permissions = {});

    /**
     * @brief Deletes a file from the bucket.
     * @param bucketId Bucket ID.
     * @param fileId File ID.
     * @return JSON response string.
     */
    std::string deleteFile(const std::string &bucketId,
                           const std::string &fileId);

    /**
     * @brief Returns a downloadable URL for a file.
     * @param bucketId Bucket ID.
     * @param fileId File ID.
     * @return URL string for downloading the file.
     */
    std::string getFileDownload(const std::string &bucketId,
                                const std::string &fileId);

    /**
     * @brief Uploads a file to the specified bucket.
     * @param bucketId Target bucket ID.
     * @param fileName Name to give the file.
     * @param fileContent File content (base64 or raw).
     * @param permissions Optional permissions list.
     * @return JSON response string.
     */
    std::string createFile(const std::string &bucketId,
                           const std::string &fileName,
                           const std::string &fileContent,
                           const std::vector<std::string> &permissions);

  private:
    std::string apiKey;    /**< The API key for accessing Appwrite. */
    std::string projectId; /**< The Appwrite project identifier. */
};

#endif
