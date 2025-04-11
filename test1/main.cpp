#include <iostream>
// #include "./include/sparse_matrix.hpp"
#include <vector>
#include <cmath>

/**
 * @name MatrixElement
 * @brief 矩阵元素结构体
 */
struct MatrixElement {
    int row;
    int col;
    int value;
};



class SparseMatrix {
public:
    SparseMatrix(){
        // TODO by kezjo
    }

    int addElement(int row, int col, int value){
        if (matrix_data.size() >= max_size) {
            std::cerr << "matrix_data size overflow" << std::endl;
            return 0;
        }
        if(row < 0 || row >= 3 || col < 0 || col >= 3) {
            std::cerr << "row or col out of range" << std::endl;
            return 0;
        }
        MatrixElement element = {row, col, value};
        matrix_data.push_back(element);
        return 1;
    }

    void output(const std::vector<MatrixElement>& matrix) {
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
    int transpose(){
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

SparseMatrix MatrixAdd(SparseMatrix& matrix_A, SparseMatrix& matrix_B) {
    SparseMatrix result;
    std::vector<MatrixElement> data_A = matrix_A.getMatrixData();
    std::vector<MatrixElement> data_B = matrix_B.getMatrixData();
    for(const auto& element : data_B){
        bool element_found = false;
        for(auto& element_A : data_A){
            if(element.row == element_A.row && element.col == element_A.col){
                // 如果在矩阵A中，相加
                element_A.value += element.value;
                element_found = true;
                break;
            }
        }
        if(!element_found){
            data_A.push_back(element);
        }
    }

    for(const auto& element : data_A){
        result.addElement(element.row, element.col, element.value);
    }

    return result;
}


int main() {
    // TODO
    SparseMatrix matrix_A;
    
    while(1){
        int row, col, value;
        std::cout << "输入矩阵元素的行、列和数值(-1结束): ";
        std::cin >> row;
        if(row == -1){
            break;
        }
        std::cin >> col >> value;
        int ret = matrix_A.addElement(row, col, value);
        if(ret == 0){
            std::cerr << "添加矩阵元素失败" << std::endl;
            break;
        }
    }

    std::cout << "原矩阵:" << std::endl;
    matrix_A.output(matrix_A.getMatrixData());
    std::cout << "转置矩阵:" << std::endl;
    int ret = matrix_A.transpose();
    if(ret == 0){
        std::cerr << "转置矩阵失败" << std::endl;
        return 0;
    }
    matrix_A.output(matrix_A.getTransposedMatrixData());

    // 矩阵B
    SparseMatrix matrix_B;
    while(1){
        int row, col, value;
        std::cout << "输入矩阵元素的行、列和数值(-1结束): ";
        std::cin >> row;
        if(row == -1){
            break;
        }
        std::cin >> col >> value;
        int ret = matrix_B.addElement(row, col, value);
        if(ret == 0){
            std::cerr << "添加矩阵元素失败" << std::endl;
            break;
        }
    }

    SparseMatrix matrix_sum = MatrixAdd(matrix_A, matrix_B);
    std::cout << "A+B:" << std::endl;
    matrix_sum.output(matrix_sum.getMatrixData());
    return 0;
}