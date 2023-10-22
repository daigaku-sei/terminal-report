#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <filesystem>

int main() {
    // Ask user for file path
    std::string filePath;
    while (true) {
        std::cout << "Enter the path to the file (666 to quit): ";
        std::getline(std::cin, filePath);
        if (filePath.empty() || filePath == "666") {
            break;
        }
        // Check if file exists
        if (!std::filesystem::exists(filePath)) {
            std::cout << "File not found: " << filePath << std::endl;
            filePath.clear();
        }
    }
    if (filePath.empty()) {
        return 0; // User entered 666
    }

    // Open file and read contents
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cout << "Error opening file: " << filePath << std::endl;
        return 1;
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    // Ask user for line numbers
    int n, m;
    while (true) {
        std::cout << "Enter the value of n (line number to move): ";
        std::cin >> n;
        if (n < 1 || n > lines.size()) {
            std::cout << "Invalid line number. Please enter a number between 1 and " << lines.size() << "." << std::endl;
            continue;
        }
        std::cout << "Enter the value of m (line number to move after): ";
