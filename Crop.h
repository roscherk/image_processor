#ifndef CPP_PILOT_HSE_CROP_H
#define CPP_PILOT_HSE_CROP_H
#pragma once
#include "Filter.h"

class Crop : public Filter {
    int32_t new_width_ = 0;
    int32_t new_height_ = 0;
public:
    Crop(int32_t new_width, int32_t new_height) : new_width_(new_width), new_height_(new_height) {};
    virtual void Apply(Image& image) final;
    virtual ~Crop(){};
};

#endif  // CPP_PILOT_HSE_CROP_H
