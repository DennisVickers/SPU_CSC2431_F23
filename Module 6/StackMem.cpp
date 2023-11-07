#include <iostream>
using namespace std;

void functionB() {
    int b = 5; // b is a local variable, stored on the stack
    cout << "The value of b is: " << b << endl;
    // When functionB returns, b is automatically removed from the stack
}

void functionA() {
    int a = 10; // a is a local variable, stored on the stack
    functionB();
    // functionB has returned, its stack frame is gone
    cout << "The value of a is: " << a << endl;
    // When functionA returns, a is automatically removed from the stack
}

int main() {
    functionA();
    // When main returns, its stack frame is gone and the program ends
    return 0;
}