#include <stdio.h>

// Function to find additive inverse modulo m
int additiveInverseMod(int a, int m) {
    return (m - (a % m)) % m;
}

int main() {
    int a, m;
    
    // Input values
    printf("Enter a number (a): ");
    scanf("%d", &a);
    
    printf("Enter modulus (m): ");
    scanf("%d", &m);

    // Compute and display the additive inverse
    int inverse = additiveInverseMod(a, m);
    printf("The additive inverse of %d modulo %d is: %d\n", a, m, inverse);
    
    return 0;
}

