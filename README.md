# Appwrite C++ SDK

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=flat-square&logo=c%2B%2B&logoColor=white)
![Appwrite](https://img.shields.io/badge/Appwrite-%23FD366E.svg?style=flat-square&logo=appwrite&logoColor=white)
![GitHub License](https://img.shields.io/github/license/pooranjoyb/cpp-sdk-appwrite?style=flat-square)
![Version](https://img.shields.io/badge/api%20version-1.2.0-blue.svg?style=flat-square)

![banner-appwrite](https://github.com/user-attachments/assets/63e7dbad-6a49-4b80-bee2-8e0a46601eec)

## Overview

This **C++ SDK** is built from scratch as a **prototype** for interacting with Appwrite's backend services. 
- It allows users to perform a limited set of functionalities as of now,
- including the **creation of databases, collections, and documents**,
- while also enabling the **retrieval of usage statistics** and
- management of **storage** and **account health**.

**This SDK is compatible with Appwrite server version 1.6.x.**

![Appwrite](https://github.com/appwrite/appwrite/raw/main/public/images/github.png)


## Installation

### Prerequisites

Before you begin, ensure that you have `conan` & `clang-format` installed on your system. 
- You can install `conan` using `pip`,
- and `clang-format` using `apt`

```bash
sudo apt install clang-format
pip install conan
```

### Build From Source Code

Clone the repository and run the following commands
```bash
mkdir build && cd build
conan install .. --build=missing
cmake ..
make
```

Install the SDK.
```bash
sudo make install
```

## Getting Started

### Make Your First Request

Set the neccessary header files.
```cpp
#include "AppwriteSDK/Appwrite.hpp"
```
Once your SDK header is set, create the Appwrite service objects and choose the request to send.
```cpp
    std::string projectId = "<your-project-id>";
    std::string apiKey = "<your-api-key>"; 

    Appwrite appwrite(projectId, apiKey);

    // for the Databases instance
    Databases& databases = appwrite.getDatabases();
```

### Full Example
```cpp
#include "Appwrite.hpp"
#include <iostream>

int main() {
    std::string projectId = "<your-project-id>";
    std::string apiKey = "<your-api-key>"; 
    std::string databaseId = "<unique-database-id>";
    std::string name = "<unique-database-name>";
    bool enabled = true;

    Appwrite appwrite(projectId, apiKey);
    
    std::string response = appwrite.getDatabases().create(databaseId, name, enabled);

    return 0;
}    

```
### Error Handling

The Appwrite C++ SDK raises `AppwriteException` object with `message`, `code` and `response` properties. You can handle any errors by catching `AppwriteException` and present the `message` to the user or handle it yourself based on the provided error information. Below is an example.

```cpp
    try {
        // Send some request here
    } catch (const AppwriteException& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
```

### Compilation & Execution

- ### Compile
```bash
g++ -o <output-file-name> <your-file-name>.cpp -I/usr/local/include/AppwriteSDK -L/usr/local/lib -lAppwriteSDK -lcurl
```

- ### Execute
```bash
./output-file-name
```

For a more detailed view of the implementations, please check out the example directory. [Example](/examples/)

### Learn more
You can use the following resources to learn more and get help
- 🚀 [Getting Started Tutorial](https://www.youtube.com/watch?v=L1D-Ibe7XeU)
- 📜 [C++ SDK Docs](/docs)


## License 
This project is licensed under the MIT License, and further details can be found in the [LICENSE](LICENSE) file.
