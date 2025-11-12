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

