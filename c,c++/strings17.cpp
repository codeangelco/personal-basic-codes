#include <bits/stdc++.h>
using namespace std;

int main() {
    string sopa;
    getline(cin, sopa);

    // reverse(sopa.begin(), sopa.end());

    // cout << sopa.find("ho") << endl;

    // transform(sopa.begin(), sopa.end(), sopa.begin(), ::toupper);

    // sort(sopa.begin(), sopa.end());
    // sopa.erase(unique(sopa.begin(), sopa.end()), sopa.end());

    sopa = sopa.substr(0, 5);

    char ch;
    if (!(cin >> ch)) {
        sopa = "-1";
    } else {
        size_t pos = sopa.find_last_of(ch);
        sopa = (pos == string::npos) ? "-1" : to_string((int)pos);
    }

    cout << sopa << endl;

    return 0;
}