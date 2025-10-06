#include <stdio.h>
#include <math.h>
#define PI 3.141592
#define epsilon 0.000001

double solver(double R, double r, double h);
double Bisection(double R, double r, double h, double low_h, double high_h, double volume);
double CupVolume(double R, double r, double h);

int main() {
    int totalCases, idCases;
    double r, R, h;

    scanf("%d",&totalCases);
    for (idCases = 1; idCases <= totalCases; idCases++) {
        scanf("%lf %lf %lf", &r, &R, &h);
        printf("%lf\n", solver(R, r, h));
    }

    return 0;
}

double solver(double R, double r, double h) {
    return Bisection(R, r, h, 0.0, h, CupVolume(R, r, h) / 2.0);
}

double Bisection(double R, double r, double h, double low_h, double high_h, double volume) {
    double delta_R, mid_h_volume, mid_h = (low_h + high_h) / 2.0;
    delta_R = mid_h * ((R - r) / h);
    mid_h_volume = CupVolume(r + delta_R, r, mid_h);
    if (fabs(mid_h_volume - volume) < epsilon) {
        return mid_h;
    } else {
        if (mid_h_volume > volume) {
            return Bisection(R, r, h, low_h, mid_h, volume);
        } else {
            return Bisection(R, r, h, mid_h, high_h, volume);
        }
    }
}

double CupVolume(double R, double r, double h) {
    double volume;
    volume = (PI * h * (R*R + r*r + R*r)) / 3.0;
    return volume;
}