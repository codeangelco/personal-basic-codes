#include <iostream>

class IntHolder {
private:
    int* ptr;
public:

    IntHolder() : ptr(new int(0)) {}

    IntHolder(int value) : ptr(new int(value)) {
        std::cout << "reserved memory whit value: " << *ptr << " " << std::endl;
    };

    ~IntHolder() {
        delete ptr;
        std::cout << "Memory successfully deleted." << std::endl;
    };

    IntHolder operator=(const IntHolder& other) {
        if (this != &other) {
            *ptr = *(other.ptr);
        }
        return *this;
    }

    void new_set(int value) { *ptr = value; }
    int get() const { return *ptr; }
};

int main() {
    IntHolder entero_1;
    std::cout << entero_1.get() << std::endl; // <- Será 0.
    entero_1.new_set(10);
    std::cout << entero_1.get() << std::endl; // <- Será 10.
    IntHolder entero_2 = entero_1;
    std::cout << entero_2.get() << std::endl; // <- Será 10 tambien.

    return 0;
}