CXX = g++
CXXFLAGS = -std=c++11 -Iinclude
LDFLAGS = -lcurl

SRC_DIR = src
INCLUDE_DIR = include
EXAMPLES_DIR = examples
TESTS_DIR = tests

SRCS = \
    $(SRC_DIR)/Appwrite.cpp \
    $(SRC_DIR)/services/Account.cpp \
    $(SRC_DIR)/services/Databases.cpp \
    $(SRC_DIR)/services/Query.cpp \
    $(SRC_DIR)/services/Storage.cpp \
    $(SRC_DIR)/services/Health.cpp \
    $(SRC_DIR)/services/Messaging.cpp \
    $(SRC_DIR)/Utils.cpp \
    $(SRC_DIR)/Validator.cpp \

# TEST
testSDK: $(SRCS) $(EXAMPLES_DIR)/testSDK.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/testSDK $(SRCS) $(EXAMPLES_DIR)/testSDK.cpp $(LDFLAGS)

# Account 
createAccount: $(SRCS) $(EXAMPLES_DIR)/account/createAccount.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createAccount $(SRCS) $(EXAMPLES_DIR)/account/createAccount.cpp $(LDFLAGS)
createSession: $(SRCS) $(EXAMPLES_DIR)/account/createSession.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createSession $(SRCS) $(EXAMPLES_DIR)/account/createSession.cpp $(LDFLAGS)

# Database
createDatabase: $(SRCS) $(EXAMPLES_DIR)/database/createDatabase.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createDatabase $(SRCS) $(EXAMPLES_DIR)/database/createDatabase.cpp $(LDFLAGS)
updateDatabase: $(SRCS) $(EXAMPLES_DIR)/database/updateDatabase.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/updateDatabase $(SRCS) $(EXAMPLES_DIR)/database/updateDatabase.cpp $(LDFLAGS)
getDatabase: $(SRCS) $(EXAMPLES_DIR)/database/getDatabase.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getDatabase $(SRCS) $(EXAMPLES_DIR)/database/getDatabase.cpp $(LDFLAGS)
listDatabase: $(SRCS) $(EXAMPLES_DIR)/database/listDatabase.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/listDatabase $(SRCS) $(EXAMPLES_DIR)/database/listDatabase.cpp $(LDFLAGS)
getDatabaseUsage: $(SRCS) $(EXAMPLES_DIR)/database/getDatabaseUsage.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getDatabaseUsage $(SRCS) $(EXAMPLES_DIR)/database/getDatabaseUsage.cpp $(LDFLAGS)
getCollectionUsage: $(SRCS) $(EXAMPLES_DIR)/database/getCollectionUsage.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getCollectionUsage $(SRCS) $(EXAMPLES_DIR)/database/getCollectionUsage.cpp $(LDFLAGS)

# Database - Collection
listCollection: $(SRCS) $(EXAMPLES_DIR)/database/collection/listCollection.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/listCollection $(SRCS) $(EXAMPLES_DIR)/database/collection/listCollection.cpp $(LDFLAGS)
createCollection: $(SRCS) $(EXAMPLES_DIR)/database/collection/createCollection.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createCollection $(SRCS) $(EXAMPLES_DIR)/database/collection/createCollection.cpp $(LDFLAGS)
getCollection: $(SRCS) $(EXAMPLES_DIR)/database/collection/getCollection.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getCollection $(SRCS) $(EXAMPLES_DIR)/database/collection/getCollection.cpp $(LDFLAGS)
updateCollection: $(SRCS) $(EXAMPLES_DIR)/database/collection/updateCollection.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/updateCollection $(SRCS) $(EXAMPLES_DIR)/database/collection/updateCollection.cpp $(LDFLAGS)
deleteCollection: $(SRCS) $(EXAMPLES_DIR)/database/collection/deleteCollection.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/deleteCollection $(SRCS) $(EXAMPLES_DIR)/database/collection/deleteCollection.cpp $(LDFLAGS)

