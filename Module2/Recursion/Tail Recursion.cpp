#include <iostream>
using namespace std;

// Tail-recursive function to calculate Fibonacci sequence
int fibonacciTailRecursive(int n, int a = 0, int b = 1) {
    // Base case
    if (n == 0) {
        return a;
    }

    // Tail-recursive case
    return fibonacciTailRecursive(n - 1, b, a + b);
}

int main() {
    int num = 10;
    int result = fibonacciTailRecursive(num);
    cout << "The " << num << "-th Fibonacci number is: " << result << endl;
    return 0;
}

/*
 * Function Signature: The first parameter, n, is the position in the
 * Fibonacci sequence we're interested in. The second and third 
 * parameters, a and b, are initialized to 0 and 1 by default. They 
 * are used to hold the two most recent Fibonacci numbers in the sequence.
 *
 * Base Case: If n is 0, the function returns a. This serves as our 
 * base case.
 *
 * Tail-Recursive Case: In this case, we make a recursive call to
 * fibonacciTailRecursive, decrementing n by 1 and updating a and b 
 * to be b and a + b, respectively. Notice that this recursive call 
 * is the last operation in the function, making it a 
 * tail-recursive function.
 *
 *Immediate Return: The function returns the result of the recursive 
 * call directly, adhering to the characteristics of tail recursion.
 */
