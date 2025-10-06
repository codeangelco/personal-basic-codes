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

void build_MPQ(int Q[], int heapSize) {
    for (int i = (heapSize / 2) - 1; i >= 0; i--) {
        MinHeapify(Q,i,heapSize);
    }
}

// 2, 4, 3, 9, 5, 7, 6.

// 2  -----  3 - 6                                         # 2
//  \         \
//   4 - 5     7
//     \
//      9


// MPQ -> minimum priority queue
int main() {
    int Q[100]; // El tamaño maximo que vamos a tener será 100 elementos
    int size = 0, op;
    do
    {
        printf("\n\n0. Salir\n1. Mostrar\n2. Insertar\n3. Extraer minimo\n4. Obtener minimo\n/: ");
        scanf("%d",&op);
        switch (op)
        {
        case 0:
            break;
        case 1:
            mostrar(Q,size);
            break;
        case 2:
            int key;
            printf("\nIngrese el valor a insertar: ");
            scanf("%d",&key);
            MPQ_insert(Q,key,&size);
            break;
        case 3:
            if (size > 0) {    // <- Revision extra hecha por el profe.
                int key = MPQ_extract(Q,&size);
                printf("Elemento extraido: %d",key);
            } else {
                printf("Sin elementos!");
            }
            break;
        case 4:
            if (size == 0) {
                printf("\nNo hay valores.\n");
                break;
            }
            printf("\nMinimo: %d\n",MPQ_minimum(Q));
            break;
        }
    } while (op);
    
    return 0;
}