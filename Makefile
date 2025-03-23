CXX = g++
CXXFLAGS = -std=c++11 -Iinclude
LDFLAGS = -lcurl

SRC_DIR = src
INCLUDE_DIR = include
EXAMPLES_DIR = examples

SRCS = \
    $(SRC_DIR)/Appwrite.cpp \
    $(SRC_DIR)/services/Account.cpp \
    $(SRC_DIR)/services/Databases.cpp \
    $(SRC_DIR)/services/Storage.cpp \
    $(SRC_DIR)/services/Health.cpp \
    $(SRC_DIR)/Utils.cpp \
    $(SRC_DIR)/Validator.cpp \

BINS = \
    createAccount \
    createSession \
    createDatabase \
    updateDatabase \
    getDatabase \
    listDatabase \
	getDatabaseUsage \
	getCollectionUsage \
	listCollection \
    createCollection \
	getCollection \
	updateCollection \
	deleteCollection \
	createDocument \
	listDocument \
	getDocument \
	deleteDocument \
	updateDocument \
	listAttributes \
	createBooleanAttribute \
	createEmailAttribute \
	createEnumAttribute \
	createFloatAttribute \
	createIntegerAttribute \
	createIPaddressAttribute \
	createStringAttribute \
	updateBooleanAttribute \
	updateEmailAttribute \
	updateEnumAttribute \
	updateFloatAttribute \
	updateIntegerAttribute \
	updateIPaddressAttribute \
	updateStringAttribute \
	listIndexes \
	createIndex \
	deleteIndex \
	getIndex \
	createBucket \
	updateBucket \
	listBuckets \
	getBucket \
	deleteBucket \
	getFile \
	getFileView \
	updateFile \
	deleteFile \
	getFileDownload \
	getHealth \
	getAntivirus \
	getCache \
	getDB \
	getPubSub \
	getStorage \
	getStorageLocal \
	getTime \
	getQueue \
	getCertificate \
	getQueueBuilds \
	getQueueCertificates \
	getQueueUsageWebhooks \
	getQueueUsageDump \
	getQueueFunctions \
	getQueueMails \
	getQueueMessaging \
	getQueueMigrations \

# build all binaries
all: $(BINS)

# Account 
createAccount: $(SRCS) $(EXAMPLES_DIR)/account/createAccount.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/account/createAccount $(SRCS) $(EXAMPLES_DIR)/account/createAccount.cpp $(LDFLAGS)
createSession: $(SRCS) $(EXAMPLES_DIR)/account/createSession.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/account/createSession $(SRCS) $(EXAMPLES_DIR)/account/createSession.cpp $(LDFLAGS)

# Database
createDatabase: $(SRCS) $(EXAMPLES_DIR)/database/createDatabase.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/database/createDatabase $(SRCS) $(EXAMPLES_DIR)/database/createDatabase.cpp $(LDFLAGS)
updateDatabase: $(SRCS) $(EXAMPLES_DIR)/database/updateDatabase.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/database/updateDatabase $(SRCS) $(EXAMPLES_DIR)/database/updateDatabase.cpp $(LDFLAGS)
getDatabase: $(SRCS) $(EXAMPLES_DIR)/database/getDatabase.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/database/getDatabase $(SRCS) $(EXAMPLES_DIR)/database/getDatabase.cpp $(LDFLAGS)
listDatabase: $(SRCS) $(EXAMPLES_DIR)/database/listDatabase.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/database/listDatabase $(SRCS) $(EXAMPLES_DIR)/database/listDatabase.cpp $(LDFLAGS)
getDatabaseUsage: $(SRCS) $(EXAMPLES_DIR)/database/getDatabaseUsage.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/database/getDatabaseUsage $(SRCS) $(EXAMPLES_DIR)/database/getDatabaseUsage.cpp $(LDFLAGS)
getCollectionUsage: $(SRCS) $(EXAMPLES_DIR)/database/getCollectionUsage.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/database/getCollectionUsage $(SRCS) $(EXAMPLES_DIR)/database/getCollectionUsage.cpp $(LDFLAGS)

# Database - Collection
listCollection: $(SRCS) $(EXAMPLES_DIR)/database/collection/listCollection.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/collection/listCollection $(SRCS) $(EXAMPLES_DIR)/database/collection/listCollection.cpp $(LDFLAGS)
createCollection: $(SRCS) $(EXAMPLES_DIR)/database/collection/createCollection.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/collection/createCollection $(SRCS) $(EXAMPLES_DIR)/database/collection/createCollection.cpp $(LDFLAGS)
getCollection: $(SRCS) $(EXAMPLES_DIR)/database/collection/getCollection.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/collection/getCollection $(SRCS) $(EXAMPLES_DIR)/database/collection/getCollection.cpp $(LDFLAGS)
updateCollection: $(SRCS) $(EXAMPLES_DIR)/database/collection/updateCollection.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/collection/updateCollection $(SRCS) $(EXAMPLES_DIR)/database/collection/updateCollection.cpp $(LDFLAGS)
deleteCollection: $(SRCS) $(EXAMPLES_DIR)/database/collection/deleteCollection.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/collection/deleteCollection $(SRCS) $(EXAMPLES_DIR)/database/collection/deleteCollection.cpp $(LDFLAGS)

