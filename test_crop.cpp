#include <catch.hpp>
#include "BMP.h"
#include "Crop.h"

TEST_CASE("Crop") {
    BMP file;
    Image image = file.Read("../projects/image_processor/examples/example.bmp");
    Image reference = file.Read("../projects/image_processor/test_references/crop.bmp");
    Crop crop(reference.GetWidth(), reference.GetHeight());
    crop.Apply(image);
    REQUIRE((image.GetWidth() == reference.GetWidth() && image.GetHeight() == reference.GetHeight()));
    for (int32_t i = 0; i < image.GetHeight(); ++i) {
        for (int32_t j = 0; j < image.GetWidth(); ++j) {
            REQUIRE(image.GetColor(j, i) == reference.GetColor(j, i));
        }
    }
}
