#include <catch.hpp>
#include "BMP.h"
#include "Grayscale.h"

TEST_CASE("Grayscale") {
    const int error = 5;
    BMP file;
    Image image = file.Read("../projects/image_processor/examples/example.bmp");
    Image reference = file.Read("../projects/image_processor/test_references/grayscale.bmp");
    Grayscale grayscale;
    grayscale.Apply(image);
    for (int32_t i = 0; i < image.GetHeight(); ++i) {
        for (int32_t j = 0; j < image.GetWidth(); ++j) {
            REQUIRE(abs(image.GetColor(j, i).R() - reference.GetColor(j, i).R()) <= error);
            REQUIRE(abs(image.GetColor(j, i).G() - reference.GetColor(j, i).G()) <= error);
            REQUIRE(abs(image.GetColor(j, i).B() - reference.GetColor(j, i).B()) <= error);
        }
    }
}


