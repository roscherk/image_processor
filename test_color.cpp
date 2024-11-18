#include <catch.hpp>
#include <cstring>
#include "Color.h"

TEST_CASE("Color") {
    // stored in BGR format
    Color color(1, 2,3);
    REQUIRE(color.R() == 3);
    REQUIRE(color.G() == 2);
    REQUIRE(color.B() == 1);
    color = Color(10, 11, 12);
    REQUIRE(color.R() == 12);
    REQUIRE(color.G() == 11);
    REQUIRE(color.B() == 10);
    REQUIRE(color == Color(10, 11, 12));
}
