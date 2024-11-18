#include "FilterFactory.h"

std::unique_ptr<Filter> FilterFactory::CreateFilter(const FilterType& type) {
    switch (type) {
        case FilterType::CROP:
            throw std::domain_error("CreateFilter(const Filter::FilterType& type): too few parameters for Crop()");
        case FilterType::CUSTOM:
            break;
        case FilterType::EDGE_DETECTION:
            throw std::domain_error("CreateFilter(const Filter::FilterType& type): too few parameters for EdgeDetection(threshold)");
        case FilterType::GAUSSIAN_BLUR:
            throw std::domain_error("CreateFilter(const Filter::FilterType& type): too few parameters for GaussianBlur(sigma)");
        case FilterType::GRAYSCALE:
            return std::make_unique<Grayscale>();
        case FilterType::NEGATIVE:
            return std::make_unique<Negative>();
        case FilterType::SHARPENING:
            return std::make_unique<Sharpening>();
    }
    return nullptr;
}

std::unique_ptr<Filter> FilterFactory::CreateFilter(const FilterType& type, uint32_t new_width, uint32_t new_height) {
    switch (type) {
        case FilterType::CROP:
            return std::make_unique<Crop>(new_width, new_height);
        case FilterType::CUSTOM:
            break;
        case FilterType::EDGE_DETECTION:
            throw std::domain_error(
                "CreateFilter(const Filter::FilterType& type, ...): too many parameters for EdgeDetection(threshold)");
        case FilterType::GAUSSIAN_BLUR:
            throw std::domain_error(
                "CreateFilter(const Filter::FilterType& type, ...): too many parameters for GaussianBlur(sigma)");
        case FilterType::GRAYSCALE:
            throw std::domain_error(
                "CreateFilter(const Filter::FilterType& type, ...): too many parameters for Grayscale()");
        case FilterType::NEGATIVE:
            throw std::domain_error(
                "CreateFilter(const Filter::FilterType& type, ...): too many parameters for Negative()");
        case FilterType::SHARPENING:
            throw std::domain_error(
                "CreateFilter(const Filter::FilterType& type, ...): too many parameters for Sharpening()");
    }
    return nullptr;
}

std::unique_ptr<Filter> FilterFactory::CreateFilter(const FilterFactory::FilterType& type, uint32_t param) {
    switch (type) {
        case FilterType::CROP:
            throw std::domain_error(
                "CreateFilter(const Filter::FilterType& type, uint32_t param): too few parameters for Crop()");
        case FilterType::CUSTOM:
            return std::make_unique<Custom>(param);
            break;
        case FilterType::EDGE_DETECTION:
            return std::make_unique<EdgeDetection>(param);
        case FilterType::GAUSSIAN_BLUR:
            return std::make_unique<GaussianBlur>(param);
        case FilterType::GRAYSCALE:
            throw std::domain_error(
                "CreateFilter(const Filter::FilterType& type, uint32_t param): too many parameters for Grayscale()");
        case FilterType::NEGATIVE:
            throw std::domain_error(
                "CreateFilter(const Filter::FilterType& type, uint32_t param): too many parameters for Negative()");
        case FilterType::SHARPENING:
            throw std::domain_error(
                "CreateFilter(const Filter::FilterType& type, uint32_t param): too many parameters for Sharpening()");
    }
    return nullptr;
}
