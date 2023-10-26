#include <iostream>
using namespace std;

void printEven(int n);  // Forward declaration

// Function to print odd numbers
void printOdd(int n) {
    if (n > 0) {
        cout << "Odd: " << n << endl;
        printEven(n - 1);  // Call printEven
    }
}

// Function to print even numbers
void printEven(int n) {
    if (n > 0) {
        cout << "Even: " << n << endl;
        printOdd(n - 1);  // Call printOdd
    }
}

int main() {
    printOdd(10);  // Start with printOdd function
    return 0;
}
