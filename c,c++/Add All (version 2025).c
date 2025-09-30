#include <stdio.h>
#define infinity 9223372036854775807
#define MAXT 1000001

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return (2 * i) + 2;
}

void exchange(long long int Q[], int a, int b) {
    long long int temp = Q[a];
    Q[a] = Q[b];
    Q[b] = temp;
}

void MinHeapify(long long int Q[], int i, int heapSize) {
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

long long int MPQ_minimum(long long int Q[]) {
    return Q[0];
}

long long int MPQ_extract(long long int Q[], long long int *heapSize) {
    long long int min = -infinity;    // <- Corregido por el profe
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

void MPQ_decreaseKey(long long int Q[], long long int i, long long int key) {
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

void MPQ_insert(long long int Q[], long long int key, long long int *heapSize) {
    (*heapSize)++;
    Q[*heapSize - 1] = infinity;
    MPQ_decreaseKey(Q, *heapSize - 1, key);
} 

long long int AddAll(long long int Q[], long long int n) {
    long long result = 0, value1, value2, value3;

    while (n >= 2) {
        value1 = MPQ_extract(Q, &n);
        value2 = MPQ_extract(Q, &n);
        value3 = value1 + value2;
        result = result + value3;
        MPQ_insert(Q, value3, &n);
    }
    return result;
}

int main() {
    long long int totalCases, idCase, n, idElement, heapSize;
    long long Q[MAXT], element;

    scanf("%lld",&totalCases);

    for (idCase = 0; idCase < totalCases; idCase++) {
        heapSize = 0;
        scanf("%lld",&n);
        for (idElement = 0; idElement < n; idElement++) {
            scanf("%lld",&element);
            MPQ_insert(Q, element, &heapSize);
        }
        printf("%lld\n",AddAll(Q,n));
    }

    return 0;
}