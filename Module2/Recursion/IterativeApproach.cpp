#include <iostream>
using namespace std;

// Iterative function to calculate the Fibonacci sequence
int fibonacciIterative(int n) {
    // Handle base cases
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // Initialize variables for iteration
    int a = 0, b = 1, c;

    // Iterative calculation
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main() {
    int num = 10;  // Find the 10th Fibonacci number
    int result = fibonacciIterative(num);
    cout << "The " << num << "-th Fibonacci number is: " << result << endl;
    return 0;
}

/* Explanation
* Base Cases:
* If n is 0, the function immediately returns 0.
* If n is 1, the function immediately returns 1.
* These handle the first two numbers in the Fibonacci sequence.
* 
* Initialization:
* Initialize three integers a, b, and c to store the two most recent Fibonacci * numbers and their sum, respectively. Start with a = 0 and b = 1.
* 
* Iterative Calculation:
* A for loop iterates from 2 to n. In each iteration, c is calculated 
* as a+b, and then a and b are updated for the next iteration.
* 
* Result:
* After the loop, c will contain the n-th Fibonacci number, 
* which is then returned.
* 
* Main Function:
* The main function calls fibonacciIterative with num set to 10 to find
* the 10th Fibonacci number and stores it in result.
*/