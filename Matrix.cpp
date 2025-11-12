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
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix& other) {
    allocate(other.n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    deallocate();
}

Matrix& Matrix::operator = (const Matrix& other) {
    if (this != &other) {
        deallocate();
        allocate(other.n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::operator + (const Matrix& other) const {
    if (n != other.n) {
        std::cerr << "Matrix size mismatch in addition." << std::endl;
        return Matrix();
    }
    Matrix result(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator * (const Matrix& other) const {
    if (n != other.n) {
        std::cerr << "Matrix size mismatch in multiplication!" << std::endl;
        return Matrix();
    }
    Matrix result(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

bool Matrix::readFromFile(const std::string& filename, bool second) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return false;
    }

    if (second) {
        // Skip first matrix
        std::string line;
        int temp_n;
        file >> temp_n;
        for (int i = 0; i < temp_n * temp_n; ++i) {
            file >> temp_n;
        }
    }

    int size;
    file >> size;
    deallocate();
    allocate(size);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> data[i][j];
        }
    }
    file.close();
    return true;
}

void Matrix::display() const {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(4) << data[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int Matrix::mainDiagonalSum() const {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += data[i][i];
    }
    return sum;
}

int Matrix::secondaryDiagonalSum() const {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += data[i][n - 1 - i];
    }
    return sum;
}

Matrix Matrix::swapRows(int r1, int r2) const {
    if (r1 < 0 || r1 >= n || r2 < 0 || r2 >= n) {
        std::cerr << "Invalid row indices for swap." << std:: endl;
        return *this;
    }
    Matrix result = *this;
    for (int j = 0; j < n; ++j) {
        std::swap(result.data[r1][j], result.data[r2][j]);
    }
    return result;
}

Matrix Matrix::swapColumns(int c1, int c2) const {
    if (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n) {
        std::cerr << "Invalid column indices for swap." << std::endl;
        return *this;
    }
    Matrix result = *this;
    for (int i = 0; i < n; ++i) {
        std::swap(result.data[i][c1], result.data[i][c2]);
    }
    return result;
}

Matrix Matrix::updateElement(int row, int col, int value) const {
    if (row < 0 || row >= n || col < 0 || col >= n) {
        std::cerr << "Invalid indices for update!" << std::endl;
        return *this;
    }
    Matrix result = *this;
    result.data[row][col] = value;
    return result;
}