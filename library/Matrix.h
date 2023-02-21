//
// Created by Quentin Surdez on 10.02.23.
//

#ifndef CPP_ML_MATRIX_H
#define CPP_ML_MATRIX_H
#include <utility>
#include <vector>
#include <ostream>


class Matrix {
public:
    Matrix() = default;
    explicit Matrix(unsigned _rows, unsigned _cols, std::vector<std::vector<double>> _data) :
    rows(_rows), cols(_cols), data(std::move(_data)) {};
    Matrix zero(unsigned _rows, unsigned _cols);
    Matrix random(unsigned _rows, unsigned _cols);
    Matrix add(Matrix &rhs);
    Matrix multiply(Matrix &rhs);
    Matrix transpose();
    friend std::ostream& operator<<(std::ostream& os, const Matrix &rhs);


private:
    unsigned rows;
    unsigned cols;
    std::vector<std::vector<double>> data;

};


#endif //CPP_ML_MATRIX_H
