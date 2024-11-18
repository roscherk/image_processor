#include <catch.hpp>
#include <cstring>
#include "Image.h"

TEST_CASE("Image") {
    const int32_t width = 640;
    const int32_t height = 480;
    Image image(width, height);
    REQUIRE((image.GetWidth() == width && image.GetHeight() == height));
    for (int32_t i = 0; i < image.GetHeight(); ++i) {
        for (int32_t j = 0; j < image.GetWidth(); ++j) {
            image.SetColor(j, i, Color(round(255 * (j / image.GetWidth())),
                                 round(255 * (1 - (j / image.GetWidth()))),
                                 round(255 * (i / image.GetHeight()))));
        }
    }
    for (int32_t i = 0; i < image.GetHeight(); ++i) {
        for (int32_t j = 0; j < image.GetWidth(); ++j) {
            REQUIRE(image.GetColor(j, i) == Color(round(255 * (j / image.GetWidth())),
                                                  round(255 * (1 - (j / image.GetWidth()))),
                                                  round(255 * (i / image.GetHeight()))));
        }
    }
}
