#ifndef CPP_PILOT_HSE_IO_H
#define CPP_PILOT_HSE_IO_H
#pragma once
#include <fstream>
#include <string>

template <typename T>
class IO {
public:
    virtual T Read(const std::string& path) = 0;
    virtual void Write(const std::string& path, const T& data) = 0;
};

#endif  // CPP_PILOT_HSE_IO_H
