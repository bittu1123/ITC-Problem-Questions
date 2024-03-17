#include <iostream>
#include <fstream>

using namespace std;

// Function prototypes
void inputMatrix(int**& matrix, int& rows, int& cols);
void displayMatrix(int** matrix, int rows, int cols);
int** sumOfMatrices(int** matrix1, int** matrix2, int rows, int cols);
int** productOfMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2);
int** transposeMatrix(int** matrix, int rows, int cols);
int determinantOfMatrix(int** matrix, int n);
void deleteMatrix(int**& matrix, int rows);

// Function to input matrix from the user
void inputMatrix(int**& matrix, int& rows, int& cols) {
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        cout << "Enter elements for row " << i + 1 << ": ";
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
}

// Function to display matrix
void displayMatrix(int** matrix, int rows, int cols) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to calculate the sum of two matrices
int** sumOfMatrices(int** matrix1, int** matrix2, int rows, int cols) {
    int** result = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        result[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Function to calculate the product of two matrices
int** productOfMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2) {
    if (cols1 != rows2) {
        cout << "Matrix multiplication not possible. Invalid dimensions." << endl;
        return NULL;
    }

    int** result = new int*[rows1];
    for (int i = 0; i < rows1; ++i) {
        result[i] = new int[cols2];
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
int** transposeMatrix(int** matrix, int rows, int cols) {
    int** result = new int*[cols];
    for (int i = 0; i < cols; ++i) {
        result[i] = new int[rows];
        for (int j = 0; j < rows; ++j) {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}

// Function to calculate the determinant of a square matrix
int determinantOfMatrix(int** matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        int det = 0;
        for (int i = 0; i < n; ++i) {
            int** submatrix = new int*[n - 1];
            for (int j = 0; j < n - 1; ++j) {
                submatrix[j] = new int[n - 1];
            }
            for (int j = 1; j < n; ++j) {
                for (int k = 0, l = 0; k < n; ++k) {
                    if (k != i) {
                        submatrix[j - 1][l++] = matrix[j][k];
                    }
                }
            }
            int sign = (i % 2 == 0) ? 1 : -1;
            det += sign * matrix[0][i] * determinantOfMatrix(submatrix, n - 1);
            for (int j = 0; j < n - 1; ++j) {
                delete[] submatrix[j];
            }
            delete[] submatrix;
        }
        return det;
    }
}

// Function to delete a matrix and free memory
void deleteMatrix(int**& matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = NULL;
}

int main() {
    int** matrix1 = NULL;
    int** matrix2 = NULL;
    int rows1, cols1, rows2, cols2;

    cout << "Matrix 1:" << endl;
    inputMatrix(matrix1, rows1, cols1);

    cout << "Matrix 2:" << endl;
    inputMatrix(matrix2, rows2, cols2);

    // Display matrices
    displayMatrix(matrix1, rows1, cols1);
    displayMatrix(matrix2, rows2, cols2);

    // Calculate and display the sum of matrices
    int** sumMatrix = sumOfMatrices(matrix1, matrix2, rows1, cols1);
    if (sumMatrix != NULL) {
        cout << "Sum of Matrices:" << endl;
        displayMatrix(sumMatrix, rows1, cols1);
        deleteMatrix(sumMatrix, rows1);
    }

    // Calculate and display the product of matrices
    int** productMatrix = productOfMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);
    if (productMatrix != NULL) {
        cout << "Product of Matrices:" << endl;
        displayMatrix(productMatrix, rows1, cols2);
        deleteMatrix(productMatrix, rows1);
    }

    // Calculate and display the transpose of matrices
    int** transposeMatrix1 = transposeMatrix(matrix1, rows1, cols1);
    int** transposeMatrix2 = transposeMatrix(matrix2, rows2, cols2);

    cout << "Transpose of Matrix 1:" << endl;
    displayMatrix(transposeMatrix1, cols1, rows1);
    deleteMatrix(transposeMatrix1, cols1);

    cout << "Transpose of Matrix 2:" << endl;
    displayMatrix(transposeMatrix2, cols2, rows2);
    deleteMatrix(transposeMatrix2, cols2);

    // Calculate and display the determinant of matrices
    int detMatrix1 = determinantOfMatrix(matrix1, rows1);
    int detMatrix2 = determinantOfMatrix(matrix2, rows2);

    cout << "Determinant of Matrix 1: " << detMatrix1 << endl;
    cout << "Determinant of Matrix 2: " << detMatrix2 << endl;

    // Save results to files
    ofstream outFile1("matrix.txt");
    ofstream outFile2("matrix2.txt");

    if (outFile1.is_open() && outFile2.is_open()) {
        outFile1 << "Matrix 1:" << endl;
        displayMatrix(matrix1, rows1, cols1);

        outFile2 << "Matrix 2:" << endl;
        displayMatrix(matrix2, rows2, cols2);

        outFile1 << "Sum of Matrices:" << endl;
        displayMatrix(sumMatrix, rows1, cols1);
        deleteMatrix(sumMatrix, rows1);

        outFile2 << "Product of Matrices:" << endl;
        displayMatrix(productMatrix, rows1, cols2);
        deleteMatrix(productMatrix, rows1);

        outFile1 << "Transpose of Matrix 1:" << endl;
        displayMatrix(transposeMatrix1, cols1, rows1);
        deleteMatrix(transposeMatrix1, cols1);

        outFile2 << "Transpose of Matrix 2:" << endl;
        displayMatrix(transposeMatrix2, cols2, rows2);
        deleteMatrix(transposeMatrix2, cols2);

        outFile1 << "Determinant of Matrix 1: " << detMatrix1 << endl;
        outFile2 << "Determinant of Matrix 2: " << detMatrix2 << endl;

        outFile1.close();
        outFile2.close();
    } else {
        cout << "Unable to open output files." << endl;
    }

    // Clean up memory
    deleteMatrix(matrix1, rows1);
    deleteMatrix(matrix2, rows2);

    return 0;
}

