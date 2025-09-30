#include <iostream>
using namespace std;

int main() {
    clog << "Conexion clogs\n";
    cerr << "Resultado final: 42\n";   // lo que ve el usuario
    clog << "Iteracion 1 completada\n"; // lo que ve el programador
    // cerr << "Error: división por cero\n"; // error crítico
    clog << "Iteracion 2 completada\n";
    clog << "Iteracion 3 completada\n";
    return 0;
}

