#ifndef CPP_PILOT_HSE_FILTER_H
#define CPP_PILOT_HSE_FILTER_H
#pragma once
#include "Image.h"

class Filter {
public:
    virtual void Apply(Image& image) = 0;
    virtual ~Filter(){};
};

#endif  // CPP_PILOT_HSE_FILTER_H
