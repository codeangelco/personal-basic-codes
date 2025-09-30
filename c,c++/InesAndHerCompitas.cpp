#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, compartir, directo;
    cin >> n >> m;
    int p1[m], p2[m], p3[m], pi[m];

    int points1 = 0, points2 = 0, points3 = 0, pointsInes = 0, div = 0;
    for (int i = 0; i < m; i++) {
        cin >> compartir >> directo;
        cin >> p1[i] >> p2[i] >> p3[i];
        if (p1[i] == 1) div++;
        if (p2[i] == 1) div++;
        if (p3[i] == 1) div++;

        if (compartir/(div+1) < directo) pointsInes += directo;
        else {
            div++;
            pointsInes += compartir/div;
        }

        if (p1[i] == 1) points1 += compartir/div;
        else points1 += directo;
        if (p2[i] == 1) points2 += compartir/div;
        else points2 += directo;
        if (p3[i] == 1) points3 += compartir/div;
        else points3 += directo;
    }

    cerr << points1 << " " << points2 << " " << points3 << " " << pointsInes << endl;

    return 0;
}