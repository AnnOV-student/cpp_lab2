#include <iostream>
#include <ctime>

double factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 2);
}


double t(double x) {
    double a = x, b = 1;
    for (int k = 1; k <= 10; ++k) {
        int n = 2 * k + 1;
        double d = 1;
        while (n > 0) {
            d *= x;
            --n;
        }
        a += d / factorial(2 * k + 1);
    }
    for (int k = 1; k <= 10; ++k) {
        int n = 2 * k;
        double d = 1;
        while (n > 0) {
            d *= x;
            --n;
        }
        b += d / factorial(2 * k);
    }
    return a / b;
}

int main() {
    double y;
    std::cout << "y= ";
    std::cin >> y;
    clock_t start = clock();
    std::cout << "Result: " << (7 * 0.24742 + 2 * t(y + 1)) / (6 - t(y * y - 1)) << std::endl;
    clock_t end = clock();
    std::cout << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

    return 0;
}