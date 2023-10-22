#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int getInputAsInt() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    int value;
    if (ss >> value) {
        return value;
    } else {
        throw std::runtime_error("Invalid input. Please enter a valid integer.");
    }
}

int main() {
    int num_lines = 10;
    std::cout << "Type 666 at some point to exit" << std::endl;

    // Write ordered lines to the file
    std::ofstream file("random_file.txt");
    for (int i = 1; i <= num_lines; i++) {
        file << "Line " << i << std::endl;
    }
    file.close();

    // Read and display the contents of the file
    std::ifstream readFile1("random_file.txt");
    std::cout << "Contents of the file:" << std::endl;
    std::string line;
    while (std::getline(readFile1, line)) {
        std::cout << line << std::endl;
    }
    readFile1.close();

    int n, m; // Declare n and m here

    while (true) {
        try {
            std::cout << "Enter the line number to move: ";
            n = getInputAsInt();
            if (n == 666) {
                break;
            }
            std::cout << "Enter the line number to move after: ";
            m = getInputAsInt();
            if (m == 666) {
                break;
            }
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
            continue;
        }

        // Check if the line numbers are valid
        if (n < 1 || n > num_lines || m < 1 || m > num_lines) {
            std::cout << "Invalid line numbers. Please enter numbers between 1 and " << num_lines << "." << std::endl;
            continue;
        }

        std::vector<std::string> lines;
        std::ifstream readFile2("random_file.txt");
        std::string line;
        while (std::getline(readFile2, line)) {
            lines.push_back(line);
        }
        readFile2.close();

        // Account for n < m
        if (n < m) {
            lines.insert(lines.begin() + m - 1, lines[n - 1]);
            if (n <= m) {
                lines.erase(lines.begin() + n - 1);
            } else {
                lines.erase(lines.begin() + n);
            }
        }
        std::ofstream writeFile("random_file.txt");
        for (const auto& line : lines) {
            writeFile << line << std::endl;
        }
        writeFile.close();

        if (m == n || m == n - 1) {
            std::cout << "Line " << n << " is already after line " << m << "." << std::endl;
        } else {
            std::cout << "Line " << n << " has been placed after line " << m << "." << std::endl;
        }

        // Read and display the updated contents of the file
        std::ifstream readFile3("random_file.txt");
        std::cout << "Contents of the file:" << std::endl;
        while (std::getline(readFile3, line)) {
            std::cout << line << std::endl;
        }
        readFile3.close();
    }

    // Read and display the final contents of the file
    std::ifstream readFile4("random_file.txt");
    std::cout << "Final contents of the file:" << std::endl;
    while (std::getline(readFile4, line)) {
        std::cout << line << std::endl;
    }
    readFile4.close();

    return 0;
}
