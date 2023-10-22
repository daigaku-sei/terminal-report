#include <iostream>
#include <Eigen/Dense>

int getInputAsInt() {
    std::string input;
    std::cin >> input;
    std::stringstream ss(input);
    int value;
    if (ss >> value) {
        return value;
    } else {
        return -1; // Return -1 to indicate invalid input
    }
}

int main() {
    int rows1, cols1, rows2, cols2;
    
    std::cout << "______\n";
    std::cout << "\n cpp2: [9] => T6: matrix operations on 2x[M]x[N] of double\n";
    std::cout << "______\n";
    
    // Ask user for rows and columns of the first matrix
    do {
        std::cout << "Enter the valid number of rows for the first matrix: ";
        rows1 = getInputAsInt();
        std::cout << "Enter the valid number of columns for the first matrix: ";
        cols1 = getInputAsInt();
    } while (rows1 <= 0 || cols1 <= 0);

    // Ask user for rows and columns of the second matrix
    do {
        std::cout << "Enter the valid number of rows for the second matrix: ";
        rows2 = getInputAsInt();
        std::cout << "Enter the valid number of columns for the second matrix: ";
        cols2 = getInputAsInt();
    } while (rows2 <= 0 || cols2 <= 0);

    Eigen::MatrixXd matrix1(rows1, cols1);
    Eigen::MatrixXd matrix2(rows2, cols2);

    char choice;
    std::cout << "\nDo you want to enter the matrix values manually? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        std::cout << "\nType any invalid to autofill with zeros the rest (both matrixes)\n";
        std::cout << "Going column by column, from top number to bottom\n";
        std::cout << "Enter the values 1 per line & hit enter for Matrix 1:\n";
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols1; j++) {
                std::cin >> matrix1(i, j);
            }
        }

        std::cout << "\nType any invalid to autofill with zeros the rest of Matrix 2\n";
        std::cout << "Going column by column, from top number to bottom\n";
        std::cout << "Enter the values 1 per line & hit enter for Matrix 2:\n";
        for (int i = 0; i < rows2; i++) {
            for (int j = 0; j < cols2; j++) {
                std::cin >> matrix2(i, j);
            }
        }
    } else {
        // Create matrixes with random data
        matrix1 = Eigen::MatrixXd::Random(rows1, cols1) * 100.0;
        matrix2 = Eigen::MatrixXd::Random(rows2, cols2) * 100.0;
    }
    
    // Get ranks
    int rank1 = matrix1.fullPivLu().rank();
    int rank2 = matrix2.fullPivLu().rank();

    // Transpose
    Eigen::MatrixXd transpose1 = matrix1.transpose();
    Eigen::MatrixXd transpose2 = matrix2.transpose();

    // Check if matrices are square
    bool square1 = (rows1 == cols1);
    bool square2 = (rows2 == cols2);

    // Determinant, trace, and inverse (if possible)
    double determinant1 = 0.0, determinant2 = 0.0;
    double trace1 = 0.0, trace2 = 0.0;
    Eigen::MatrixXd inverse1, inverse2;
    bool invertible1 = false, invertible2 = false;

    if (square1) {
        determinant1 = matrix1.determinant();
        trace1 = matrix1.trace();
        if (determinant1 != 0) {inverse1 = matrix1.inverse();
        invertible1 = true;}
    }

    if (square2) {
        determinant2 = matrix2.determinant();
        trace2 = matrix2.trace();
        if (determinant2 != 0) {inverse2 = matrix2.inverse();
        invertible2 = true;}
    }

    // Get sum and product (if possible)
    Eigen::MatrixXd sum, product;
    bool addable = (matrix1.rows() == matrix2.rows() && matrix1.cols() == matrix2.cols());
    // Check if matrices are equal
    bool equal = (addable && matrix1 == matrix2);
    
    bool multipliable = (matrix1.cols() == matrix2.rows());

    if (addable) {
        sum = matrix1 + matrix2;
    }

    if (multipliable) {
        product = matrix1 * matrix2;
    }

    // Print the results
    std::cout << "\nMatrix 1:\n" << matrix1 << std::endl;
    std::cout << "Matrix 2:\n" << matrix2 << std::endl;

    std::cout << "\nRank of Matrix 1: " << rank1 << std::endl;
    std::cout << "Rank of Matrix 2: " << rank2 << std::endl;

    std::cout << "\nTranspose of Matrix 1:\n" << transpose1 << std::endl;
    std::cout << "Transpose of Matrix 2:\n" << transpose2 << std::endl;

    if (square1) {
        std::cout << "\nDeterminant of Matrix 1: " << determinant1 << std::endl;
        std::cout << "Trace of Matrix 1: " << trace1 << std::endl;
        if (invertible1) std::cout << "Inverse of Matrix 1:\n" << inverse1 << std::endl;
            else  std::cout << "Matrix 1 is not invertible." << std::endl;
    } else
        std::cout << "\nMatrix 1 is not square." << std::endl;

    if (square2) {
        std::cout << "\nDeterminant of Matrix 2: " << determinant2 << std::endl;
        std::cout << "Trace of Matrix 2: " << trace2 << std::endl;
        if (invertible2) std::cout << "Inverse of Matrix 2:\n" << inverse2 << std::endl;
            else  std::cout << "Matrix 2 is not invertible." << std::endl;
    } else
        std::cout << "\nMatrix 2 is not square." << std::endl;

    std::cout << "\nAre the matrices equal? " << (equal ? "Yes" : "No") << std::endl;

    if (addable) {
        std::cout << "Sum of Matrix 1 and Matrix 2:\n" << sum << std::endl;
    } else {
        std::cout << "Matrices cannot be added." << std::endl;
    }

    if (multipliable) {
        std::cout << "Product of Matrix 1 and Matrix 2:\n" << product << std::endl;
    } else {
        std::cout << "Matrices cannot be multiplied." << std::endl;
    }

    return 0;
}
