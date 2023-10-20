#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <vector>

std::vector<std::vector<double>> createRandomMatrix(int rows, int cols, double minRange, double maxRange);
void printMatrix(const std::vector<std::vector<double>>& matrix);
std::vector<std::vector<double>> transpose(const std::vector<std::vector<double>>& matrix);
bool isSquareMatrix(const std::vector<std::vector<double>>& matrix);
double calculateDeterminant(const std::vector<std::vector<double>>& matrix);
double calculateTrace(const std::vector<std::vector<double>>& matrix);
std::vector<std::vector<double>> calculateInverse(const std::vector<std::vector<double>>& matrix);
std::vector<std::vector<double>> sum(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);
std::vector<std::vector<double>> product(const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2);

#endif
