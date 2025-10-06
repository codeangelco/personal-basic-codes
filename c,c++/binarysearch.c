#include <stdio.h>
#include <stdlib.h>
#define MAXT 100

int recursive_binarysearch(int *arr, int i, int j, int k) {
    int m;
    if (i > j) return (-1) * i - 1;
    else {
        m = (i + j) / 2;
        if (k == arr[m]) return m;
        else {
            if (k > arr[m]) return recursive_binarysearch(arr, m + 1, j, k);
            else return recursive_binarysearch(arr, i, m - 1, k);
        }
    }
}

int iterative_binarysearch(int *arr, int i, int j, int k) {
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

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    system("pause");

    printf("%d\n", iterative_binarysearch(arr,0,5,7));
    printf("%d\n", recursive_binarysearch(arr,0,5,7));

    return 0;
}