#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;


double f(double x) {
    return x * x * sin(x);
}


double S4(double x) {
    double a0 = 0.197672;
    double a[] = {0.072827, -0.022262, -0.038390, -0.043865};
    double b[] = {-0.237249, -0.123859, -0.077809, -0.052223};

    double sum = a0 ;
    for (int k = 1; k <= 4; ++k) {
        sum += a[k - 1] * cos(2 * PI * k * x);
        sum += b[k - 1] * sin(2 * PI * k * x);
    }
    return sum;
}

int main() {
    int m = 16;
    double error = 0.0;

    for (int j = 0; j < m; ++j) {
        double xj = static_cast<double>(j) / m;
        double diff = f(xj) - S4(xj);
        error += diff * diff;
    }

    cout << "E(S4) = " << error << endl;
    return 0;
}