# Database-Collection-Document
createDocument: $(SRCS) $(EXAMPLES_DIR)/database/collection/document/createDocument.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createDocument $(SRCS) $(EXAMPLES_DIR)/database/collection/document/createDocument.cpp $(LDFLAGS)
listDocument: $(SRCS) $(EXAMPLES_DIR)/database/collection/document/listDocument.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/listDocument $(SRCS) $(EXAMPLES_DIR)/database/collection/document/listDocument.cpp $(LDFLAGS)
deleteDocument: $(SRCS) $(EXAMPLES_DIR)/database/collection/document/deleteDocument.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/deleteDocument $(SRCS) $(EXAMPLES_DIR)/database/collection/document/deleteDocument.cpp $(LDFLAGS)
getDocument: $(SRCS) $(EXAMPLES_DIR)/database/collection/document/getDocument.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getDocument $(SRCS) $(EXAMPLES_DIR)/database/collection/document/getDocument.cpp $(LDFLAGS)

#Collection-Attribute
listAttributes: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/listAttributes.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/listAttributes $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/listAttributes.cpp $(LDFLAGS)
createBooleanAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createBooleanAttribute.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createBooleanAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createBooleanAttribute.cpp $(LDFLAGS)
createEmailAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createEmailAttribute.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createEmailAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createEmailAttribute.cpp $(LDFLAGS)
createEnumAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createEnumAttribute.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createEnumAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createEnumAttribute.cpp $(LDFLAGS)
createFloatAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createFloatAttribute.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createFloatAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createFloatAttribute.cpp $(LDFLAGS)
createIntegerAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createIntegerAttribute.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createIntegerAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createIntegerAttribute.cpp $(LDFLAGS)
createIPaddressAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createIPaddressAttribute.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createIPaddressAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createIPaddressAttribute.cpp $(LDFLAGS)
createStringAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createStringAttribute.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createStringAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/createStringAttribute.cpp $(LDFLAGS)

updateBooleanAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateBooleanAttribute.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/updateBooleanAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateBooleanAttribute.cpp $(LDFLAGS)
updateEmailAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateEmailAttribute.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/updateEmailAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateEmailAttribute.cpp $(LDFLAGS)
updateEnumAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateEnumAttribute.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/updateEnumAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateEnumAttribute.cpp $(LDFLAGS)
updateFloatAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateFloatAttribute.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/updateFloatAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateFloatAttribute.cpp $(LDFLAGS)
updateIntegerAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateIntegerAttribute.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/updateIntegerAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateIntegerAttribute.cpp $(LDFLAGS)
updateIPaddressAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateIPaddressAttribute.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/updateIPaddressAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateIPaddressAttribute.cpp $(LDFLAGS)
updateStringAttribute: $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateStringAttribute.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/updateStringAttribute $(SRCS) $(EXAMPLES_DIR)/database/collection/attribute/updateStringAttribute.cpp $(LDFLAGS)

# Collection-Indexes
listIndexes: $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/listIndexes.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/listIndexes $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/listIndexes.cpp $(LDFLAGS)
createIndex: $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/createIndex.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createIndex $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/createIndex.cpp $(LDFLAGS)
deleteIndex: $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/deleteIndex.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/deleteIndex $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/deleteIndex.cpp $(LDFLAGS)
getIndex: $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/getIndex.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getIndex $(SRCS) $(EXAMPLES_DIR)/database/collection/indexes/getIndex.cpp $(LDFLAGS)

# Storage
createBucket: $(SRCS) $(EXAMPLES_DIR)/storage/createBucket.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createBucket $(SRCS) $(EXAMPLES_DIR)/storage/createBucket.cpp $(LDFLAGS)
updateBucket: $(SRCS) $(EXAMPLES_DIR)/storage/updateBucket.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/updateBucket $(SRCS) $(EXAMPLES_DIR)/storage/updateBucket.cpp $(LDFLAGS)
listBuckets: $(SRCS) $(EXAMPLES_DIR)/storage/listBuckets.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/listBuckets $(SRCS) $(EXAMPLES_DIR)/storage/listBuckets.cpp $(LDFLAGS)
getBucket: $(SRCS) $(EXAMPLES_DIR)/storage/getBucket.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getBucket $(SRCS) $(EXAMPLES_DIR)/storage/getBucket.cpp $(LDFLAGS)
deleteBucket: $(SRCS) $(EXAMPLES_DIR)/storage/deleteBucket.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/deleteBucket $(SRCS) $(EXAMPLES_DIR)/storage/deleteBucket.cpp $(LDFLAGS)

