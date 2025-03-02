#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the text using Polyalphabetic Cipher
void encrypt(char text[], char key[]) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    char encryptedText[100];
    
    for (int i = 0, j = 0; i < textLen; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            char shift = tolower(key[j % keyLen]) - 'a'; // Normalize key character to a shift value
            encryptedText[i] = (ch - base + shift) % 26 + base;
            j++; // Increment key index only for alphabetic characters
        } else {
            encryptedText[i] = ch; // Non-alphabet characters remain unchanged
        }
    }
    encryptedText[textLen] = '\0'; // Null-terminate the string
    printf("Encrypted text: %s\n", encryptedText);
}

// Function to decrypt the text using Polyalphabetic Cipher
void decrypt(char text[], char key[]) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    char decryptedText[100];
    
    for (int i = 0, j = 0; i < textLen; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            char shift = tolower(key[j % keyLen]) - 'a'; // Normalize key character to a shift value
            decryptedText[i] = (ch - base - shift + 26) % 26 + base;
            j++; // Increment key index only for alphabetic characters
        } else {
            decryptedText[i] = ch; // Non-alphabet characters remain unchanged
        }
    }
    decryptedText[textLen] = '\0'; // Null-terminate the string
    printf("Decrypted text: %s\n", decryptedText);
}

int main() {
    char text[100], key[100];
    int choice;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character from input

    printf("Enter the keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline character from input

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\nYour choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(text, key);
    } else if (choice == 2) {
        decrypt(text, key);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

