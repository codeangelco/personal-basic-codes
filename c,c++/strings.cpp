#include <iostream>
#include <string>
using namespace std;

void ingresarNombre() {
    std::string full_name;

    std::cout << "Ingresa tu nombre completo: ";
    getline(std::cin, full_name);

    if (full_name.empty()) {
        std::cerr << "No ingresaste un nombre!" << std::endl;
        exit(1);
    }

    if (full_name.length() > 40) {
        std::cerr << "Tu nombre no puede tener mas de 20 caracteres!" << std::endl;
        exit (1);
    }

    std::cout << "Bienvenido " << full_name << "!" << std::endl;
}

void appendThings() {
    std::string full_name;

    std::cout << "Ingresa tu nombre completo: ";
    getline(std::cin, full_name);

    

    std::string correo = full_name + "@gmail.com";
    erase(correo, ' ');




    
    uppercase(correo);

    std::cout << "Tu correo es: " << correo << std::endl;


}


int main() {
    ingresarNombre();

    appendThings();

    return 0;
}