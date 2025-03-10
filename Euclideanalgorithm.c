//Implementation of Euclidean Algorithm in c .....

#include <stdio.h>

// Function to compute GCD using the Euclidean algorithm
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
    
    // Calculate and display GCD
    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
    
    return 0;
}

