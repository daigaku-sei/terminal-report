#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
// to be improved
int main() {
    std::ofstream file("random_file.txt"); // Create a file
    int numLines = 10; // Number of lines

    // Write ordered lines to the file
    for (int i = 1; i <= numLines; i++) {
        file << "Line " << i << std::endl;
    }
    file.close(); // Close the file

    // Read and display the contents of the file
    std::ifstream readFile("random_file.txt");
    std::string line;

    std::cout << "Contents of the file:" << std::endl;
    while (std::getline(readFile, line)) {
        std::cout << line << std::endl;
    }
    readFile.close(); // Close the file

    int n, m;

    std::cout << "Enter the value of n (line number to move): ";
    std::cin >> n;

    std::cout << "Enter the value of m (line number to move after): ";
    std::cin >> m;

    // Check if the line numbers are valid
    if (n < 1 || n > numLines || m < 1 || m > numLines) {
        std::cout << "Invalid line numbers. Please enter numbers between 1 and " << numLines << "." << std::endl;
        return 1;
    }

    // Check if n is already after m
    if (n >= m) {
        std::cout << "Line " << n << " is already after line " << m << "." << std::endl;
        return 1;
    }

    std::ifstream readFile("random_file.txt");
    std::ofstream writeFile("temp_file.txt");

    int currentLine = 1;

    // Move the lines and write to the temporary file
    while (std::getline(readFile, line)) {
        if (currentLine == m) {
            writeFile << "Line " << n << std::endl;
        }

        if (currentLine != n) {
            writeFile << line << std::endl;
        }

        writeFile << line << std::endl;

        currentLine++;
    }

    readFile.close();
    writeFile.close();

    std::remove("random_file.txt");
    std::rename("temp_file.txt", "random_file.txt");
    std::cout << "Line " << n << " has been placed after line " << m << "." << std::endl;

    // Read and display the updated contents of the file
    std::ifstream updatedFile("random_file.txt");

    std::cout << "Updated contents of the file:" << std::endl;
    while (std::getline(updatedFile, line)) {
        std::cout << line << std::endl;
    }
    updatedFile.close();

    return 0;
}
