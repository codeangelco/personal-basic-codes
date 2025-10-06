#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAXT 14142

int BinarySearch(int *arr, int i, int j, int k) {
    int r = -1;
    while (i <= j) {
        int m = (i + j) / 2;
        if (arr[m] == k) {
            r = m;
            break;
        } else {
            if (arr[m] > k) j = m - 1;
            else i = m + 1;
        }
    }
    if (r == -1) return (i * -1) - 1;
    return r;
}

int main() {
    int arr[MAXT + 1];
    arr[0] = 0;
    for (int i = 1; i <= MAXT; i++) arr[i] = arr[i-1] + i;

    int t, id, k;
    scanf_s("%d", &t);
    while (t--) {
        scanf_s("%d", &k);
        id = BinarySearch(arr,0,MAXT+1,k);
        if (id > 0) {
            printf("%d %d\n",id+1, id+1);
        } else {
            printf("%d %d\n",arr[((id*-1)-2)],(id*-1)-1);
        }
    }
    
    

       
    return 0;
}