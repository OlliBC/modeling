#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <math.h>
#include <algorithm>

using namespace std;
double normal_rand_value() {
    double a = 0, b = 1;
    return (double) rand() / (double) RAND_MAX * (b - a) + a;
}

double coordinate(int sigma) {
    double x = 0;
    for (int i = 0; i < 12; ++i) {
        x += normal_rand_value();
    }
    return sigma * (x - 6);
}

int main() {

    srand((unsigned int) time(NULL));

    int S = 10;
    vector<pair<double, double>> points;

    for (int i = 0; i < 60; ++i) {
        pair<double, double> temp;
        temp.first = coordinate(S);
        temp.second = coordinate(S);

        points.push_back(temp);
    }

    double area = 0;

    for (int i = 0; i < points.size(); ++i) {
        if (pow(points[i].first, 2) + pow(points[i].second, 2) <= 1) {
            double temp = _Pi * (pow(points[i].first, 2) + pow(points[i].second, 2));
            if (area < temp)
                area = temp;
        }
    }

    if (area == 0){
        cout << "NONE";
    } else {
        cout << area;
    }
    return 0;
}