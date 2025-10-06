#include <iostream>
using namespace std;

int fibo(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    int ans = 0;
    ans += fibo(n - 1);
    ans += fibo(n - 2);
    return ans;
}

int main() {
    int n;
    cin >> n;
    while (n != -1) {
        cout << fibo(n) << endl;
        cin >> n;
    }
    
    return 0;
}