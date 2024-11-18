#ifndef CPP_PILOT_HSE_COLOR_H
#define CPP_PILOT_HSE_COLOR_H
#pragma once
#include <memory>
#include <iostream>

struct Color {
    unsigned char* ptr_ = nullptr;
    Color(){};
    Color(const Color& other);
    Color(unsigned char b, unsigned char g, unsigned char r);
    ~Color() {
        delete[] ptr_;
    }
    Color& operator=(const Color& other);
    bool operator==(const Color& other) const {
        return ptr_[0] == other.B() && ptr_[1] == other.G() && ptr_[2] == other.R();
    };
    const unsigned char* Get() const {
        return ptr_;
    }
    const unsigned char R() const {
        return ptr_[2];
    }
    const unsigned char G() const {
        return ptr_[1];
    }
    const unsigned char B() const {
        return ptr_[0];
    }
};

#endif  // CPP_PILOT_HSE_COLOR_H
