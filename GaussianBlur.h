#ifndef CPP_PILOT_HSE_GAUSSIANBLUR_H
#define CPP_PILOT_HSE_GAUSSIANBLUR_H
#pragma once
#include "MatrixFilter.h"

class GaussianBlur : public MatrixFilter {
public:
    GaussianBlur(int sigma) : MatrixFilter(CreateMatrix(sigma)){};
    virtual void Apply(Image& image) final;
    virtual ~GaussianBlur(){};
    static Matrix CreateMatrix(int sigma);
};

#endif  // CPP_PILOT_HSE_GAUSSIANBLUR_H