# Storage - Files
getFile: $(SRCS) $(EXAMPLES_DIR)/storage/files/getFile.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/files/getFile $(SRCS) $(EXAMPLES_DIR)/storage/files/getFile.cpp $(LDFLAGS)
updateFile: $(SRCS) $(EXAMPLES_DIR)/storage/files/updateFile.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/files/updateFile $(SRCS) $(EXAMPLES_DIR)/storage/files/updateFile.cpp $(LDFLAGS)
deleteFile: $(SRCS) $(EXAMPLES_DIR)/storage/files/deleteFile.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/files/deleteFile $(SRCS) $(EXAMPLES_DIR)/storage/files/deleteFile.cpp $(LDFLAGS)
getFileDownload: $(SRCS) $(EXAMPLES_DIR)/storage/files/getFileDownload.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/files/getFileDownload $(SRCS) $(EXAMPLES_DIR)/storage/files/getFileDownload.cpp $(LDFLAGS)
getFileView: $(SRCS) $(EXAMPLES_DIR)/storage/files/getFileView.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/files/getFileView $(SRCS) $(EXAMPLES_DIR)/storage/files/getFileView.cpp $(LDFLAGS)
createFile: $(SRCS) $(EXAMPLES_DIR)/storage/files/createFile.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/files/createFile $(SRCS) $(EXAMPLES_DIR)/storage/files/createFile.cpp $(LDFLAGS)


# Health
getHealth: $(SRCS) $(EXAMPLES_DIR)/health/getHealth.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getHealth $(SRCS) $(EXAMPLES_DIR)/health/getHealth.cpp $(LDFLAGS)
getAntivirus: $(SRCS) $(EXAMPLES_DIR)/health/getAntivirus.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getAntivirus $(SRCS) $(EXAMPLES_DIR)/health/getAntivirus.cpp $(LDFLAGS)
getCache: $(SRCS) $(EXAMPLES_DIR)/health/getCache.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getCache $(SRCS) $(EXAMPLES_DIR)/health/getCache.cpp $(LDFLAGS)
getDB: $(SRCS) $(EXAMPLES_DIR)/health/getDB.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getDB $(SRCS) $(EXAMPLES_DIR)/health/getDB.cpp $(LDFLAGS)
getPubSub: $(SRCS) $(EXAMPLES_DIR)/health/getPubSub.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getPubSub $(SRCS) $(EXAMPLES_DIR)/health/getPubSub.cpp $(LDFLAGS)
getStorage: $(SRCS) $(EXAMPLES_DIR)/health/getStorage.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getStorage $(SRCS) $(EXAMPLES_DIR)/health/getStorage.cpp $(LDFLAGS)
getStorageLocal: $(SRCS) $(EXAMPLES_DIR)/health/getStorageLocal.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getStorageLocal $(SRCS) $(EXAMPLES_DIR)/health/getStorageLocal.cpp $(LDFLAGS)
getTime: $(SRCS) $(EXAMPLES_DIR)/health/getTime.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getTime $(SRCS) $(EXAMPLES_DIR)/health/getTime.cpp $(LDFLAGS)
getQueue: $(SRCS) $(EXAMPLES_DIR)/health/getQueue.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getQueue $(SRCS) $(EXAMPLES_DIR)/health/getQueue.cpp $(LDFLAGS)
getCertificate: $(SRCS) $(EXAMPLES_DIR)/health/params/getCertificate.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/params/getCertificate $(SRCS) $(EXAMPLES_DIR)/health/params/getCertificate.cpp $(LDFLAGS)
getQueueBuilds: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueBuilds.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/params/getQueueBuilds $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueBuilds.cpp $(LDFLAGS)
getQueueCertificates: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueCertificates.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/params/getQueueCertificates $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueCertificates.cpp $(LDFLAGS)
getQueueUsageWebhooks: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueUsageWebhooks.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/params/getQueueUsageWebhooks $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueUsageWebhooks.cpp $(LDFLAGS)
getQueueUsageDump: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueUsageDump.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/params/getQueueUsageDump $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueUsageDump.cpp $(LDFLAGS)
getQueueFunctions: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueFunctions.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/params/getQueueFunctions $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueFunctions.cpp $(LDFLAGS)
getQueueMails: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueMails.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/params/getQueueMails $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueMails.cpp $(LDFLAGS)
getQueueMessaging: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueMessaging.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/params/getQueueMessaging $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueMessaging.cpp $(LDFLAGS)
getQueueMigrations: $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueMigrations.cpp
				@mkdir -p ./$(TESTS_DIR)
				$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/params/getQueueMigrations $(SRCS) $(EXAMPLES_DIR)/health/params/getQueueMigrations.cpp $(LDFLAGS)

