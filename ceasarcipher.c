//WAP to implement Ceasar Cipher......

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the text using Caesar Cipher
void encrypt(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            text[i] = (ch - base + shift) % 26 + base;
        }
    }
}

// Function to decrypt the text using Caesar Cipher
void decrypt(char text[], int shift) {
    encrypt(text, 26 - (shift % 26)); // Decrypt by reversing the shift
}

int main() {
    char text[100];
    int shift, choice;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character from input

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\nYour choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(text, shift);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        decrypt(text, shift);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

