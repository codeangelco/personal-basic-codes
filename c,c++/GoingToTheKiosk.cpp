#include <iostream>
using namespace std;
#define endl '\n'

int main() {
    int a, b, c, devuelta;
    cin >> a >> b >> c;
    devuelta = b - a;
    if (devuelta % c == 0) cerr << "S" << endl;
    else cerr << "N" << endl;

    return 0;
}