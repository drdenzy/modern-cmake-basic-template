#include "my_lib.h"
#include <catch2/catch_all.hpp>
using Catch::Approx;

TEST_CASE("modCompute computes modulus correctly", "[modCompute]")
{
    REQUIRE(modCompute(10, 3) == 1);
    REQUIRE(modCompute(25, 5) == 0);
    REQUIRE(modCompute(-7, 4) == -3);
}

TEST_CASE("computeTax computes total tax correctly", "[computeTax]")
{
    double income = 100000;
    double stateRate = 0.05;
    double countyRate = 0.025;
    double expected = 7500.0000;
    REQUIRE(computeTax(income, stateRate, countyRate) ==
            Approx(expected).epsilon(0.0001));
}

TEST_CASE("roundToDecimalPlaces rounds correctly", "[roundToDecimalPlaces]")
{
    REQUIRE(roundToDecimalPlaces(3.1415926, 2) == Approx(3.14));
    REQUIRE(roundToDecimalPlaces(2.71828, 3) == Approx(2.718));
}


TEST_CASE("Modulus computation", "[mod]")
{
    SECTION("Positive numbers")
    {
        REQUIRE(modCompute(10, 3) == 1);
        REQUIRE(modCompute(15, 5) == 0);
    }

    SECTION("Negative numbers")
    {
        REQUIRE(modCompute(-10, 3) == -1);
        REQUIRE(modCompute(10, -3) == 1);
    }
}

TEST_CASE("Tax computation", "[tax]")
{
    const double income = 1000.0;
    const double stateRate = 0.05;
    const double countyRate = 0.02;

    SECTION("Basic tax calculation")
    {
        double expected = 70.0;
        REQUIRE(computeTax(income, stateRate, countyRate) == Approx(expected));
    }

    SECTION("Rounding verification")
    {
        double unrounded = 123.456789;
        REQUIRE(roundToDecimalPlaces(unrounded, 2) == Approx(123.46));
        REQUIRE(roundToDecimalPlaces(unrounded, 4) == Approx(123.4568));
    }
}
