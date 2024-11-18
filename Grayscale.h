#ifndef CPP_PILOT_HSE_GRAYSCALE_H
#define CPP_PILOT_HSE_GRAYSCALE_H
#pragma once
#include "Filter.h"

class Grayscale : virtual public Filter {
public:
    virtual void Apply(Image& image);
    virtual ~Grayscale(){};
};

#endif  // CPP_PILOT_HSE_GRAYSCALE_H
