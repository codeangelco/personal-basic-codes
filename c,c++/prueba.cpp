#include <iostream>
#include <cmath>

unsigned long long fibo(unsigned long long n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    unsigned long long n1 = fibo(n - 1);
    n1 += fibo(n - 2);
    return n1;
}

int main() {

    for (int i = 40; i < 100; i++) {
        std::cout << i << "# : " << fibo(i) << std::endl;
    }

    return 0;
}