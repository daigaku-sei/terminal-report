import numpy as np

print("\n p2: [9] => T6: matrix operations on 2x[M]x[N] of double\n")
rows1, cols1 = 0, 0
while rows1 <= 0 or cols1 <= 0:
    rows1 = int(input("Enter the number of rows for the first matrix: "))
    cols1 = int(input("Enter the number of columns for the first matrix: "))

rows2, cols2 = 0, 0
while rows2 <= 0 or cols2 <= 0:
    rows2 = int(input("Enter the valid number of rows for the second matrix: "))
    cols2 = int(input("Enter the valid number of columns for the second matrix: "))

matrix1 = np.zeros((rows1, cols1))
matrix2 = np.zeros((rows2, cols2))

choice = input("Do you want to enter the matrix values manually? (y/n): ")
if choice.lower() == 'y':
    print("Enter the values for matrix1:")
    for i in range(rows1):
        for j in range(cols1):
            matrix1[i, j] = float(input())

    print("Enter the values for matrix2:")
    for i in range(rows2):
        for j in range(cols2):
            matrix2[i, j] = float(input())
else:
    matrix1 = np.random.randn(rows1, cols1) * 100.0
    matrix2 = np.random.randn(rows2, cols2) * 100.0

rank1 = np.linalg.matrix_rank(matrix1)
rank2 = np.linalg.matrix_rank(matrix2)
transpose1 = matrix1.T
transpose2 = matrix2.T
square1 = (rows1 == cols1)
square2 = (rows2 == cols2)
determinant1, determinant2 = 0.0, 0.0
trace1, trace2 = 0.0, 0.0
inverse1, inverse2 = None, None
invertible1, invertible2 = False, False

if square1:
    determinant1 = np.linalg.det(matrix1)
    trace1 = np.trace(matrix1)
    inverse1 = np.linalg.inv(matrix1)
    invertible1 = True

if square2:
    determinant2 = np.linalg.det(matrix2)
    trace2 = np.trace(matrix2)
    inverse2 = np.linalg.inv(matrix2)
    invertible2 = True

sum_matrix, product = None, None
addable = (matrix1.shape == matrix2.shape)
equal = (addable and np.array_equal(matrix1, matrix2))
multipliable = (matrix1.shape[1] == matrix2.shape[0])

if addable:
    sum_matrix = matrix1 + matrix2

if multipliable:
    product = np.dot(matrix1, matrix2)

print("Matrix 1:\n", matrix1)
print("Matrix 2:\n", matrix2)
print("Rank of Matrix 1:", rank1)
print("Rank of Matrix 2:", rank2)
print("Transpose of Matrix 1:\n", transpose1)
print("Transpose of Matrix 2:\n", transpose2)

if square1:
    print("Determinant of Matrix 1:", determinant1)
    print("Trace of Matrix 1:", trace1)
    print("Inverse of Matrix 1:\n", inverse1)
else:
    print("Matrix 1 is not square.")

if square2:
    print("Determinant of Matrix 2:", determinant2)
    print("Trace of Matrix 2:", trace2)
    print("Inverse of Matrix 2:\n", inverse2)
else:
    print("Matrix 2 is not square.")

print("Are the matrices equal?", "Yes" if equal else "No")

if addable:
    print("Sum of Matrix 1 and Matrix 2:\n", sum_matrix)
else:
    print("Matrices cannot be added.")

if multipliable:
    print("Product of Matrix 1 and Matrix 2:\n", product)
else:
    print("Matrices cannot be multiplied.")
