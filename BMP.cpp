#include "BMP.h"
#include <iostream>

Image BMP::Read(const std::string& path) {
    std::ifstream file;
    file.open(path, std::ios_base::binary);
    if (!file.is_open()) {
        throw std::ios_base::failure("Could not open the file on read");
    }
    file.read(reinterpret_cast<char*>(&header_), BITMAP_FILE_HEADER_SIZE);
    if (header_.signature != BMP_SIGNATURE) {
        throw std::ios_base::failure("Wrong file signature");
    }
    file.read(reinterpret_cast<char*>(&info_header_), DIB_HEADER_SIZE);
    Image result(info_header_.width, info_header_.height);
    ReadColors(file, result, result.GetWidth() % 4);
    file.close();
    return result;
}

void BMP::Write(const std::string& path, const Image& image) {
    std::ofstream file;
    file.open(path, std::ios_base::binary);
    if (!file.is_open()) {
        throw std::ios_base::failure("Could not open the file on write");
    }
    info_header_.width = image.GetWidth();
    info_header_.height = image.GetHeight();
    info_header_.image_size = image.GetWidth() * image.GetHeight() * 3;
    file.write(reinterpret_cast<const char*>(&header_), BITMAP_FILE_HEADER_SIZE);
    file.write(reinterpret_cast<const char*>(&info_header_), DIB_HEADER_SIZE);
    for (int32_t i = 0; i < image.GetHeight(); ++i) {
        for (int32_t j = 0; j < image.GetWidth(); ++j) {
            file.write(reinterpret_cast<const char*>(image.GetColor(j, i).Get()), 3);
        }
        const unsigned int padding_amount = (4 - (image.GetWidth() * 3) % 4) % 4;
        for (unsigned int k = 0; k < padding_amount; ++k) {
            file.write("0", 1);
        }
    }
    file.close();
}

void BMP::ReadColors(std::ifstream& file, Image& result, unsigned int padding) {
    char row[result.GetWidth() * 3];
    for (int32_t i = 0; i < result.GetHeight(); ++i) {
        file.read(row, result.GetWidth() * 3);
        file.seekg(padding, std::ios_base::cur);
        for (int32_t j = 0; j < result.GetWidth() * 3; j += 3) {
            result.SetColor(j / 3, i, Color(row[j], row[j+1], row[j+2]));
        }
    }
}
