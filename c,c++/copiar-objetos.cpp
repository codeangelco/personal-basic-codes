#include <cassert>
#include <iostream>
using namespace std;

class Lista {
private:
    int* elementos;
    int capacidad;
    int cantidad;

public:
    Lista() : elementos(nullptr), capacidad(1), cantidad(0) {}

    Lista(int cap) : capacidad(cap), cantidad(0) {
        elementos = new int[capacidad];
    }

    Lista(const Lista& lista) {
        capacidad = lista.capacidad;
        cantidad = lista.cantidad;
        elementos = new int[capacidad];
        
        // Copiar todos los elementos
        for (int i = 0; i < cantidad; i++) {
            elementos[i] = lista.elementos[i];
        }
    }

    ~Lista() {
        if (elementos != nullptr) {
            delete[] elementos;
        }
        cout << "Lista eliminada." << endl;
    }

    int getCantidad() const {
        return cantidad;
    }

    int getCapacidad() const {
        return capacidad;
    }

    int getElemento(int indice) const {
        assert(indice >= 0 && indice < cantidad);
        return elementos[indice];
    }

    void setElemento(int indice, int valor) {
        assert(indice >= 0 && indice < cantidad);
        elementos[indice] = valor;
    }

    bool agregar(int valor) {
        if (cantidad < capacidad) {
            elementos[cantidad++] = valor;
            return true;
        }
        return false;
    }

    void copy(const Lista& lista) {
        if (this != &lista) {
            delete[] elementos;
            capacidad = lista.capacidad;
            cantidad = lista.cantidad;
            elementos = new int[capacidad];
            for (int i = 0; i < cantidad; i++) {
                elementos[i] = lista.elementos[i];
            }
        }
    }

    friend ostream& operator<<(ostream &os, Lista &lista) {
        os << "Lista: ";
        for (int i = 0; i < lista.cantidad; ++i) {
            os << lista.elementos[i] << (i < lista.cantidad - 1 ? ", " : ".");
        }
        return os;
    }

    Lista& operator=(const Lista& lista) {
        if (this != &lista) {
            delete[] elementos;
            capacidad = lista.capacidad;
            cantidad = lista.cantidad;
            elementos = new int[capacidad];
            for (int i = 0; i < cantidad; i++) {
                elementos[i] = lista.elementos[i];
            }
        }
        return *this;
    }
};

int main() {
    Lista lista1(5);
    lista1.agregar(1);
    lista1.agregar(2);
    lista1.agregar(3);
    lista1.agregar(4);
    lista1.agregar(5);
    cout << lista1 << endl;
    Lista lista2 = lista1;
    cout << lista2 << endl;
    Lista lista3(lista1);
    cout << lista3 << endl;
    Lista lista4;
    lista4.copy(lista1);
    cout << lista4 << endl;

    return 0;
}
