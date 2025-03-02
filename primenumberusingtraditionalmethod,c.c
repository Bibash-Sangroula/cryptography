//WAP in c to find the prime number using traditional method...
#include <stdio.h>

// Function to check if a number is prime using trial division
int isPrime(int n) {
    // Handle special cases
    if (n <= 1)
        return 0;  // Not prime
    if (n <= 3)
        return 1;  // 2 and 3 are prime

    // Eliminate even numbers and multiples of 3
    if (n % 2 == 0 || n % 3 == 0)
        return 0;

    // Check divisibility from 5 to sqrt(n), skipping even numbers
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }

    return 1;  // Prime
}

int main() {
    int num;

    // User input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check for primality
    if (isPrime(num))
        printf("%d is a Prime Number.\n", num);
    else
        printf("%d is NOT a Prime Number.\n", num);

    return 0;
}

