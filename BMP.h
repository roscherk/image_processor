#ifndef CPP_PILOT_HSE_BMP_H
#define CPP_PILOT_HSE_BMP_H
#pragma once
#include "IO.h"
#include "Image.h"

class BMP : public IO<Image> {
    static const unsigned int BMP_SIGNATURE = 0x4D42;
    static const unsigned int BITMAP_FILE_HEADER_SIZE = 14;
    static const unsigned int DIB_HEADER_SIZE = 40;

    struct BitmapFileHeader {
        uint16_t signature = BMP_SIGNATURE;  // default
        uint32_t file_size = 0;
        uint16_t reserved1 = 0;  // default
        uint16_t reserved2 = 0;  // default
        uint32_t offset = 54;    // default
    };

    struct DIBHeader {
        uint32_t size = 40;  // default
        int32_t width = 0;
        int32_t height = 0;
        uint16_t planes = 1;          // взято с вики
        uint16_t bit_per_pixel = 24;  // default
        uint32_t compression = 0;     // default
        uint32_t image_size = 0;
        int32_t x_pixels_per_meter = 2835;  // взято с вики
        int32_t y_pixels_per_meter = 2835;  // взято с вики
        int32_t colors_used = 0;            // default
        int32_t colors_important = 0;       // default
    };

    BitmapFileHeader header_;
    DIBHeader info_header_;

    void ReadColors(std::ifstream& file, Image& result, unsigned int padding);

public:
    virtual Image Read(const std::string& path) final;
    virtual void Write(const std::string& path, const Image& data) final;
};

#endif  // CPP_PILOT_HSE_BMP_H
