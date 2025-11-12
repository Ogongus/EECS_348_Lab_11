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

