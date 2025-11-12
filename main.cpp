#include "Matrix.h"
#include <iostream>

int main() {
    Matrix A, B;

    // Practice 1: Read and display two matrices
    std::cout << "=== Reading Matrix A from input.txt ===" << std::endl;
    if (!A.readFromFile("input.txt")) return 1;
    std::cout << "Matrix A:" << std::endl;
    A.display();

    std::cout << "=== Reading Matrix B from input.txt ===" << std::endl;
    if (!B.readFromFile("input.txt", true)) return 1;
    std::cout << "Matrix B:" << std::endl;
    B.display();

    // Practice 2: Addition
    std::cout << "=== A + B ===" << std::endl;
    Matrix C = A + B;
    C.display();

    // Practice 3: Multiplication
    std::cout << "=== A * B ===" std::endl;
    Matrix D = A * B;
    D.display();

    // Practice 4: Diagonal sums
    std::cout << "=== Diagonal Sums of A ===" << std::endl;
    std::cout << "Main diagonal sum: " << A.mainDiagonalSum() << std::endl;
    std::cout << "Secondary diagonal sum: " << A.secondaryDiagonalSum() << std::endl;

    // Practice 5:
}