#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main() {
    std::ofstream file("random_file.txt"); // Create a file

    // Check if the file is successfully opened
    if (!file) {
        std::cout << "Error creating the file." << std::endl;
        return 1;
    }

    // Generate a random number of lines (between 5 and 10)
    std::srand(std::time(nullptr));
    int numLines = std::rand() % 6 + 5;

    // Fill the file with random lines
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

    int m, n;

    while (true) {
        std::cout << "Enter the value of m (line number to move after): ";

        // Check if the input is a valid integer
        if (!(std::cin >> m)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Check if the user wants to exit
        if (m == 666) {
            break;
        }

        // Check if the line number is out of bounds
        if (m < 1 || m > numLines) {
            std::cout << "Invalid line number. Please enter a number between 1 and " << numLines << "." << std::endl;
            continue;
        }

        std::cout << "Enter the value of n (line number to move): ";

        // Check if the input is a valid integer
        if (!(std::cin >> n)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Check if the user wants to exit
        if (n == 666) {
            break;
        }

        // Check if the line number is out of bounds
        if (n < 1 || n > numLines) {
            std::cout << "Invalid line number. Please enter a number between 1 and " << numLines << "." << std::endl;
            continue;
        }

        // Check if n is already after m
        if (n > m) {
            std::cout << "Line " << n << " is already after line " << m << "." << std::endl;
            continue;
        }

        std::ifstream readFile("random_file.txt");
        std::ofstream writeFile("temp_file.txt");

        int currentLine = 1;

        // Move the lines and write to the temporary file
        while (std::getline(readFile, line)) {
            if (currentLine == m) {
                writeFile << line << std::endl;
                writeFile << "New Line " << n << std::endl;
            } else if (currentLine != n) {
                writeFile << line << std::endl;
            }

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
    }

    return 0;
}
