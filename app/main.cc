#include <iostream>
#include <nlohmann/json.hpp>

#include "my_lib.h"
#include "config.hpp"

int main(){

    std::cout << "Project Name: " << project_name << "\n"
            << "Version: " << project_version << "\n";
    std::cout << '\n';

    std::cout << "JSON Lib Version: "
    << NLOHMANN_JSON_VERSION_MAJOR << "."
    << NLOHMANN_JSON_VERSION_MINOR << "."
    << NLOHMANN_JSON_VERSION_PATCH << "\n";

  std::cout << '\n';
  
    int x = 10;
    int y = 3;

    std::cout << "10 mod 3 = " << modCompute(x, y) << '\n';

    return 0;
}
