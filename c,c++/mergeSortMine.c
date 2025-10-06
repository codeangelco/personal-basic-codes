#include <stdio.h>
#define infinity 2147483647

void MergeSort(int arr[], int l, int r);
void Merge(int arr[], int l, int m, int r);

int main() {
    int n;
    while (scanf("%d",&n)) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d",&arr[i]);
        MergeSort(arr,0,n-1);
        for (int i = 0; i < n; i++) {
            printf("%d",arr[i]);
            if (i < n-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

void MergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        Merge(arr, l, m, r);
    }
}

void Merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1+1], R[n2+1];
    for (int i = 0; i < n1; i++) L[i] = arr[i+l];
    for (int i = 0; i < n2; i++) R[i] = arr[i+m+1];
    L[n1] = infinity;
    R[n2] = infinity;
    int i = 0, j = 0;
    for (int k = l; k <= r; k++) {
        if (L[i] < R[j]) arr[k] = L[i++];
        else arr[k] = R[j++];
    }
}