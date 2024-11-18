#ifndef CPP_PILOT_HSE_SHARPENING_H
#define CPP_PILOT_HSE_SHARPENING_H
#pragma once
#include "MatrixFilter.h"

class Sharpening : public MatrixFilter {
public:
    Sharpening() : MatrixFilter({{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}}){};
    virtual void Apply(Image& image) final;
    virtual ~Sharpening(){};
};

#endif  // CPP_PILOT_HSE_SHARPENING_H
