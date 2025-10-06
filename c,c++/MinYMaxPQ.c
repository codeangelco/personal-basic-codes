#include <stdio.h>
#include <math.h>

int parent(int id) {
    return (id - 1) / 2;
}

int left(int id) {
    return (id * 2) + 1;
}

int right(int id) {
    return (id * 2) + 2;
}

void exchange(int heap[], int id_1, int id_2) {
    int temp = heap[id_1];
    heap[id_1] = heap[id_2];
    heap[id_2] = temp;
}

void MinHeapify(int heap[], int id, int heapSize) {
    int least, l = left(id), r = right(id);
    if (l < heapSize && heap[l] < heap[id]) {
        least = l;
    } else {
        least = id;
    }
    if (r < heapSize && heap[r] < heap[least]) {
        least = r;
    }
    if (least != id) {
        exchange(heap, id, least);
        MinHeapify(heap, least, heapSize);
    }
}

int MinPQ_minimum(int heap[]) {
    return heap[0];
}

int MinPQ_extract(int heap[], int *heapSize) {
    int min = -__INT32_MAX__;
    if (*heapSize < 1) {
        puts("ERROR: Heap underflow.");
    } else {
        min = heap[0];
        heap[0] = heap[*heapSize - 1];
        (*heapSize)--;
        MinHeapify(heap, 0, *heapSize);
    }
    return min;
}

void MinPQ_decreaseKey(int heap[], int id, int key) {
    if (key > heap[id]) {
        puts("ERROR: The new key is larger than the current type of key.");
    } else {
        heap[id] = key;
        while (id > 0 && heap[id] < heap[parent(id)]) {
            exchange(heap, id, parent(id));
            id = parent(id);
        }
    }
}

void MinPQ_insert(int heap[], int key, int *heapSize) {
    (*heapSize)++;
    heap[*heapSize - 1] = __INT32_MAX__;
    MinPQ_decreaseKey(heap, *heapSize - 1, key);
}

int MaxPQ_maximum(int heap[]) {
    return -(MinPQ_minimum(heap));
}

int MaxPQ_extract(int heap[], int *heapSize) {
    return -(MinPQ_extract(heap, heapSize));
}

void MaxPQ_insert(int heap[], int key, int *heapSize) {
    MinPQ_insert(heap, -key, heapSize);
}