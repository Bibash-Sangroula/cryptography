//WAP to find the totient of a number ....
#include <stdio.h>

// Function to compute Euler's Totient Function (phi(n))
int phi(int n) {
    int result = n;  // Initialize result as n

    // Check for every prime factor of n
    for (int p = 2; p * p <= n; p++) {
        // Check if p is a factor of n
        if (n % p == 0) {
            // If p is a prime factor, divide n by p completely
            while (n % p == 0)
                n /= p;
            // Apply the formula: phi(n) = n * (1 - 1/p)
            result -= result / p;
        }
    }

    // If n is a prime number greater than 1, apply the formula
    if (n > 1)
        result -= result / n;

    return result;
}

int main() {
    int num;

    // User input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Compute and print the totient function
    printf("Euler's Totient Function (phi) of %d is: %d\n", num, phi(num));

    return 0;
}

