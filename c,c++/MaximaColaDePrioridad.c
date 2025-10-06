#include <stdio.h>
#define infinity 2147483647

// MINIMAAAAAAAAAAAAAAAAA

void mostrar(int Q[], int size) {
    if (size == 0) {
        printf("\nNo hay valores.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d",Q[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return (2 * i) + 2;
}

void exchange(int Q[], int a, int b) {
    int temp = Q[a];
    Q[a] = Q[b];
    Q[b] = temp;
}

void MinHeapify(int Q[],int i,int heapSize) {
    int least;
    int l = left(i);
    int r = right(i);
    if (l < heapSize && Q[l] < Q[i]) {
        least = l;
    } else {
        least = i;
    }
    if (r < heapSize && Q[r] < Q[least]) {
        least = r;
    }
    if (least != i) {
        exchange(Q, i, least);
        MinHeapify(Q,least,heapSize);
    }
}

int MPQ_minimum(int Q[]) {
    return Q[0];
}

int MPQ_extract(int Q[], int *heapSize) {
    int min = -infinity;    // <- Corregido por el profe
    if (*heapSize < 1) {
        printf("heap underflow\n");
        // return -1;     <- Corregido por el profe
    } else {
        min = Q[0];
        Q[0] = Q[*heapSize - 1];
        (*heapSize)--;
        MinHeapify(Q,0,*heapSize);
        // return min;     <- Corregido por el profe
    }
    return min;    // <- Corregido por el profe
}

void MPQ_decreaseKey(int Q[], int i, int key) {
    if (key > Q[i]) {
        printf("new key is higher than current key\n");
    } else {
        Q[i] = key;
        while (i > 0 && Q[parent(i)] > Q[i]) {
            exchange(Q,i,parent(i));
            i = parent(i);
        }
    }
}

void MPQ_insert(int Q[], int key, int *heapSize) {
    (*heapSize)++;
    Q[*heapSize - 1] = infinity;
    MPQ_decreaseKey(Q, *heapSize - 1, key);
} 

// void build_MPQ(int Q[], int heapSize) {              // <- Para maxima priodidad solo funcionaria si la lista a organizar esta invertida.
//     for (int i = (heapSize / 2) - 1; i >= 0; i--) {
//         MinHeapify(Q,i,heapSize);
//     }
// }

void MaxPQ_insert(int Q[], int key, int *heapSize) {
    MPQ_insert(Q, -key, heapSize);
}

int MaxPQ_maximum(int Q[]) {
    return -(MPQ_minimum(Q));
}

int MaxPQ_extract(int Q[], int* heapSize) {
    return -(MPQ_extract(Q,heapSize));
}

void build_MaxPQ(int Q[], int heapSize) {              // <- Para maxima priodidad solo funcionaria si la lista a organizar esta invertida.
    for (int i = 0; i < heapSize; i++) {
        Q[i] = -(Q[i]);
    }
    for (int i = (heapSize / 2) - 1; i >= 0; i--) {
        MinHeapify(Q,i,heapSize);
    }
}

int main() {

    int arr[] = {1, 5, 2, 3, 7, 9, 10};
    int heapSize = 7;
    
    build_MaxPQ(arr, heapSize);
    printf("%d\n",MaxPQ_maximum(arr));
    MaxPQ_extract(arr, &heapSize);
    MaxPQ_extract(arr, &heapSize);
    printf("%d\n",MaxPQ_maximum(arr));
    MaxPQ_insert(arr, 100, &heapSize);
    MaxPQ_insert(arr, 10, &heapSize);
    printf("%d\n",MaxPQ_maximum(arr));
    MaxPQ_extract(arr, &heapSize);
    printf("%d\n",MaxPQ_maximum(arr));

    return 0;
}