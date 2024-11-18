#ifndef CPP_PILOT_HSE_NEGATIVE_H
#define CPP_PILOT_HSE_NEGATIVE_H
#pragma once
#include "Filter.h"

class Negative : public Filter {
public:
    virtual void Apply(Image& image) final;
    virtual ~Negative(){};
};

#endif  // CPP_PILOT_HSE_NEGATIVE_H
