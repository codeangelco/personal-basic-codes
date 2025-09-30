#include <iostream>
using namespace std;

template <typename T> class vector{
    private:
        size_t size;
        T arr[];
    public:
        vector(size_t sz) {
            size = sz;
            arr[size];
            for (int i = 0; i < size; i++) {
                arr[i] = 0;
            }
        }

        T operator[](unsigned int id) const { return arr[id]; }
        // T* operator[](unsigned int id) { return &arr[id]; }
        // T operator=(int value) {}
};






int main() {
    vector<int> social(10);
    std::cerr << social[0] << std::endl;
    social[0] = 10;
    std::cerr << social[0] << std::endl;

    return 0;
}
