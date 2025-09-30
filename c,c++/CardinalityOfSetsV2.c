#include <stdio.h>
#define infinity 2147483647

// MINIMAAAAAAAAAAAAAAAAA

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

void build_MPQ(int Q[], int heapSize) {
    for (int i = (heapSize / 2) - 1; i >= 0; i--) {
        MinHeapify(Q,i,heapSize);
    }
}

int main() {
    int n, m, size_a = 0, inter = 0, temp;
    scanf("%d %d",&n,&m);
    int A[n + m];
    for (int i = 0; i < n + m; i++) {
        scanf("%d",&temp);
        MPQ_insert(A,temp, &size_a);
    }
    while (size_a >= 2) {
        temp = MPQ_extract(A,&size_a);
        if (temp == MPQ_minimum(A)) {
            MPQ_extract(A,&size_a);
            inter++;
        }
    }
    
    printf("%d %d %d %d\n", n - inter, inter, m - inter, n + (m - inter));
    return 0;
}