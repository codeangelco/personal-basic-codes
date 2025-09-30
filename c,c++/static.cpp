#include <iostream>
/*                         ### IMPLEMENTACION STATIC EN CLASES
class Bitcoins {
    private:
        static unsigned int cantidad_en_sirculacion;
        static unsigned int valor_en_mercado;
    public:
        Bitcoins() {
            cantidad_en_sirculacion++;
        }

        Bitcoins(unsigned int nuevo_valor) {
            cantidad_en_sirculacion++;
            valor_en_mercado = nuevo_valor;
        }

        ~Bitcoins() {
            cantidad_en_sirculacion--;
        }

        unsigned int valorActual() const { return valor_en_mercado; }
        unsigned int cantidadActual() const { return cantidad_en_sirculacion; }
        void establecerNuevoValor(unsigned int &nuevo_valor) { valor_en_mercado = nuevo_valor; }
};

unsigned int Bitcoins::cantidad_en_sirculacion = 0;
unsigned int Bitcoins::valor_en_mercado = 0;
*/

/*                                                          ### IMPLEMENTACION STATIC EN FUNCIONES
void maximoValorRecibido(long long nuevo_valor) {
    static long long valor_maximo = -9223372036854775807;
    if (valor_maximo < nuevo_valor) {
        valor_maximo = nuevo_valor;
    }
    std::cout << "El máximo valor recibido es: " << valor_maximo << std::endl;
}
*/

int main() {
    return 0;
}