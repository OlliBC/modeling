#include <iostream>
#include <random>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
    random_device rd;
    mt19937 mersenne(rd());

    long long int N = (100 + mersenne()) / 100;
    if (N < 0)
        N *= -1;

    double x = N * 0.05;
    x = round(x);

    double a = x;
    int t = 0;
    double h = 0.00001, k = 0.01;

    vector<double> array;
    while (x < 0.95 * N){
        array.push_back(x);
        x += h * k * a * (N - x);
        t += 1;
    }

    cout << "People: "<< N << endl << "Moment: " << t;
    for (int i = 0; i < array.size(); ++i) {
        if (i % 40 == 0){
            cout << endl;
        } else {
            cout << array[i] << " ";
        }
    }

    return 0;
}