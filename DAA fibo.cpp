#include <iostream>
#include <vector>
using namespace std;

// Non-recursive (Iterative) Fibonacci
int fibonacciIterative(int n) {
    if (n <= 1) return n;

    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

// Recursive Fibonacci
int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int n;
    cout << "Enter the Fibonacci term to calculate: ";
    cin >> n;

    // Iterative calculation
    cout << "Iterative Fibonacci of " << n << " is: " << fibonacciIterative(n) << endl;

    // Recursive calculation
    cout << "Recursive Fibonacci of " << n << " is: " << fibonacciRecursive(n) << endl;

    return 0;
}