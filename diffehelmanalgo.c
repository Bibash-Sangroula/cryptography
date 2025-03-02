//Implementation of Diffie-Helmann key exchange ........
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
    long long P, G, private_key_A, private_key_B, public_key_A, public_key_B, shared_secret_A, shared_secret_B;

    // Choosing a prime number P and a primitive root G
    printf("Enter a prime number P: ");
    scanf("%lld", &P);
    printf("Enter a primitive root G: ");
    scanf("%lld", &G);

    // Selecting private keys for Alice and Bob
    printf("Enter Alice's private key: ");
    scanf("%lld", &private_key_A);
    printf("Enter Bob's private key: ");
    scanf("%lld", &private_key_B);

    // Calculating public keys
    public_key_A = power(G, private_key_A, P);
    public_key_B = power(G, private_key_B, P);

    printf("\nPublic Key of Alice: %lld", public_key_A);
    printf("\nPublic Key of Bob: %lld", public_key_B);

    // Calculating shared secret keys
    shared_secret_A = power(public_key_B, private_key_A, P);
    shared_secret_B = power(public_key_A, private_key_B, P);

    printf("\nShared Secret Key for Alice: %lld", shared_secret_A);
    printf("\nShared Secret Key for Bob: %lld", shared_secret_B);

    if (shared_secret_A == shared_secret_B) {
        printf("\nKey exchange successful! Shared secret key is: %lld\n", shared_secret_A);
    } else {
        printf("\nKey exchange failed!\n");
    }
    return 0;
}