# Database-Collection-Document
createDocument: $(SRCS) $(EXAMPLES_DIR)/database/collection/document/createDocument.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/document/createDocument $(SRCS) $(EXAMPLES_DIR)/database/collection/document/createDocument.cpp $(LDFLAGS)
listDocument: $(SRCS) $(EXAMPLES_DIR)/database/collection/document/listDocument.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/document/listDocument $(SRCS) $(EXAMPLES_DIR)/database/collection/document/listDocument.cpp $(LDFLAGS)
deleteDocument: $(SRCS) $(EXAMPLES_DIR)/database/collection/document/deleteDocument.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/document/deleteDocument $(SRCS) $(EXAMPLES_DIR)/database/collection/document/deleteDocument.cpp $(LDFLAGS)
getDocument: $(SRCS) $(EXAMPLES_DIR)/database/collection/document/getDocument.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/document/getDocument $(SRCS) $(EXAMPLES_DIR)/database/collection/document/getDocument.cpp $(LDFLAGS)
updateDocument: $(SRCS) $(EXAMPLES_DIR)/database/collection/document/updateDocument.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/document/updateDocument $(SRCS) $(EXAMPLES_DIR)/database/collection/document/updateDocument.cpp $(LDFLAGS)

#Collection-Attribute
listAttributes: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/listAttributes.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/listAttributes $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/listAttributes.cpp $(LDFLAGS)
createBooleanAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createBooleanAttribute.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/createBooleanAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createBooleanAttribute.cpp $(LDFLAGS)
createEmailAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createEmailAttribute.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/createEmailAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createEmailAttribute.cpp $(LDFLAGS)
createEnumAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createEnumAttribute.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/createEnumAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createEnumAttribute.cpp $(LDFLAGS)
createFloatAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createFloatAttribute.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/createFloatAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createFloatAttribute.cpp $(LDFLAGS)
createIntegerAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createIntegerAttribute.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/createIntegerAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createIntegerAttribute.cpp $(LDFLAGS)
createIPaddressAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createIPaddressAttribute.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/createIPaddressAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createIPaddressAttribute.cpp $(LDFLAGS)
createStringAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createStringAttribute.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/createStringAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createStringAttribute.cpp $(LDFLAGS)

updateBooleanAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateBooleanAttribute.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/updateBooleanAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateBooleanAttribute.cpp $(LDFLAGS)
updateEmailAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateEmailAttribute.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/updateEmailAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateEmailAttribute.cpp $(LDFLAGS)
updateEnumAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateEnumAttribute.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/updateEnumAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateEnumAttribute.cpp $(LDFLAGS)
updateFloatAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateFloatAttribute.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/updateFloatAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateFloatAttribute.cpp $(LDFLAGS)
updateIntegerAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateIntegerAttribute.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/updateIntegerAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateIntegerAttribute.cpp $(LDFLAGS)
updateIPaddressAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateIPaddressAttribute.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/updateIPaddressAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateIPaddressAttribute.cpp $(LDFLAGS)
updateStringAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateStringAttribute.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/attribute/updateStringAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateStringAttribute.cpp $(LDFLAGS)

# Collection-Indexes
listIndexes: $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/listIndexes.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/indexes/listIndexes $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/listIndexes.cpp $(LDFLAGS)
createIndex: $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/createIndex.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/indexes/createIndex $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/createIndex.cpp $(LDFLAGS)
deleteIndex: $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/deleteIndex.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/indexes/deleteIndex $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/deleteIndex.cpp $(LDFLAGS)
getIndex: $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/getIndex.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/indexes/getIndex $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/getIndex.cpp $(LDFLAGS)

# Storage
createBucket: $(SRCS) $(EXAMPLES_DIR)/storage/createBucket.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/storage/createBucket $(SRCS) $(EXAMPLES_DIR)/storage/createBucket.cpp $(LDFLAGS)
updateBucket: $(SRCS) $(EXAMPLES_DIR)/storage/updateBucket.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/storage/updateBucket $(SRCS) $(EXAMPLES_DIR)/storage/updateBucket.cpp $(LDFLAGS)
listBuckets: $(SRCS) $(EXAMPLES_DIR)/storage/listBuckets.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/storage/listBuckets $(SRCS) $(EXAMPLES_DIR)/storage/listBuckets.cpp $(LDFLAGS)
getBucket: $(SRCS) $(EXAMPLES_DIR)/storage/getBucket.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/storage/getBucket $(SRCS) $(EXAMPLES_DIR)/storage/getBucket.cpp $(LDFLAGS)
deleteBucket: $(SRCS) $(EXAMPLES_DIR)/storage/deleteBucket.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/storage/deleteBucket $(SRCS) $(EXAMPLES_DIR)/storage/deleteBucket.cpp $(LDFLAGS)

