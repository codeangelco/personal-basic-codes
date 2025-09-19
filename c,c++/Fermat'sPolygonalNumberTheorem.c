#include <stdio.h>
#define infinity 2147483647
#define MAXT 100001


BinarySearch(long long arr[], int left, int right, long long k) {
    int m;
    while (left <= right)
    {
        m = (left + right) / 2;
        if (arr[m] == k) {
            return m;
        } else if (arr[m] > k) {
            right = m - 1;
        } else {
            left = m + 1;
        }
    }
    return (left * -1) - 1;
}

void Merge(long long arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[i + left];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[i + mid + 1];
    }
    L[n1] = infinity;
    R[n2] = infinity;
    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
    }
}

void MergeSort(long long arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

void triangulares(long long arr[]) {
    for (long long i = 1; i <= MAXT; i++) {
        arr[i - 1] = (i * (i + 1)) / 2;
    }
}

int main() {
    long long arr[MAXT];
    int t, n, formas;
    triangulares(arr);
    scanf("%d",&t);
    while (t--) {
        formas = 0;
        scanf("%d",&n);
        if (BinarySearch(arr, 0, MAXT - 1, n) >= 0) {
            formas++;
        }
        for (int i = 0; i < MAXT; i++) {
            if (arr[i] > n) {
                break;
            }
            int temp = BinarySearch(arr, i, MAXT, n - arr[i]);
            if (temp < 0) {
                continue;
            }
            if (arr[i] + arr[temp] == n) {
                formas++;
            }
        }
        for (int i = 0; i < MAXT; i++) {
            if (arr[i] > n/2) {
                break;
            }
            for (int j = i; j < MAXT; j++) {
                if (arr[i] + arr[j] > n) {
                    break;
                }
                int temp = BinarySearch(arr, j, MAXT, n - arr[i] - arr[j]);
                if (temp < 0) {
                    continue;
                }
                if (arr[i] + arr[j] + arr[temp] == n) {
                    formas++;
                }
            }
        }
        printf("%d\n",formas);
    }
    return 0;
}