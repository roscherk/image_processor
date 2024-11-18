#include <catch.hpp>
#include "BMP.h"
#include "EdgeDetection.h"
#include <iostream>

TEST_CASE("EdgeDetection") {
    const int error = 25;
    BMP file;
    Image image = file.Read("../projects/image_processor/examples/example.bmp");
    Image reference = file.Read("../projects/image_processor/test_references/edge_detection.bmp");
    EdgeDetection edge_detection(8);
    edge_detection.Apply(image);
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
            REQUIRE(errors_count <= 1);
        }
    }
}
