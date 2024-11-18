#include <catch.hpp>
#include <cstring>
#include "BMP.h"

TEST_CASE("Input/Output") {
    BMP file;
    Image image1 = file.Read("../projects/image_processor/examples/example.bmp");
    file.Write("../projects/image_processor/examples/output.bmp", image1);
    Image image2 = file.Read("../projects/image_processor/examples/output.bmp");
    REQUIRE((image1.GetWidth() == image2.GetWidth() &&
            image1.GetHeight() == image2.GetHeight()));
    for (int32_t i = 0; i < image1.GetHeight(); ++i) {
        for (int32_t j = 0; j < image1.GetWidth(); ++j) {
            REQUIRE(image1.GetColor(j, i) == image2.GetColor(j, i));
        }
    }
}

TEST_CASE("Exceptions") {
    BMP file;
    try {
        Image image = file.Read("/wrong_file_path");
        throw std::ios_base::failure("Wrong");
    } catch (const std::ios_base::failure& exception) {
        REQUIRE(strcmp(exception.what(), "Could not open the file on read"));
    }

    try {
        Image image = file.Read("../projects/image_processor/examples/example.png");
        throw std::ios_base::failure("Wrong");
    } catch (const std::ios_base::failure& exception) {
        REQUIRE(strcmp(exception.what(), "Wrong file signature"));
    }
}
