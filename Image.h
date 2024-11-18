#ifndef CPP_PILOT_HSE_IMAGE_H
#define CPP_PILOT_HSE_IMAGE_H
#pragma once
#include "Color.h"
#include <cstdint>
#include <vector>

class Image {
    int32_t width_ = 0;
    int32_t height_ = 0;
    std::vector<std::vector<Color>> data_;

public:
    Image(int32_t width, int32_t height);
    const int32_t GetWidth() const {
        return width_;
    }
    const int32_t GetHeight() const {
        return height_;
    }
    const Color& GetColor(size_t x, size_t y) const {
        return data_[y][x];
    }
    void Resize(int32_t new_width, int32_t new_height);
    void SetColor(int32_t x, int32_t y, const Color& new_color) {
        data_[y][x] = new_color;
    };
};

#endif  // CPP_PILOT_HSE_IMAGE_H
