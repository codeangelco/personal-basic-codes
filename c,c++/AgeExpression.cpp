#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;

    if (a % __gcd(b, c) == 0) {
        cout << 1 << endl;
        return 0;
    }

    cout << 0 << endl;

    return 0;
}