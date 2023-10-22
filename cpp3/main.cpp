#include <iostream>
#include <fstream>
#include <vector>

int main() {

    std::cout << "______\n";
    std::cout << "\n cpp3: [9] => 9. line relocator: pop nth and insert after mth\n";
    std::cout << "______\n";
    
    int num_lines = 10;
    std::cout << "Type 666 at some point to exit" << std::endl;

    // Write ordered lines to the file
    std::ofstream file("random_file.txt");
    for (int i = 1; i <= num_lines; i++) {
        file << "Line " << i << std::endl;
    }
    file.close();

    // Read and display the contents of the file
    std::ifstream readFile("random_file.txt");
    std::cout << "Contents of the file:" << std::endl;
    std::string line;
    while (std::getline(readFile, line)) {
        std::cout << line << std::endl;
    }
    readFile.close();

    while (true) {
        try {
            int n, m;
            std::cout << "Enter the line number to move: ";
            std::cin >> n;
            if (n == 666) {
                break;
            }
            std::cout << "Enter the line number to move after: ";
            std::cin >> m;
            if (m == 666) {
                break;
            }
        } catch (...) {
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
            continue;
        }

        // Check if the line numbers are valid
        if (n < 1 || n > num_lines || m < 1 || m > num_lines) {
            std::cout << "Invalid line numbers. Please enter numbers between 1 and " << num_lines << "." << std::endl;
            continue;
        }

        std::vector<std::string> lines;
        std::ifstream readFile("random_file.txt");
        std::string line;
        while (std::getline(readFile, line)) {
            lines.push_back(line);
        }
        readFile.close();

        // Account for n < m
        if (n < m) {
            lines.insert(lines.begin() + m - 1, lines[n - 1]);
            lines.erase(lines.begin() + n - 1);
        } else {
            lines.insert(lines.begin() + m, lines[n - 1]);
            lines.erase(lines.begin() + n - 1);
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
        std::ifstream readFile("random_file.txt");
        std::cout << "Contents of the file:" << std::endl;
        while (std::getline(readFile, line)) {
            std::cout << line << std::endl;
        }
        readFile.close();
    }

    // Read and display the final contents of the file
    std::ifstream readFile("random_file.txt");
    std::cout << "Final contents of the file:" << std::endl;
    while (std::getline(readFile, line)) {
        std::cout << line << std::endl;
    }
    readFile.close();

    return 0;
}
