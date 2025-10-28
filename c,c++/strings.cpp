#include <iostream>
#include <string>
#include <algorithm>  // para std::erase
// #include <ranges>     // para std::ranges::transform
// #include <cctype>     // para ::toupper y ::tolower
// using namespace std;

inline void toLowerCase(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}
inline void toUpperCase(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

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

    toUpperCase(full_name);

    std::cout << "Bienvenido " << full_name << "!" << std::endl;
}



void appendThings() {
    std::string full_name;

    std::cout << "Ingresa tu nombre completo: ";
    getline(std::cin, full_name);

    

    std::string correo = full_name + "@gmail.com";
    toLowerCase(correo);
    std::erase_if(correo, [](char a) { return !(a != 'a' && a != 'e'); });
    // erase(correo, 'a');
    // erase(correo, 'i');


    
    std::cout << "Tu correo es: " << correo << std::endl;


}

void buscarAlgo() {
    std::string full_text;

    std::cout << "Ingresa el texto completo:" << std::endl;
    getline(std::cin, full_text);

    
}


int main() {
    ingresarNombre();

    appendThings();

    buscarAlgo();

    return 0;
}