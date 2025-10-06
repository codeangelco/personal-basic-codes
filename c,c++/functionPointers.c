#include <stdio.h>
#include <stdlib.h>

int suma(int a, int b) {
    return a + b;
}

int compar(const void *item1, const void *item2) {
    // if ((*(int*)item1) % 2 == 1 && (*(int*)item2) % 2 == 0) {
    //     return 1;
    // } else if ((*(int*)item1) % 2 == 0 && (*(int*)item2) % 2 == 1) {
    //     return -1;
    // }
    // if ((*(int*)item2) >= (*(int*)item1)) {
    //     return 1;
    // } else
    //     return -1;
}

int main() {
    // int (*f)(int, int) = suma;
    // printf("%d\n",f(2,3));
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    qsort(arr,10,sizeof(int),compar);
    for (int i = 0; i < 10; i++) {
        printf("%d\n",arr[i]);
    }
    return 0;
}