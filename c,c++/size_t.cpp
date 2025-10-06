#include <iostream>

void print_arry(int array[], size_t size) {
    for (int i = 0; i < size; i++) {
        std::cerr << array[i] << (i < size - 1 ? " " : "\n");
    }
}

void read_array(int array[], size_t size) {
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
}

int main() {
    size_t n;
    std::cin >> n;
    int arr[n];
    read_array(arr, n);
    print_arry(arr, n);

    return 0;
}