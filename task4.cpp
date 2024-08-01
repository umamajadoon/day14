#include <iostream>

void multiplyMatrices(int** mat1, int** mat2, int** result, int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        std::cout << "Matrix multiplication not possible with these dimensions.\n";
        return;
    }
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < c1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int r1 = 2, c1 = 3, r2 = 3, c2 = 2;
    int** mat1 = new int*[r1];
    int** mat2 = new int*[r2];
    int** result = new int*[r1];

    for (int i = 0; i < r1; ++i) {
        mat1[i] = new int[c1];
        result[i] = new int[c2];
    }
    for (int i = 0; i < r2; ++i) {
        mat2[i] = new int[c2];
    }

    // Initialize matrices
    mat1[0][0] = 1; mat1[0][1] = 2; mat1[0][2] = 3;
    mat1[1][0] = 4; mat1[1][1] = 5; mat1[1][2] = 6;

    mat2[0][0] = 7; mat2[0][1] = 8;
    mat2[1][0] = 9; mat2[1][1] = 10;
    mat2[2][0] = 11; mat2[2][1] = 12;

    multiplyMatrices(mat1, mat2, result, r1, c1, r2, c2);

    // Display result
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Free memory
    for (int i = 0; i < r1; ++i) {
        delete[] mat1[i];
        delete[] result[i];
    }
    for (int i = 0; i < r2; ++i) {
        delete[] mat2[i];
    }
    delete[] mat1;
    delete[] mat2;
    delete[] result;

    return 0;
}