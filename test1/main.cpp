#include <iostream>
#include "./include/sparse_matrix.hpp"

int main() {
    SparseMatrix matrix;
    matrix.addElement(0, 0, 1.0);
    matrix.addElement(0, 1, 2.0);
    matrix.output(matrix.getMatrixData());
    std::cout << "------------------------" << std::endl;
    matrix.transpose();
    matrix.output(matrix.getTransposedMatrixData());
    std::cout << "------------------------" << std::endl;
    return 0;
}