#include <catch.hpp>
#include "BMP.h"
#include "Negative.h"

TEST_CASE("Negative") {
    BMP file;
    Image image = file.Read("../projects/image_processor/examples/example.bmp");
    Image reference = file.Read("../projects/image_processor/test_references/negative.bmp");
    Negative negative;
    negative.Apply(image);
    for (int32_t i = 0; i < image.GetHeight(); ++i) {
        for (int32_t j = 0; j < image.GetWidth(); ++j) {
            REQUIRE(image.GetColor(j, i) == reference.GetColor(j, i));
        }
    }
}

