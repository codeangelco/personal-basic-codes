#include <iostream>
// #include <mutex>
#include <thread>
using namespace std;
// Los hilos se pueden poner a hacer las mismas finciones, pero si calculan sobre la misma variable y la variable tiene valor compartido entre \
    llamados, entonces pueden afectar los hilos asincronicos; para ese problema, la solucion es utilizar mutex.

int contador = 0;
// mutex mx;

void incrementar() {
    for (int i = 0; i < 100000; i++) {
        // mx.lock();
        contador++; // varios hilos modifican la misma variable
        // mx.unlock();
    }
}

int main() {
    thread t1(incrementar);
    thread t2(incrementar);

    t1.join();
    t2.join();

    cerr << "Contador = " << contador << endl;
}

// int main() {
//     for (int i = 0; i < 10; i++)
//     {
//         cerr << "#" << i << " | ";
//         solver();
//         cerr << endl;
//     }
    

//     return 0;
// }
