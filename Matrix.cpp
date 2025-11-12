#include "Matrix.h"
#include <fstream>
#include <iomanip>
#include <sstream>

void Matrix::allocate(int size) {
    n = size;
    data = new int*[n];
    for (int i = 0; i < n; ++i) {
        data[i] = new int[n];
    }
}

void Matrix::deallocate() {
    if (data) {
        for (int i = 0; i < n; ++i) {
            delete[] data [i];
        }
        delete[] data;
        data = nullptr;
    }
    n = 0;
}

Matrix::Matrix() : n(0), data(nullptr) {}

Matrix::Matrix(int size) {
    allocate(size);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            data[i][j] = 0;
}

Matrix::Matrix(const Matrix& other) {
    allocate(other.n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            data[i][j] = other.data[i][j];
}

