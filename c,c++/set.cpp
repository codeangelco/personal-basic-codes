#include <iostream>
#include <set>

int main() {
    std::set<int> sett;
    // Insertar elementos
    sett.insert(5);      // O(log n)
    sett.insert(2);      // O(log n)
    sett.insert(8);      // O(log n)
    sett.insert(5);      // O(log n), no se repite

    // Mostrar elementos (ordenados)
    std::cout << "Elementos del set: ";
    for (int x : sett) { // O(n)
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Buscar un elemento
    if (sett.find(2) != sett.end()) { // O(log n)
        std::cout << "2 está en el set" << std::endl;
    }

    // Eliminar un elemento
    sett.erase(5); // O(log n)

    // Mostrar elementos después de borrar
    std::cout << "Después de borrar 5: ";
    for (int x : sett) { // O(n)
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Comprobar si está vacío
    if (sett.empty()) { // O(1)
        std::cout << "El set está vacío" << std::endl;
    } else {
        std::cout << "El set NO está vacío" << std::endl;
    }

    // Tamaño del set
    std::cout << "Tamaño del set: " << sett.size() << std::endl; // O(1)

    // Limpiar el set
    sett.clear(); // O(n)
    std::cout << "Después de clear(), tamaño: " << sett.size() << std::endl; // O(1)

    // Insertar varios elementos usando insert con rango
    int arr[] = {10, 20, 30};
    sett.insert(arr, arr + 3); // O(k * log n), k = elementos a insertar

    // Usar count (devuelve 1 si existe, 0 si no)
    std::cout << "¿20 está en el set? " << (sett.count(20) ? "Sí" : "No") << std::endl; // O(log n)

    // Usar lower_bound y upper_bound
    auto it1 = sett.lower_bound(11); // O(log n), primer elemento >= 15
    if (it1 != sett.end())
        std::cout << "lower_bound(10): " << *it1 << std::endl;

    auto it2 = sett.upper_bound(11); // O(log n), primer elemento > 20
    if (it2 != sett.end())
        std::cout << "upper_bound(10): " << *it2 << std::endl;

    // Usar equal_range (devuelve par de iteradores)
    auto range = sett.equal_range(20); // O(log n)
    std::cout << "equal_range(20): ";
    for (auto it = range.first; it != range.second; ++it) // O(1)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Usar swap
    std::set<int> otro_set = {100, 200};
    sett.swap(otro_set); // O(1)
    std::cout << "Después de swap, sett contiene: ";
    for (int x : sett) std::cout << x << " "; // O(n)
    std::cout << std::endl;
    

    return 0;
}