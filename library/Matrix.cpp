//
// Created by Quentin Surdez on 10.02.23.
//

#include "Matrix.h"
#include <random>
#include <iostream>
#include <algorithm>

using namespace std;

Matrix Matrix::zero(unsigned int _rows, unsigned int _cols) {
    vector<double> columns (_cols, 0);
    vector<vector<double>> matrix (_rows, columns);
    Matrix zero (_rows, _cols, matrix);
    return zero;
}

Matrix Matrix::random(unsigned int _rows, unsigned int _cols) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    Matrix result;
    result = result.zero(_rows, _cols);
    for (size_t i = 0; i < _rows; ++i) {
        for (size_t j = 0; j < _cols; ++j) {
            result.data[i][j] = dis(gen) * 2 - 1;
        }
    }
    return result;
}

Matrix Matrix::add(Matrix &rhs) {
    if (this->rows != rhs.rows || this->cols != rhs.cols)
        cerr << "Attempting to add a matrix with a matrix of different dimension";

    Matrix result = Matrix::zero(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            result.data[i][j] = this->data[i][j] + rhs.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::transpose() {
    Matrix result = Matrix::zero(this->cols, this->rows);

    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            result.data[j][i] = this->data[i][j];
        }
    }
    return result;
}

Matrix Matrix::multiply(Matrix &rhs) {
    if (this->cols != rhs.rows)
        cerr << "Attempting to multiply a matrix of invalid dimension";

    Matrix result = Matrix::zero(this->rows, rhs.cols);


    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < rhs.cols; ++j) {
            double sum = 0;
            for (size_t k = 0; k < this->cols; ++k) {
                sum += this->data[i][k] * rhs.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

Matrix Matrix::from(std::vector<std::vector<double>> _data) {
   return Matrix(_data.size(), _data[0].size(), _data);
}

Matrix Matrix::map(double (*func)(double)) {
   for (const auto&vec : data) {
      for (double var : vec){
         func(var);
      }
   }
   return *this;
}

vector<double> Matrix::row(unsigned int row) const {
   vector<double> result(this->rows, 0.0);

   for (size_t i = 0; i < this->cols; i++){
      result.push_back(this->data[row][i]);
   }

   return result;
}

vector<double> Matrix::column(unsigned int col) const {
   vector<double> result(this->cols, 0.0);

   for (size_t i = 0; i < this->rows; i++){
      result.push_back(this->data[i][col]);
   }

   return result;
}


ostream& operator<<(ostream& os, const Matrix &rhs) {
    for (size_t i = 0; i < rhs.rows; ++i) {
        for (size_t j = 0; j < rhs.cols; ++j) {
            if (!j)
                os << "[";
            os << rhs.data[i][j];
            if (j != rhs.cols - 1)
                os << ", ";
        }
        os << "]" << endl;
    }
    return os;
}