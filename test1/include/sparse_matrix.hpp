// Created by kezjo on 25-4-8
#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <iostream>
#include <vector>
#include <cmath>

/**
 * @name MatrixElement
 * @brief 矩阵元素结构体
 */
struct MatrixElement {
    int row;
    int col;
    double value;
};


/**
 * @name SparseMatrix class
 */
class SparseMatrix {
public:
    SparseMatrix(){
        // TODO by kezjo
    }

    int addElement(int row, int col, double value);

    void output(const std::vector<MatrixElement>& matrix);

    int transpose();

    std::vector<MatrixElement> getMatrixData() const {
        return matrix_data;
    }

    std::vector<MatrixElement> getTransposedMatrixData() const {
        return transposed_matrix_data;
    }
private:
    int max_size = 9;   //3*3矩阵最多9个元素
    std::vector<MatrixElement> matrix_data;
    std::vector<MatrixElement> transposed_matrix_data;
};

#endif