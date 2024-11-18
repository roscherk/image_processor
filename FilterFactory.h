#ifndef CPP_PILOT_HSE_FILTERFACTORY_H
#define CPP_PILOT_HSE_FILTERFACTORY_H
#pragma once
#include "Crop.h"
#include "Custom.h"
#include "EdgeDetection.h"
#include "Filter.h"
#include "GaussianBlur.h"
#include "Grayscale.h"
#include "MatrixFilter.h"
#include <memory>
#include "Negative.h"
#include "Sharpening.h"

class FilterFactory {
public:
    enum class FilterType {
        CROP,
        CUSTOM,
        EDGE_DETECTION,
        GAUSSIAN_BLUR,
        GRAYSCALE,
        NEGATIVE,
        SHARPENING,
    };
    static std::unique_ptr<Filter> CreateFilter(const FilterType& type);
    static std::unique_ptr<Filter> CreateFilter(const FilterType& type, uint32_t param);
    static std::unique_ptr<Filter> CreateFilter(const FilterType& type, uint32_t new_width,
                                                uint32_t new_height);
};

#endif  // CPP_PILOT_HSE_FILTERFACTORY_H
