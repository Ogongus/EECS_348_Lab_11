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
        
}