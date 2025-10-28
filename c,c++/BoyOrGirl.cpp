#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    if (s.length() % 2 == 0) {
        cout << "CHAT WITH HER!" << endl;
    } else {
        cout << "IGNORE HIM!" << endl;
    }

    return 0;
}