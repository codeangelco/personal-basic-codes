#include <iostream>

int main() {
    int a = 4, b = 7;
    std::cerr << "a & b = " << (a & b) << std::endl;
    std::cerr << "a && b = " << (a && b) << std::endl;
    std::cerr << "a | b = " << (a | b) << std::endl;
    std::cerr << "a || b = " << (a || b) << std::endl;
    std::cerr << "a ^ b = " << (a ^ b) << std::endl;
    std::cerr << "~a, ~b = " << ~a << " " << ~b << std::endl;
    std::cerr << "a << 1 = " << (a << 1) << std::endl;
    std::cerr << "a >> 1 = " << (a >> 1) << std::endl;
    std::cerr << "a >> 1 = " << (a >> 2) << std::endl;
    int c = -5;
    std::cerr << "~c = " << ~c << std::endl;
    return 0;
}