# Storage - Files
getFile: $(SRCS) $(EXAMPLES_DIR)/storage/files/getFile.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/storage/files/getFile $(SRCS) $(EXAMPLES_DIR)/storage/files/getFile.cpp $(LDFLAGS)
updateFile: $(SRCS) $(EXAMPLES_DIR)/storage/files/updateFile.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/storage/files/updateFile $(SRCS) $(EXAMPLES_DIR)/storage/files/updateFile.cpp $(LDFLAGS)
deleteFile: $(SRCS) $(EXAMPLES_DIR)/storage/files/deleteFile.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/storage/files/deleteFile $(SRCS) $(EXAMPLES_DIR)/storage/files/deleteFile.cpp $(LDFLAGS)
getFileDownload: $(SRCS) $(EXAMPLES_DIR)/storage/files/getFileDownload.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/storage/files/getFileDownload $(SRCS) $(EXAMPLES_DIR)/storage/files/getFileDownload.cpp $(LDFLAGS)
getFileView: $(SRCS) $(EXAMPLES_DIR)/storage/files/getFileView.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/storage/files/getFileView $(SRCS) $(EXAMPLES_DIR)/storage/files/getFileView.cpp $(LDFLAGS)
createFile: $(SRCS) $(EXAMPLES_DIR)/storage/files/createFile.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/storage/files/createFile $(SRCS) $(EXAMPLES_DIR)/storage/files/createFile.cpp $(LDFLAGS)


# Health
getHealth: $(SRCS) $(EXAMPLES_DIR)/health/getHealth.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/getHealth $(SRCS) $(EXAMPLES_DIR)/health/getHealth.cpp $(LDFLAGS)
getAntivirus: $(SRCS) $(EXAMPLES_DIR)/health/getAntivirus.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/getAntivirus $(SRCS) $(EXAMPLES_DIR)/health/getAntivirus.cpp $(LDFLAGS)
getCache: $(SRCS) $(EXAMPLES_DIR)/health/getCache.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/getCache $(SRCS) $(EXAMPLES_DIR)/health/getCache.cpp $(LDFLAGS)
getDB: $(SRCS) $(EXAMPLES_DIR)/health/getDB.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/getDB $(SRCS) $(EXAMPLES_DIR)/health/getDB.cpp $(LDFLAGS)
getPubSub: $(SRCS) $(EXAMPLES_DIR)/health/getPubSub.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/getPubSub $(SRCS) $(EXAMPLES_DIR)/health/getPubSub.cpp $(LDFLAGS)
getStorage: $(SRCS) $(EXAMPLES_DIR)/health/getStorage.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/getStorage $(SRCS) $(EXAMPLES_DIR)/health/getStorage.cpp $(LDFLAGS)
getStorageLocal: $(SRCS) $(EXAMPLES_DIR)/health/getStorageLocal.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/getStorageLocal $(SRCS) $(EXAMPLES_DIR)/health/getStorageLocal.cpp $(LDFLAGS)
getTime: $(SRCS) $(EXAMPLES_DIR)/health/getTime.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/getTime $(SRCS) $(EXAMPLES_DIR)/health/getTime.cpp $(LDFLAGS)
getQueue: $(SRCS) $(EXAMPLES_DIR)/health/getQueue.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/getQueue $(SRCS) $(EXAMPLES_DIR)/health/getQueue.cpp $(LDFLAGS)
getCertificate: $(SRCS) $(EXAMPLES_DIR)/health/params/getCertificate.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/params/getCertificate $(SRCS) $(EXAMPLES_DIR)/health/params/getCertificate.cpp $(LDFLAGS)
getQueueBuilds: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueBuilds.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/params/getQueueBuilds $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueBuilds.cpp $(LDFLAGS)
getQueueCertificates: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueCertificates.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/params/getQueueCertificates $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueCertificates.cpp $(LDFLAGS)
getQueueUsageWebhooks: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueUsageWebhooks.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/params/getQueueUsageWebhooks $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueUsageWebhooks.cpp $(LDFLAGS)
getQueueUsageDump: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueUsageDump.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/params/getQueueUsageDump $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueUsageDump.cpp $(LDFLAGS)
getQueueFunctions: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueFunctions.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/params/getQueueFunctions $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueFunctions.cpp $(LDFLAGS)
getQueueMails: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueMails.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/params/getQueueMails $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueMails.cpp $(LDFLAGS)
getQueueMessaging: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueMessaging.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/params/getQueueMessaging $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueMessaging.cpp $(LDFLAGS)
getQueueMigrations: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueMigrations.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/health/params/getQueueMigrations $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueMigrations.cpp $(LDFLAGS)
full_flow_test: $(SRCS) $(EXAMPLES_DIR)/full_flow_test.cpp
	$(CXX) $(CXXFLAGS) -o ./tests/full_flow_test $(SRCS) $(EXAMPLES_DIR)/full_flow_test.cpp $(LDFLAGS)