//WAP in c to Implement Miller’s Algorithm for testing Primality......
#include <stdio.h>
#include <stdlib.h>

// Function to perform modular exponentiation (a^b % mod)
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)  // If exp is odd, multiply base with result
            result = (result * base) % mod;
        exp = exp >> 1;     // Divide exp by 2
        base = (base * base) % mod; // Square the base
    }

    return result;
}

// Function to perform the Miller-Rabin Test
int miller_test(long long d, long long n) {
    long long a = 2 + rand() % (n - 4); // Choose a random base in range [2, n-2]
    long long x = power_mod(a, d, n); // Compute a^d % n

    if (x == 1 || x == n - 1)
        return 1; // Probably prime

    // Keep squaring x while d does not become n-1
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1) return 0; // Composite
        if (x == n - 1) return 1; // Probably prime
    }

    return 0; // Composite
}

// Miller-Rabin Primality Test
int is_prime(long long n, int k) {
    if (n <= 1 || n == 4) return 0;
    if (n <= 3) return 1;

    // Express n-1 as 2^s * d
    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Perform k trials
    for (int i = 0; i < k; i++) {
        if (!miller_test(d, n))
            return 0; // Composite
    }

    return 1; // Probably prime
}

int main() {
    long long num;
    int k = 5; // Number of iterations for accuracy

    printf("Enter a number to check for primality: ");
    scanf("%lld", &num);

    if (is_prime(num, k))
        printf("%lld is a Prime Number.\n", num);
    else
        printf("%lld is NOT a Prime Number.\n", num);

    return 0;
}

