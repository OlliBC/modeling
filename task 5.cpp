#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <math.h>
#include <algorithm>

using namespace std;

double RandomValue() {
    double a = 0, b = 1;
    return (double) rand() / (double) RAND_MAX * (b - a) + a;
}

double GetNormalRandomValue(int sigma) {
    double x = 0;
    for (int i = 0; i < 12; ++i) {
        x += RandomValue();
    }
    return sigma * (x - 6);
}

int main() {
    srand((unsigned int) time(NULL));

    int S = 1;
    double deviantResult = 0;
    double minInDay = 1440;

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 7; ++j) {
            double firstClock = minInDay + GetNormalRandomValue(S);
            double secondClock = minInDay + GetNormalRandomValue(S);
            double thirdClock = minInDay + GetNormalRandomValue(S);
            double middle = (firstClock + secondClock + thirdClock) / 3;

            if (abs(middle - minInDay) > 2) {
                deviantResult++;
            }
        }
    }

    double result = deviantResult / 1000;
    cout << endl << result;

    return 0;
}