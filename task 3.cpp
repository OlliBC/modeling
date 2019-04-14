#include <iostream>
#include <random>
#include <ctime>
#include <cmath>

using namespace std;

int Random(int min, int max) {
    return min + rand() % (max - min);
}

int main() {

    srand((unsigned int)time(NULL));
    vector<double> array;

    for (int i = 0; i < 10; i++){
        double temp = 0;
        for (int j = 0; j < 500; ++j) {
            temp += Random(1, 7);
        }
        temp /= 500;
        array.push_back(temp);
    }

    for (int k = 0; k < array.size(); ++k) {
        cout << array[k] << " ";
    }

    return 0;
}