#include <iostream>

#include "my_lib.h"

int main(){
    int x = 10;
    int y = 3;

    std::cout << "10 mod 3 = " << modCompute(x, y) << '\n';

    return 0;
}
