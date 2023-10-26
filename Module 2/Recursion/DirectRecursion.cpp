/* The Fibonacci sequence is a series of numbers in which each number 
 *is the sum of the two preceding ones, usually starting with 0 and 1.
 *The sequence begins as follows: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 */
 
#include <iostream>
using namespace std;

// Recursive function to calculate the Fibonacci sequence
int fibonacciRecursive(int n) {
    // Base cases
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    // Recursive case
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int num = 10;  // Find the 10th Fibonacci number
    int result = fibonacciRecursive(num);
    cout << "The " << num << "-th Fibonacci number is: " << result << endl;
    return 0;
}
/*
Explanation:
Base Cases:
If n is 0, the function returns 0.
If n is 1, the function returns 1.
These base cases handle the first two numbers in the Fibonacci sequence 
and ensure that the recursion eventually terminates.
Recursive Case:
For n ≥ 2, the function returns the sum of the two preceding Fibonacci numbers. This is calculated by making recursive calls to fibonacciRecursive(n - 1) 
and fibonacciRecursive(n - 2).

Main Function:
The main function calls fibonacciNonTailRecursive with num set to 10. 
This computes the 10th Fibonacci number and stores it in result.
*/