#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int size;
    std::cout << "Ingrese el tamaño del vector: ";
    std::cin >> size;

    std::vector<int> vector(size);
    std::cout << "Ingrese los elementos del vector: ";
    for (auto &item : vector) {
        std::cin >> item;
    }

    std::sort(vector.begin(), vector.end());
    vector.erase(std::unique(vector.begin(), vector.end()), vector.end());
    std::cout << "Vector sin repetidos:" << std::endl;
    for (const auto &item : vector) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}