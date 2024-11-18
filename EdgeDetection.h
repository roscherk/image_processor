#ifndef CPP_PILOT_HSE_EDGEDETECTION_H
#define CPP_PILOT_HSE_EDGEDETECTION_H
#pragma once
#include "MatrixFilter.h"
#include "Grayscale.h"

class EdgeDetection : public MatrixFilter, public Grayscale {
    int threshold_ = 0;

public:
    EdgeDetection(int threshold) : MatrixFilter({{0, -1, 0},{-1, 4, -1},{0, -1, 0}}), threshold_(threshold) {};
    virtual void Apply(Image& image) final;
    virtual ~EdgeDetection(){};
};

#endif  // CPP_PILOT_HSE_EDGEDETECTION_H
