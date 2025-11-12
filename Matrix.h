#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <iostream>

class Matrix {
    private:
        int n;
        int** data;

        void allocate(int size);
        void deallocate();
    
    public:
        // Constructors & Destructor
        Matrix();
        Matrix(int size);
        Matrix(const Matrix& other);
        ~Matrix();

        // Assignment operator
        Matrix& operator = (const Matrix& other);

        // Operator overloading
        Matrix operator + (const Matrix& other) const;
        Matrix operator * (const Matrix& other) const;

        // File input
        bool readFromFile(const std::string& filename, bool second = false);

        // Display
        void display() const;

        // Diagonal sums
        int mainDiagonalSum() const;
        int secondaryDiagonalSum() const;

        // Swap rows / columns by value
        Matrix swapRows(int r1 = 0, int r2 = 1) const;
        Matrix swapColumns(int c1 = 0, int c2 = 1) const;

        // Update element
        Matrix updateElement(int row, int col, int value) const;

        // Getter
        int getSize() const {return n;}
};

#endif