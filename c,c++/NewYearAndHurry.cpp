#include <iostream>
using namespace std;

int main() {
    int n, time, amount = 0, i;
    cin >> n >> time;
    time = 240 - time;
    for (i = 1; i <= n; i++) {
        amount += i * 5;
        if (amount > time) {
            printf("%d\n",i - 1);
            return 0;
        }
    }
    printf("%d\n",i - 1);
    return 0;
}