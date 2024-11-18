#ifndef CPP_PILOT_HSE_MATRIXFILTER_H
#define CPP_PILOT_HSE_MATRIXFILTER_H
#pragma once
#include "Image.h"
#include "Filter.h"

class MatrixFilter : virtual public Filter {
    // наследуемся от Filter для того, чтобы можно было возвращать указатели типа unique_ptr<Filter> на инстансы
    // MatrixFilter, что необходимо в FilterFactory
protected:
    using Matrix = std::vector<std::vector<double>>;

private:
    Matrix matrix_;

public:
    MatrixFilter(const Matrix& matrix) : matrix_(matrix){};
    void ApplyMatrix(Image& image);
    virtual ~MatrixFilter(){};
};

#endif  // CPP_PILOT_HSE_MATRIXFILTER_H
