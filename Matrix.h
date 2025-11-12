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
        //
}