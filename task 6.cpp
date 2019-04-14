#include <iostream>
#include <random>
#include <ctime>

using namespace std;

double RandomValue() {
    double a = 0.0, b = 1.0;
    return (double) rand() / (double) RAND_MAX * (b - a) + a;
}

int main() {
    srand((unsigned int) time(NULL));

    int H = 1000, count = 0;
    double lambda = 1, p = 0.001;

    for (int i = 0; i < 1000; ++i) {
        bool passed = true;
        double z = 0;
        while (z < H) {
            if (RandomValue() >= p) {
                z += log(RandomValue()) * (-1.0 / lambda);
            } else {
                passed = false;
                break;
            }
        }

        if (passed) {
            count++;
        }
    }

    cout << (double) count / 1000;

    return 0;
}