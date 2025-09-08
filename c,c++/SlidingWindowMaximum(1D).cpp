#include <bits/stdc++.h>
using namespace std;
/* Codigo el cual utiliza el algoritmo Sliding Window para sacar el numero mayor de un 
arreglo 1D que se encuentre dentro de la ventana */

int main() {
    int length_arr, k;

    cout << "Ingrese el tamaño del arreglo: ";
    cin >> length_arr;
    cout << "\nIngrese el valor de k: ";
    cin >> k;

    int arr[length_arr];

    cout << "\n\nVamos a rellenar el arreglo:\n";
    for (int i = 1; i <= length_arr; i++) {
        cout << "Elemento #" << i << ": ";
        cin >> arr[i-1];
    }

    deque<int> ventana, ans;
    for (int i = 0; i < length_arr; i++) {

        if (!ventana.empty() && ventana.front() <= i - k) ventana.pop_front();

        while (!ventana.empty() && arr[ventana.back()] <= arr[i]) ventana.pop_back();

        ventana.push_back(i);

        if (i >= k - 1) ans.push_back(arr[ventana.front()]);
        
    }

    cout << "\nArreglo principal:\n";
    for (int num : arr) cout << num << " | ";

    cout << "\n\nArreglo respuesta:\n";
    for (int num : ans) cout << num << " | ";
    

    return 0;
}