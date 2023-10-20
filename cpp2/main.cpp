cpp
#include <iostream>
#include "matrix_operations.h"

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
