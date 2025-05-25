#include <fmt/base.h>
#include <spdlog/spdlog.h>

#include <cxxopts.hpp>
#include <iostream>
#include <nlohmann/json.hpp>

#include "config.hpp"
#include "my_lib.h"

int main() {
    int unused; // This variable is used to avoid unused variable warnings.

    int arr[3];
    arr[3] = 100; // This line is intentionally incorrect to demonstrate the use of sanitizers to detect out-of-bounds access bug.

    std::cout << "Project Name: " << project_name << "\n"
              << "Version: " << project_version << "\n";
    std::cout << '\n';

    std::cout << "JSON Lib Version: " << NLOHMANN_JSON_VERSION_MAJOR << "."
              << NLOHMANN_JSON_VERSION_MINOR << "." << NLOHMANN_JSON_VERSION_PATCH << "\n";

    std::cout << '\n';

    std::cout << "FMT Lib Version: " << FMT_VERSION << '\n';

    std::cout << '\n';

    std::cout << "CXXOPTS Lib Version: " << CXXOPTS__VERSION_MAJOR << "." << CXXOPTS__VERSION_MINOR
              << "." << CXXOPTS__VERSION_PATCH << "\n";

    std::cout << '\n';

    std::cout << "SPDLOG Lib Version: " << SPDLOG_VER_MAJOR << "." << SPDLOG_VER_MINOR << "."
              << SPDLOG_VER_PATCH << "\n";

    std::cout << '\n';

    int x = 10;
    int y = 3;

    // std::cout << "10 mod 3 = " << modCompute(x, y) << '\n';

    int result = modCompute(x, y);
    fmt::print("Modulus Operation: {} mod {} = {}\n", x, y, result);

    std::cout << '\n';

    double totalIncome;
    std::cout << "Enter your total income: ";
    std::cin >> totalIncome;

    double stateTaxRate;
    std::cout << "Enter your state tax rate: ";
    std::cin >> stateTaxRate;

    double countyTaxRate;
    std::cout << "Enter your county tax rate: ";
    std::cin >> countyTaxRate;

    double totalTax = computeTax(totalIncome, stateTaxRate, countyTaxRate);
    fmt::print(
        "your total monthly income: {} \n state tax rate: {} \n county tax rate: {} \n Total Tax: "
        "{} \n Net income: {} \n",
        totalIncome, stateTaxRate, countyTaxRate, totalTax, totalIncome - totalTax);

    return 0;
}
