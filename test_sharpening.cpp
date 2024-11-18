#include <catch.hpp>
#include "BMP.h"
#include "Sharpening.h"
#include <iostream>

TEST_CASE("Sharpening") {
    const int error = 10;
    BMP file;
    Image image = file.Read("../projects/image_processor/examples/example.bmp");
    Image reference = file.Read("../projects/image_processor/test_references/sharpening.bmp");
    Sharpening sharpening;
    sharpening.Apply(image);
    for (int32_t i = 0; i < image.GetHeight(); ++i) {
        for (int32_t j = 0; j < image.GetWidth(); ++j) {
            int errors_count = 0;
            if (abs(image.GetColor(j, i).R() - reference.GetColor(j, i).R()) <= error) {
                ++errors_count;
            } else if (abs(image.GetColor(j, i).G() - reference.GetColor(j, i).G()) <= error) {
                ++errors_count;
            } else if (abs(image.GetColor(j, i).B() - reference.GetColor(j, i).B()) <= error) {
                ++errors_count;
            }
            REQUIRE(errors_count <= 1);  // допускаем отклонения больше погрешности по одному из каналов
        }
    }
}



