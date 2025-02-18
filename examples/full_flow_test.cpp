#include "Appwrite.hpp"
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;

Account account;
Databases databases;

void displayMenu() {
  std::cout << "\n=== Appwrite C++ SDK Test Menu ===\n";
  std::cout << "1. Create Account\n";
  std::cout << "2. Create Session\n";
  std::cout << "3. List Databases\n";
  std::cout << "4. List Collections\n";
  std::cout << "5. Create Collection\n";
  std::cout << "6. Create Email Attribute\n";
  std::cout << "7. List Documents\n";
  std::cout << "8. List Attributes\n";
  std::cout << "9. Create Document\n";
  std::cout << "10. Create Index\n";
  std::cout << "11. Exit\n";
  std::cout << "Enter your choice: ";
}

void handleCreateAccount() {
  std::string email = "test@example.com";
  std::string password = "securePassword";
  std::string userId = "uniqueUserId";
  std::string name = "Test User";

  bool success = account.createAccount(email, password, userId, name);
  std::cout << (success ? "Account created successfully.\n"
                        : "Failed to create account.\n");
}

void handleCreateSession() {
  std::string email = "test@example.com";
  std::string password = "securePassword";

  std::string sessionId = account.createSession(email, password);
  if (!sessionId.empty()) {
    std::cout << "Session created successfully. Session ID: " << sessionId
              << "\n";
  } else {
    std::cout << "Failed to create session.\n";
  }
}

void handleListDatabases() {
  std::string response = databases.list();
  std::cout << "Databases:\n" << response << "\n";
}

void handleListCollections() {
  std::string databaseId = "database123";
  std::string response = databases.listCollection(databaseId);
  std::cout << "Collections:\n" << response << "\n";
}

void handleCreateCollection() {
  std::string databaseId = "database123";
  std::string collectionId = "test1234collectionnew";
  std::string name = "Sample Collection";
  bool enabled = true;

  std::string response =
      databases.createCollection(databaseId, collectionId, name, enabled);
  std::cout << "Collection Creation Response:\n" << response << "\n";
}

void handleCreateEmailAttribute() {
  std::string databaseId = "database123";
  std::string collectionId = "test1234collectionnew";
  std::string attributeId = "email";
  bool required = true;
  std::string defaultValue = "";

  std::string response = databases.createEmailAttribute(
      databaseId, collectionId, attributeId, required, defaultValue);
  std::cout << "Email Attribute Creation Response:\n" << response << "\n";
}

void handleListDocuments() {
  std::string databaseId = "database123";
  std::string collectionId = "test1234collectionnew";

  std::string response = databases.listDocument(databaseId, collectionId);
  std::cout << "Documents:\n" << response << "\n";
}

void handleListAttributes() {
  std::string databaseId = "database123";
  std::string collectionId = "test1234collectionnew";

  std::string response = databases.listAttributes(databaseId, collectionId);
  std::cout << "Attributes:\n" << response << "\n";
}

void handleCreateDocument() {
  std::string databaseId = "database123";
  std::string collectionId = "test1234collectionnew";
  std::string documentId = "sampleDocumentId";

  json data = {{"email", "test@example.com"}};

  std::string response =
      databases.createDocument(databaseId, collectionId, documentId, data);
  std::cout << "Document Creation Response:\n" << response << "\n";
}

void handleCreateIndex() {
  std::string databaseId = "database123";
  std::string collectionId = "test1234collectionnew";
  std::string key = "indexKey";
  std::string type = "unique";
  std::vector<std::string> attributes = {"email"};

  std::string response =
      databases.createIndexes(databaseId, collectionId, key, type, attributes);
  std::cout << "Index Creation Response:\n" << response << "\n";
}

int main() {
  std::string projectId = "66fbb5a100070a3a1d19";
  std::string apiKey = "";

  account.setup(projectId);
  databases.setup(apiKey, projectId);

  int choice;
  do {
    displayMenu();
    std::cin >> choice;
    switch (choice) {
    case 1:
      handleCreateAccount();
      break;
    case 2:
      handleCreateSession();
      break;
    case 3:
      handleListDatabases();
      break;
    case 4:
      handleListCollections();
      break;
    case 5:
      handleCreateCollection();
      break;
    case 6:
      handleCreateEmailAttribute();
      break;
    case 7:
      handleListDocuments();
      break;
    case 8:
      handleListAttributes();
      break;
    case 9:
      handleCreateDocument();
      break;
    case 10:
      handleCreateIndex();
      break;
    case 11:
      std::cout << "Exiting program.\n";
      break;
    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 11);

  return 0;
}
