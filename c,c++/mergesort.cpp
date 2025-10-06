#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> L(n1+1), R(n2+1);
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }
    L[n1] = 2147483647;
    R[n2] = 2147483647;
    int i = 0, j = 0, k = p;
    while (k <= r) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
}

void MergeSort(vector<int>& A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int main() {
    vector<int> arr = {5,4,3,2,1};
    MergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
        cerr << arr[i] << " ";
    }
    cerr << endl;
    return 0;
}