#include <iostream>
using namespace std;

template <typename T>
T findMax(T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    cout << "Max int: " << findMax(intArr, 5) << endl;

    double doubleArr[] = {1.1, 2.2, 3.3};
    cout << "Max double: " << findMax(doubleArr, 3) << endl;

    return 0;
}
