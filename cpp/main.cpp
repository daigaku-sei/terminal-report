#include <iostream>
#include <gsl/gsl_sf_ellint.h>

double calculate_period(double phi0, double l, double g) {
    double k = std::sin(phi0 / 2) * std::sin(phi0 / 2);
    double K = gsl_sf_ellint_Kcomp(k, GSL_PREC_DOUBLE);
    double T = 4 * std::sqrt(l / g) * K;
    return T;
}

int main() {
    double phi0 = 1.0;
    double l = 2.0;
    double g = 9.8;

    double T = calculate_period(phi0, l, g);
    std::cout << "T = " << T << std::endl;

    return 0;
}
