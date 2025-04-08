// Created by kezjo on 25-4-8

#include "../include/sparse_matrix.hpp"


int SparseMatrix::addElement(int row, int col, double value) {
    if (matrix_data.size() >= max_size) {
        std::cerr << "matrix_data size overflow" << std::endl;
        return 0;
    }
    MatrixElement element = {row, col, value};
    matrix_data.push_back(element);
    return 1;
}

void SparseMatrix::output(const std::vector<MatrixElement>& matrix) {
    // 生成0矩阵
    std::vector<std::vector<int>> output_matrix(3, std::vector<int>(3, 0));

    // 填入矩阵
    for (const auto& element : matrix) {
        output_matrix[element.row][element.col] = element.value;
    }

    // 输出矩阵
    for (const auto& row : output_matrix) {
        for (const auto& value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * @name transpose
 * @brief 矩阵转置
 * @return 0:非零元素数量不一致
 */
int SparseMatrix::transpose(){
    // TODO by kezjo
    for(const auto& element : matrix_data){
        // matrix_data本身大小不会超过9，这里不作检查
        MatrixElement element_transposed = {element.col, element.row, element.value};
        transposed_matrix_data.push_back(element_transposed);
    }

    //  检查转置后的矩阵大小
    if(transposed_matrix_data.size() != matrix_data.size()){
        std::cerr << "transposed_matrix_data size error" << std::endl;
        return 0;
    }
    return 1;
}