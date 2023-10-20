#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random double within a given range
double getRandomNumber(double min, double max) {
    double random = ((double)rand()) / RAND_MAX;
    double range = max - min;
    return (random * range) + min;
}

// Function to allocate memory for a matrix
int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to fill a matrix with random values within a given range
void fillMatrix(int** matrix, int rows, int cols, int min, int max) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = getRandomNumber(min, max);
        }
    }
}

// Function to print a matrix
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a matrix is square (quadro)
int isSquareMatrix(int rows, int cols) {
    return rows == cols;
}

// Function to calculate the determinant of a square matrix
int calculateDeterminant(int** matrix, int size) {
    // Implementation of determinant calculation goes here
    // Return the calculated determinant
}

// Function to calculate the trace of a square matrix
int calculateTrace(int** matrix, int size) {
    // Implementation of trace calculation goes here
    // Return the calculated trace
}

// Function to calculate the inverse of a square matrix
int** calculateInverse(int** matrix, int size) {
    // Implementation of inverse calculation goes here
    // Return the calculated inverse matrix
}

int main() {
    int rows, cols;
    double min, max;
    
    // Get the size of the matrices from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    // Make sure the size is non-zero
    while (rows <= 0 || cols <= 0) {
        printf("Invalid size. Please enter a non-zero value.\n");
        printf("Enter the number of rows: ");
        scanf("%d", &rows);
        printf("Enter the number of columns: ");
        scanf("%d", &cols);
    }
    
    // Get the range of values from the user
    printf("Enter the minimum value: ");
    scanf("%d", &min);
    printf("Enter the maximum value: ");
    scanf("%d", &max);
    
    // Create the first matrix
    int** matrix1 = createMatrix(rows, cols);
    fillMatrix(matrix1, rows, cols, min, max);
    
    // Create the second matrix
    int** matrix2;
    int sameSize;
    printf("Do you want the second matrix to have the same size as the first matrix? (1 for yes, 0 for no): ");
    scanf("%d", &sameSize);
    
    if (sameSize) {
        matrix2 = createMatrix(rows, cols);
    } else {
        int rows2, cols2;
        printf("Enter the number of rows for the second matrix: ");
        scanf("%d", &rows2);
        printf("Enter the number of columns for the second matrix: ");
        scanf("%d", &cols2);
        
        // Make sure the size is non-zero
        while (rows2 <= 0 || cols2 <= 0) {
            printf("Invalid size. Please enter a non-zero value.\n");
            printf("Enter the number of rows for the second matrix: ");
            scanf("%d", &rows2);
            printf("Enter the number of columns for the second matrix: ");
            scanf("%d", &cols2);
        }
        
        matrix2 = createMatrix(rows2, cols2);
    }
    
    fillMatrix(matrix2, rows, cols, min, max);
    
    // Print the matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, rows, cols);
    
    printf("Matrix 2:\n");
    printMatrix(matrix2, rows, cols);
    
    // Perform operations based on user input
    int option;
    printf("Choose an option:\n");
    printf("1. Change value in a certain cell of a certain matrix\n");
    printf("2. Rerandom the matrices\n");
    printf("3. Rerandom one matrix\n");
    printf("4. Get rank\n");
    printf("5. Transpose option\n");
    printf("6. Check if matrices are square\n");
    printf("7. Get determinant/trace\n");
    printf("8. Get inverse\n");
    printf("123. Force exit by option, you can also use CTRL-C\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    while (option) {
        switch (option) {
            case 1:
                // Implementation for changing value in a certain cell goes here
                break;
            case 2:
                // Implementation for rerandomizing the matrices goes here
                break;
            case 3:
                // Implementation for rerandomizing one matrix goes here
                break;
            case 4:
                // Implementation for getting rank goes here
                break;
            case 5:
                // Implementation for transpose option goes here
                break;
            case 6:
                // Check if matrices are square
                if (isSquareMatrix(rows, cols)) {
                    printf("Both matrices are square.\n");
                } else {
                    printf("Both matrices are not square.\n");
                }
                break;
            case 7:
                // Implementation for getting determinant/trace goes here
                break;
            case 8:
                // Implementation for getting inverse goes here
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
        printf("Enter your option: ");
        scanf("%d", &option);
    }
    // Free the memory allocated for the matrices
    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
    }
    free(matrix1);
    
    for (int i = 0; i < rows; i++) {
        free(matrix2[i]);
    }
    free(matrix2);
    
    return 0;
}
