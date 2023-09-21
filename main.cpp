#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Define the file name
    std::string filename = "example.txt";

    // Open the file for reading and writing
    std::fstream file(filename, std::ios::in | std::ios::out | std::ios::app);

    // Check if the file exists
    if (!file.is_open()) {
        std::cout << "File does not exist. Creating it..." << std::endl;

        // Create the file if it doesn't exist
        file.open(filename, std::ios::out);

        // Check if the file creation was successful
        if (!file.is_open()) {
            std::cerr << "Failed to create the file." << std::endl;
            return 1;
        }
    }

    // Read and display the file content
    std::string line;
    std::cout << "File content:" << std::endl;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    // Clear the end-of-file flag and return to the beginning of the file
    file.clear();
    file.seekg(0, std::ios::beg);

    // Write data to the file
    std::string data = "This is a new line written to the file. 1";
    file << data << std::endl;

    // Close the file
    file.close();

    // Check the file size
    std::ifstream checkSizeFile(filename);
    if (checkSizeFile.is_open()) {
        checkSizeFile.seekg(0, std::ios::end); // Move to the end of the file
        std::streampos fileSize = checkSizeFile.tellg(); // Get the file size
        checkSizeFile.close();
        std::cout << "File size: " << fileSize << " bytes" << std::endl;
    } else {
        std::cerr << "Failed to check the file size." << std::endl;
        return 1;
    }

    return 0;
}
