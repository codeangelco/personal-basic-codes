#include <iostream> // Entrada/salida estándar.
#include <array>    // Arreglos de tamaño fijo en C++.

// Diferencias entre los arreglos:
// numeros_1: No inicializado, valores indeterminados.
// numeros_2: Inicializado en 0.
// numeros_3: Inicializado con valores específicos.
// int main() {
//     std::array<int, 5> numeros_1;           // Sin inicializar.
//     std::array<int, 5> numeros_2 {};        // Todos los elementos en 0.
//     std::array<int, 5> numeros_3 {1, 2, 3, 4, 5}; // Valores definidos.

//     std::cout << "Elementos de numeros_1: ";
//     for (const auto& num : numeros_1) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "Elementos de numeros_2: ";
//     for (const auto& num : numeros_2) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "Elementos de numeros_3: ";
//     for (const auto& num : numeros_3) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     constexpr std::array<int, 5> arreglo {1, 2, 3, 4, 5}; // Arreglo no modificable.

//     return 0;
// }

int main()
{
    constexpr std::array<int, 5> prime{ 2, 3, 5, 7, 11 };

    std::cout << prime[3] << std::endl; // print the value of element with index 3 (7)
    // std::cout << prime[9]; // invalid index (undefined behavior)
    

    return 0;
}
