#include <iostream>
using namespace std;

int main() {
    cout << "Hola mundo!" << endl;

    div_t resultado = div(4,2);
    cout << "Cociente: " << resultado.quot << " | Residuo: " << resultado.rem << endl;


    cout << "Chao mundo!" << endl;
    return 0;
}