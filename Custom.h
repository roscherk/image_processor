#ifndef CPP_PILOT_HSE_CUSTOM_H
#define CPP_PILOT_HSE_CUSTOM_H
#pragma once
#include "Filter.h"
#include "GaussianBlur.h"

class Custom : public Filter {
    int distortion_degree_ = 1;

public:
    Custom(int distortion_degree) : distortion_degree_(distortion_degree){};
    virtual void Apply(Image& image) final;
    void Distort(Image& image);
    void Colorize(Image& image);
};

#endif  // CPP_PILOT_HSE_CUSTOM_H
