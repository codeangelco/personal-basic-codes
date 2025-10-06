#include <iostream>
#include <math.h>
using namespace std;

int main() {
    // 0001001001 -> 2
    // 0110110110111 -> 5
    int d2 = 10, d2_s = 3;
    int d5 = 13, d5_s = 9;

    int a2, b5;
    cin >> a2 >> b5;
    int r2 = floor(((double)a2 / (double)d2) * (double)d2_s);
    int r5 = floor(((double)b5 / (double)d5) * (double)d5_s);

    cerr << "2: " << r2 + 1 << "   | 5: " << r5 + 1 << endl;
    return 0;
}
