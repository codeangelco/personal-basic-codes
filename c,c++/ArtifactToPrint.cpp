#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {

    char letra;
    int flag_t = 0, flag_a = 0, flag_p = 0;
    int t = 10;

    while (t--) {
        cin >> letra;
        if (letra == 'T') flag_t = 1;
        if (flag_t) {
            if (letra == 'A') flag_a = 1;
        }
        if (flag_a) {
            if (letra == 'P') flag_p = 1;
        }
    }
    if (flag_a+flag_p+flag_t == 3) cerr << "S" << endl;
    else cerr << "N" << endl;

    return 0;
}