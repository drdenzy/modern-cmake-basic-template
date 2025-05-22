#include <iostream>

#include "my_lib.h"
#include "config.hpp"

int main(){

    std::cout << "Project Name: " << project_name << "\n"
            << "Version: " << project_version << "\n";
    std::cout << '\n';


    int x = 10;
    int y = 3;

    std::cout << "10 mod 3 = " << modCompute(x, y) << '\n';

    return 0;
}
