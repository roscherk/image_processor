#include <cstring>
#include "Color.h"

Color::Color(unsigned char b, unsigned char g, unsigned char r) {
    ptr_ = new unsigned char[3];
    ptr_[0] = b;
    ptr_[1] = g;
    ptr_[2] = r;
}
Color& Color::operator=(const Color& other) {
    if (ptr_ == nullptr) {
        ptr_ = new unsigned char[3];
    }
    std::memcpy(ptr_, other.ptr_, 3);
    return *this;
}
Color::Color(const Color& other) {
    ptr_ = new unsigned char[3];
    std::memcpy(ptr_, other.ptr_, 3);
}
