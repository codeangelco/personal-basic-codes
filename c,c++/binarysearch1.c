#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int BinarySearch(int *arr, int i, int j, int k) {
    int r = -1, m;
    while (i <= j) {
        m = (i + j) / 2;
        if (k == arr[m]) {
            r = m;
            break;
        } else {
            if (arr[m] > k) j = m - 1;
            else i = m + 1;
        }
    }
    if (r == -1) r = (-1) * i - 1;
    return r;
}

void solve() {
    int n = rand() % 10+1;
    int arr[n];

    for (int i = 0; i < n; i++) arr[i] = i+1;

    for (int i = 0; i < n; i++) printf("%d\n",arr[i]);

    int numero = rand() % 10+1;

    printf("\n\n%d - #%d\n",BinarySearch(arr,0,n-1,numero),numero);
    
}


int main() {
    srand((unsigned int)time(NULL));
    int t = 10;
    while (t--)
    {
        solve();
        printf("----------------------------------------\n");
    }
    
    
    return 0;
}


