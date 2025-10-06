#include <stdio.h>
#include <stdlib.h>
#define MAXT 100000

int BinarySearch(int *arr, int i, int j, int k) {
    int r = -1, m;
    while (i <= j) {
        m = (i + j) / 2;
        if (k == arr[m]) {
            r = m;
            break;
        } else {
            if (k > arr[m]) i = m + 1;
            else j = m - 1;
        }
    }
    if (r == -1) r = (-1) * i - 1;
    return r;
}

int BinarySearchFirstOccurrence(int *arr, int i, int j, int k) {
    int r, r2;
    r = BinarySearch(arr,i,j,k);
    if (r >= 0) {
        r2 = BinarySearch(arr,i,r-1,k);
        while (r2 >= 0) {
            r = r2;
            r2 = BinarySearch(arr,i,r-1,k);
        }
    }
    return r;
}

int BinarySearchLastOccurrence(int *arr, int i, int j, int k) {
    int r, r2;
    r = BinarySearch(arr,i,j,k);
    if (r >= 0) {
        r2 = BinarySearch(arr,r+1,j,k);
        while (r2 >= 0) {
            r = r2;
            r2 = BinarySearch(arr,r+1,j,k);
        }
    }
    return r;
}

int main() {
    int n, q;
    scanf("%d %d",&n,&q);

    int acc[n+1], temp;
    acc[0] = 0;
    for (int i = 1; i <= n; i++) {
        

    }


    return 0;
}