# Messaging - Messages
createPush: $(SRCS) $(EXAMPLES_DIR)/messaging/messages/createPush.cpp
	@mkdir -p ./$(TESTS_DIR)
	$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createPush $(SRCS) $(EXAMPLES_DIR)/messaging/messages/createPush.cpp $(LDFLAGS)

listMessages: $(SRCS) $(EXAMPLES_DIR)/messaging/messages/listMessages.cpp
			@mkdir -p ./$(TESTS_DIR)
			$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/listMessages $(SRCS) $(EXAMPLES_DIR)/messaging/messages/listMessages.cpp $(LDFLAGS)
getMessages: $(SRCS) $(EXAMPLES_DIR)/messaging/messages/getMessages.cpp
			@mkdir -p ./$(TESTS_DIR)
			$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getMessages $(SRCS) $(EXAMPLES_DIR)/messaging/messages/getMessages.cpp $(LDFLAGS)
createMessage: $(SRCS) $(EXAMPLES_DIR)/messaging/messages/createMessage.cpp
	@mkdir -p ./$(TESTS_DIR)
	$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createMessage $(SRCS) $(EXAMPLES_DIR)/messaging/messages/createMessage.cpp $(LDFLAGS)

# Messaging - Topics
getTopic: $(SRCS) $(EXAMPLES_DIR)/messaging/topics/getTopic.cpp
			@mkdir -p ./$(TESTS_DIR)
			$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getTopic $(SRCS) $(EXAMPLES_DIR)/messaging/topics/getTopic.cpp $(LDFLAGS)
listTopics: $(SRCS) $(EXAMPLES_DIR)/messaging/topics/listTopics.cpp
			@mkdir -p ./$(TESTS_DIR)
			$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/listTopics $(SRCS) $(EXAMPLES_DIR)/messaging/topics/listTopics.cpp $(LDFLAGS)
deleteTopic: $(SRCS) $(EXAMPLES_DIR)/messaging/topics/deleteTopic.cpp
			@mkdir -p ./$(TESTS_DIR)
			$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/deleteTopic $(SRCS) $(EXAMPLES_DIR)/messaging/topics/deleteTopic.cpp $(LDFLAGS)
createTopic: $(SRCS) $(EXAMPLES_DIR)/messaging/topics/createTopic.cpp
			@mkdir -p ./$(TESTS_DIR)
			$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createTopic $(SRCS) $(EXAMPLES_DIR)/messaging/topics/createTopic.cpp $(LDFLAGS)
updateTopic: $(SRCS) $(EXAMPLES_DIR)/messaging/topics/updateTopic.cpp
			@mkdir -p ./$(TESTS_DIR)
			$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/updateTopic $(SRCS) $(EXAMPLES_DIR)/messaging/topics/updateTopic.cpp $(LDFLAGS)

# Messaging - subscribers
getSubscriber: $(SRCS) $(EXAMPLES_DIR)/messaging/subscribers/getSubscriber.cpp
			@mkdir -p ./$(TESTS_DIR)
			$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/getSubscriber $(SRCS) $(EXAMPLES_DIR)/messaging/subscribers/getSubscriber.cpp $(LDFLAGS)
listSubscribers: $(SRCS) $(EXAMPLES_DIR)/messaging/subscribers/listSubscribers.cpp
			@mkdir -p ./$(TESTS_DIR)
			$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/listSubscribers $(SRCS) $(EXAMPLES_DIR)/messaging/subscribers/listSubscribers.cpp $(LDFLAGS)
deleteSubscribers: $(SRCS) $(EXAMPLES_DIR)/messaging/subscribers/deleteSubscribers.cpp
			@mkdir -p ./$(TESTS_DIR)
			$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/deleteSubscribers $(SRCS) $(EXAMPLES_DIR)/messaging/subscribers/deleteSubscribers.cpp $(LDFLAGS)
createSubscribers: $(SRCS) $(EXAMPLES_DIR)/messaging/subscribers/createSubscribers.cpp
			@mkdir -p ./$(TESTS_DIR)
			$(CXX) $(CXXFLAGS) -o ./$(TESTS_DIR)/createSubscribers $(SRCS) $(EXAMPLES_DIR)/messaging/subscribers/createSubscribers.cpp $(LDFLAGS)