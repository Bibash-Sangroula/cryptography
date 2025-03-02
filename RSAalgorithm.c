//WAP to implementRSA Algorithm.............
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute (base^exp) % mod
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to compute GCD
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find modular inverse using Extended Euclidean Algorithm
long long modInverse(long long e, long long phi) {
    long long m0 = phi, t, q;
    long long x0 = 0, x1 = 1;
    if (phi == 1)
        return 0;
    while (e > 1) {
        q = e / phi;
        t = phi;
        phi = e % phi, e = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

int main() {
    long long p, q, n, phi, e, d, message, encrypted, decrypted;

    // Choosing two prime numbers
    printf("Enter first prime number (p): ");
    scanf("%lld", &p);
    printf("Enter second prime number (q): ");
    scanf("%lld", &q);

    // Compute n and phi(n)
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Choosing e such that 1 < e < phi and gcd(e, phi) = 1
    do {
        printf("Enter public exponent (e) such that 1 < e < %lld and gcd(e, %lld) = 1: ", phi, phi);
        scanf("%lld", &e);
    } while (gcd(e, phi) != 1);

    // Compute private key d
    d = modInverse(e, phi);

    printf("Public Key: (%lld, %lld)\n", e, n);
    printf("Private Key: (%lld, %lld)\n", d, n);

    // Encryption
    printf("Enter message to encrypt (integer): ");
    scanf("%lld", &message);
    encrypted = power(message, e, n);
    printf("Encrypted message: %lld\n", encrypted);

    // Decryption
    decrypted = power(encrypted, d, n);
    printf("Decrypted message: %lld\n", decrypted);

    return 0;
}

