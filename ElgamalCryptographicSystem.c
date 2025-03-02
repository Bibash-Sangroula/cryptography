//Implement Elgamal Cryptographic System.....
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

int main() {
    long long p, g, x, y, k, m, c1, c2, decrypted;

    // Choosing a prime number p and a primitive root g
    printf("Enter a prime number (p): ");
    scanf("%lld", &p);
    printf("Enter a primitive root (g): ");
    scanf("%lld", &g);

    // Selecting private key x (1 < x < p)
    printf("Enter private key (x): ");
    scanf("%lld", &x);

    // Compute public key y = g^x mod p
    y = power(g, x, p);
    printf("Public Key (y, g, p): (%lld, %lld, %lld)\n", y, g, p);

    // Encryption
    printf("Enter message to encrypt (m): ");
    scanf("%lld", &m);

    // Choosing random key k (1 < k < p-1)
    printf("Enter random key (k): ");
    scanf("%lld", &k);

    c1 = power(g, k, p);
    c2 = (m * power(y, k, p)) % p;
    printf("Encrypted message: (c1, c2) = (%lld, %lld)\n", c1, c2);

    // Decryption
    long long k_inv = power(c1, p-1-x, p);
    decrypted = (c2 * k_inv) % p;
    printf("Decrypted message: %lld\n", decrypted);

    return 0;
}

