#include "my_lib.h"

#include <cmath>

/**
 * @brief Computes the modulus of two integers.
 *
 * @param x The first integer.
 * @param y The second integer.
 * @return int The modulus of x and y.
 */
int modCompute(int x, int y) {
    return x % y;
}

/**
 * @brief Computes the total tax based on income and tax rates.
 *
 * @param income The income amount.
 * @param stateTaxRate The state tax rate.
 * @param countyTaxRate The county tax rate.
 * @return double The total tax amount.
 */
double computeTax(double income, double stateTaxRate, double countyTaxRate) {
    double stateTax = income * stateTaxRate;
    double countyTax = income * countyTaxRate;
    double totalTax = stateTax + countyTax;

    return roundToDecimalPlaces(totalTax, 4);
}

/**
 * @brief Rounds a double value to a specified number of decimal places.
 *
 * @param value The double value to round.
 * @param decimalPlaces The number of decimal places to round to.
 * @return double The rounded value.
 */
double roundToDecimalPlaces(double value, int decimalPlaces) {
    double factor = std::pow(10.0, decimalPlaces);
    return std::round(value * factor) / factor;
}
