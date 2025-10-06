#include <stdio.h>
#define infinity 2147483647

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1+1], R[n2+1];
    for (int i = 0; i < n1; i++) L[i] = arr[l+i];
    L[n1] = infinity;
    for (int i = 0; i < n2; i++) R[i] = arr[m+1+i];
    R[n2] = infinity;
    int i = 0, j = 0;
    for (int k = l; k <= r; k++) {
        if (L[i] > R[j]) {
            arr[k] = R[j];
            j++;
        } else {
            arr[k] = L[i];
            i++;
        }
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int 

    return 0;
}