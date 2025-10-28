#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    string palabra1, palabra2;
    cin >> palabra1 >> palabra2;
    transform(palabra1.begin(), palabra1.end(), palabra1.begin(), ::tolower);
    transform(palabra2.begin(), palabra2.end(), palabra2.begin(), ::tolower);
    if (palabra1 < palabra2) {
        cout << -1 << endl;
    } else if (palabra1 > palabra2) {
        cout << 1 << endl;
    } else 
        cout << 0 << endl;
}