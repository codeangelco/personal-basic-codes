#include <bits/stdc++.h>
using namespace std;

/* En una línea de producción, cada pieza tiene una calificación de calidad.
Se debe encontrar el mayor umbral H posible tal que exista al menos una ventana contigua de longitud L
que contenga K o más piezas con calidad ≥ H.

Entrada: N, L, K, seguido de N calificaciones.
Salida: El máximo H que cumple la condición. */

int main() {
    int n, l, k, temp;
    cin >> n >> l >> k;

    vector<int> piezas;
    piezas.reserve(n);
    while (n--) {
        cin >> temp;
        piezas.push_back(temp);
    }

    int min_h = *min_element(piezas.begin(), piezas.end());
    int max_h = *max_element(piezas.begin(), piezas.end());

    vector<int> h_vec;
    int length_h = max_h - min_h + 1;
    int best = 0, curr = 0;
    h_vec.reserve(length_h);
    deque<int> ventana_l, ventana_k;
    for (int i = 0; i < length_h; i++) {
        if (!ventana_l.empty() && ventana_l.front() <= i - l) {
            ventana_l.pop_front();
        }
        ventana_l.push_back(i);

        if (ventana_l.size() == l) {
            ventana_k.clear();
            for (int j = 0; j < l; j++) {
                if (ventana_k.size() >= k) ventana_k.pop_front();
                ventana_k.push_back(piezas.at(ventana_l.at(j)));

                if(ventana_k.size() == k) {
                    curr = *min_element(ventana_k.begin(),ventana_k.end());
                    if (curr > best) best = curr;
                }
            }
        }
    }
    cerr << best << "\n";

    return 0;
}
