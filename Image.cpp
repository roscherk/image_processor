#include "Image.h"
Image::Image(int32_t width, int32_t height) : width_(width), height_(height){
    for (int32_t i = 0; i < height; ++i) {
        data_.push_back(std::vector<Color>(width));
    }
}

void Image::Resize(int32_t new_width, int32_t new_height) {
    if (data_.empty()) {
        data_.resize(new_height);
    } else {
        // crop image
        data_.erase(data_.cbegin(), data_.begin() + height_ - new_height);
    }
    for (int32_t i = 0; i < new_height; ++i) {
        data_[i].resize(new_width);
    }
    width_ = new_width;
    height_ = new_height;
}
