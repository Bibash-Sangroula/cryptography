//Verify if the given two numbers are relatively prime or not .......

#include <stdio.h>

// Function to compute GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    
    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // Compute GCD
    int result = gcd(num1, num2);

    // Check if numbers are relatively prime
    if (result == 1)
        printf("%d and %d are relatively prime (coprime).\n", num1, num2);
    else
        printf("%d and %d are not relatively prime (GCD = %d).\n", num1, num2, result);
    
    return 0;
}

