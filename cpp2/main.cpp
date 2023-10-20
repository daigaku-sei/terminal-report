#include <iostream>
#include <vector>
#include <random>
#include <cmath>

// Function to create a random filled matrix
std::vector<std::vector<double>> createRandomMatrix(int rows, int cols, double minRange, double maxRange) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(minRange, maxRange);

    std::vector<std::vector<double>> matrix(rows, std::vector<double>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = dis(gen);
        }
    }

    return matrix;
}

// Function to print a matrix
void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if a matrix is square
bool isSquareMatrix(const std::vector<std::vector<double>>& matrix) {
    return matrix.size() == matrix[0].size();
}

// Function to calculate the determinant of a square matrix
double calculateDeterminant(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();

    if (n == 1) {
        return matrix[0][0];
    }

    double determinant = 0;
    int sign = 1;

    for (int i = 0; i < n; i++) {
        std::vector<std::vector<double>> subMatrix(n - 1, std::vector<double>(n - 1));

        for (int j = 1; j < n; j++) {
            int k = 0;
            for (int l = 0; l < n; l++) {
                if (l != i) {
                    subMatrix[j - 1][k++] = matrix[j][l];
                }
            }
        }

        determinant += sign * matrix[0][i] * calculateDeterminant(subMatrix);
        sign = -sign;
    }

    return determinant;
}

// Function to calculate the trace of a square matrix
double calculateTrace(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    double trace = 0;

    for (int i = 0; i < n; i++) {
        trace += matrix[i][i];
    }

    return trace;
}

// Function to calculate the inverse of a square matrix
std::vector<std::vector<double>> calculateInverse(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();

    std::vector<std::vector<double>> inverse(n, std::vector<double>(n));
    std::vector<std::vector<double>> augmentedMatrix(n, std::vector<double>(2 * n));

    // Create augmented matrix [matrix | identity matrix]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmentedMatrix[i][j] = matrix[i][j];
            augmentedMatrix[i][j + n] = (i == j) ? 1 : 0;
        }
    }

    // Perform row operations to get the inverse
    for (int i = 0; i < n; i++) {
        double pivot = augmentedMatrix[i][i];

        for (int j = 0; j < 2 * n; j++) {
            augmentedMatrix[i][j] /= pivot;
        }

        for (int j = 0; j < n; j++) {
            if (j != i) {
                double factor = augmentedMatrix[j][i];

                for (int k = 0; k < 2 * n; k++) {
                    augmentedMatrix[j][k] -= factor * augmentedMatrix[i][k];
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = augmentedMatrix[i][j + n];
        }
    }

    return inverse;
}

std::vector<std::vector<double>> transpose(const std::vector<std::vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    std::vector<std::vector<double>> transposedMatrix(cols, std::vector<double>(rows));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    return transposedMatrix;
}

// Function to calculate the sum of two matrices
std::vector<std::vector<double>> sum(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2) {
    std::vector<std::vector<double>> result;
    for (size_t i = 0; i < matrix1.size(); i++) {
        std::vector<double> row;
        for (size_t j = 0; j < matrix1[i].size(); j++) {
            row.push_back(matrix1[i][j] + matrix2[i][j]);
        }
        result.push_back(row);
    }
    return result;
}

// Function to calculate the product of two matrices
std::vector<std::vector<double>> product(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2) {
    std::vector<std::vector<double>> result;
    for (size_t i = 0; i < matrix1.size(); i++) {
        std::vector<double> row;
        for (size_t j = 0; j < matrix2[0].size(); j++) {
            int sum = 0;
            for (size_t k = 0; k < matrix1[i].size(); k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            row.push_back(sum);
        }
        result.push_back(row);
    }
    return result;
}


int main() {
    int option = 1;
    std::vector<std::vector<double>> matrix1, matrix2;
    int rows1, cols1, rows2, cols2;
    double minRange1, maxRange1, minRange2, maxRange2;

    while (option != 5) {
        std::cout << "Options:" << std::endl;
        std::cout << "1. Create two random filled matrices" << std::endl;
        std::cout << "2. Transpose matrices" << std::endl;
        std::cout << "3. Check if matrices are square and calculate determinant/trace/inverse" << std::endl;
        std::cout << "4. Perform all possible operations" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "Enter the number of rows for matrix 1: ";
                std::cin >> rows1;
                std::cout << "Enter the number of columns for matrix 1: ";
                std::cin >> cols1;
                std::cout << "Enter the minimum range for matrix 1: ";
                std::cin >> minRange1;
                std::cout << "Enter the maximum range for matrix 1: ";
                std::cin >> maxRange1;

                matrix1 = createRandomMatrix(rows1, cols1, minRange1, maxRange1);

                std::cout << "Enter the number of rows for matrix 2: ";
                std::cin >> rows2;
                std::cout << "Enter the number of columns for matrix 2: ";
                std::cin >> cols2;
                std::cout << "Enter the minimum range for matrix 2: ";
                std::cin >> minRange2;
                std::cout << "Enter the maximum range for matrix 2: ";
                std::cin >> maxRange2;

                matrix2 = createRandomMatrix(rows2, cols2, minRange2, maxRange2);

                break;

            case 2:
                std::cout << "Matrix 1:" << std::endl;
                printMatrix(matrix1);
                std::cout << "Matrix 2:" << std::endl;
                printMatrix(matrix2);

                std::cout << "Transposed Matrix 1:" << std::endl;
                printMatrix(transpose(matrix1));
                std::cout << "Transposed Matrix 2:" << std::endl;
                printMatrix(transpose(matrix2));

                break;

            case 3:
                std::cout << "Matrix 1:" << std::endl;
                printMatrix(matrix1);
                std::cout << "Matrix 2:" << std::endl;
                printMatrix(matrix2);

                if (isSquareMatrix(matrix1)) {
                    std::cout << "Matrix 1 is square." << std::endl;
                    std::cout << "Determinant of Matrix 1: " << calculateDeterminant(matrix1) << std::endl;
                    std::cout << "Trace of Matrix 1: " << calculateTrace(matrix1) << std::endl;

                    if (calculateDeterminant(matrix1) != 0) {
                        std::cout << "Inverse of Matrix 1:" << std::endl;
                        printMatrix(calculateInverse(matrix1));
                    }
                }

                if (isSquareMatrix(matrix2)) {
                    std::cout << "Matrix 2 is square." << std::endl;
                    std::cout << "Determinant of Matrix 2: " << calculateDeterminant(matrix2) << std::endl;
                    std::cout << "Trace of Matrix 2: " << calculateTrace(matrix2) << std::endl;

                    if (calculateDeterminant(matrix2) != 0) {
                        std::cout << "Inverse of Matrix 2:" << std::endl;
                        printMatrix(calculateInverse(matrix2));
                    }
                }

                break;

            case 4:
                std::cout << "Matrix 1:" << std::endl;
                printMatrix(matrix1);
                std::cout << "Matrix 2:" << std::endl;
                printMatrix(matrix2);

                if (matrix1 == matrix2) {
                    std::cout << "Matrix 1 and Matrix 2 are equal." << std::endl;
                } else {
                    std::cout << "Matrix 1 and Matrix 2 are not equal." << std::endl;
                }

                std::cout << "Sum of Matrix 1 and Matrix 2:" << std::endl;
                printMatrix(sum(matrix1, matrix2));

                std::cout << "Product of Matrix 1 and Matrix 2:" << std::endl;
                printMatrix(product(matrix1, matrix2));

                break;

            case 5:
                std::cout << "Exiting..." << std::endl;
                break;

            default:
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
        }

        std::cout << std::endl;
    }

    return 0;
}
