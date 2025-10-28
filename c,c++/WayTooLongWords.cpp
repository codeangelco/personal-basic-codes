#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void solver() {
    string palabra;
    cin >> palabra;
    if (palabra.length() > 10)
        cout << palabra.front() << palabra.length() - 2 << palabra.back() << endl;
    else
        cout << palabra << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solver();
    }

    return 0;
}