// Function to generate a random double within a given range
double getRandomNumber(double min, double max) {
    double random = ((double)rand()) / RAND_MAX;
    double range = max - min;
    return (random * range) + min;
}

// Function to allocate memory for a matrix
double** createMatrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to fill a matrix with random values within a given range
void fillMatrix(double** matrix, int rows, int cols, double min, double max) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = getRandomNumber(min, max);
        }
    }
}

// Function to print a matrix (3 decimals)
void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.3le ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a matrix is square
int isSquareMatrix(int rows, int cols) {
    return rows == cols;
}


// Function to calculate the determinant of a square matrix
int calculateDeterminant(double** matrix, int size) {
    // Base case: if the matrix is 1x1, return the single element
    if (size == 1) {
        return matrix[0][0];
    }
    
    int determinant = 0;
    int sign = 1;
    int i, j, k;
    
    // Create a submatrix for cofactor expansion
    double** submatrix = (double**)malloc((size - 1) * sizeof(double*));
    for (i = 0; i < size - 1; i++) {
        submatrix[i] = (double*)malloc((size - 1) * sizeof(double));
    }
    
    // Perform cofactor expansion along the first row
    for (i = 0; i < size; i++) {
        // Fill the submatrix for the cofactor
        for (j = 1; j < size; j++) {
            for (k = 0; k < size; k++) {
                if (k < i) {
                    submatrix[j - 1][k] = matrix[j][k];
                } else if (k > i) {
                    submatrix[j - 1][k - 1] = matrix[j][k];
                }
            }
        }
        
        // Calculate the cofactor and recursively calculate the determinant of the submatrix
        determinant += sign * matrix[0][i] * calculateDeterminant(submatrix, size - 1);
        
        // Update the sign for the next cofactor
        sign = -sign;
    }
    
    // Free the memory allocated for the submatrix
    for (i = 0; i < size - 1; i++) {
        free(submatrix[i]);
    }
    free(submatrix);
    
    return determinant;
}

// Function to calculate the trace of a square matrix
int calculateTrace(double** matrix, int size) {
    int trace = 0;
    int i;
    
    // Sum the diagonal elements of the matrix
    for (i = 0; i < size; i++) {
        trace += matrix[i][i];
    }
    
    return trace;
}

// Function to allocate memory for a square matrix
double** allocateMatrix(int size) {
    double** matrix = (double**)malloc(size * sizeof(double*));
    int i;
    for (i = 0; i < size; i++) {
        matrix[i] = (double*)malloc(size * sizeof(double));
    }
    return matrix;
}

// Function to deallocate memory for a square matrix
void deallocateMatrix(double** matrix, int size) {
    int i;
    for (i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to calculate the inverse of a square matrix
double** calculateInverse(double** matrix, int size) {
    // Create an augmented matrix [A | I]
    double** augmentedMatrix = allocateMatrix(size);
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            augmentedMatrix[i][j] = matrix[i][j];
        }
        for (j = size; j < 2 * size; j++) {
            augmentedMatrix[i][j] = (i == j - size) ? 1.0 : 0.0;
        }
    }
    
    // Perform Gauss-Jordan elimination
    for (i = 0; i < size; i++) {
        // Find the pivot row
        int pivotRow = i;
        for (j = i + 1; j < size; j++) {
            if (augmentedMatrix[j][i] > augmentedMatrix[pivotRow][i]) {
                pivotRow = j;
            }
        }
        
        // Swap the pivot row with the current row
        if (pivotRow != i) {
            double* temp = augmentedMatrix[i];
            augmentedMatrix[i] = augmentedMatrix[pivotRow];
            augmentedMatrix[pivotRow] = temp;
        }
        
        // Scale the pivot row to make the pivot element 1
        double pivotElement = augmentedMatrix[i][i];
        for (j = i; j < 2 * size; j++) {
            augmentedMatrix[i][j] /= pivotElement;
        }
        
        // Eliminate the other rows
        for (j = 0; j < size; j++) {
            if (j != i) {
                double factor = augmentedMatrix[j][i];
                for (int k = i; k < 2 * size; k++) {
                    augmentedMatrix[j][k] -= factor * augmentedMatrix[i][k];
                }
            }
        }
    }
    
    // Extract the inverse matrix from the augmented matrix
    double** inverseMatrix = allocateMatrix(size);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            inverseMatrix[i][j] = augmentedMatrix[i][j + size];
        }
    }
    
    // Deallocate memory for the augmented matrix
    deallocateMatrix(augmentedMatrix, size);
    
    return inverseMatrix;
}
