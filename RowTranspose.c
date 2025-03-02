#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt using Row Transposition Cipher
void encrypt(char *plaintext, int key[], int key_length) {
    int len = strlen(plaintext);
    int rows = (len + key_length - 1) / key_length; // Calculate rows needed
    char matrix[rows][key_length];

    // Fill the matrix with plaintext characters
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key_length; j++) {
            if (k < len)
                matrix[i][j] = plaintext[k++];
            else
                matrix[i][j] = 'X'; // Padding with 'X' if needed
        }
    }

    // Print ciphertext column-wise according to key order
    printf("Encrypted text: ");
    for (int i = 0; i < key_length; i++) {
        int col = key[i] - 1;
        for (int j = 0; j < rows; j++) {
            printf("%c", matrix[j][col]);
        }
    }
    printf("\n");
}

// Function to decrypt Row Transposition Cipher
void decrypt(char *ciphertext, int key[], int key_length) {
    int len = strlen(ciphertext);
    int rows = (len + key_length - 1) / key_length;
    char matrix[rows][key_length];
    int k = 0;

    // Fill the matrix column-wise according to key order
    for (int i = 0; i < key_length; i++) {
        int col = key[i] - 1;
        for (int j = 0; j < rows; j++) {
            if (k < len)
                matrix[j][col] = ciphertext[k++];
        }
    }

    // Read the matrix row-wise to get plaintext
    printf("Decrypted text: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key_length; j++) {
            if (matrix[i][j] != 'X') // Avoid printing padding characters
                printf("%c", matrix[i][j]);
        }
    }
    printf("\n");
}

int main() {
    char plaintext[100], ciphertext[100];
    int key[] = {3, 1, 4, 2, 5}; // Key permutation (change as needed)
    int key_length = sizeof(key) / sizeof(key[0]);
    
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline character
    
    encrypt(plaintext, key, key_length);
    
    printf("Enter ciphertext to decrypt: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = 0; // Remove newline character
    
    decrypt(ciphertext, key, key_length);
    
    return 0;
}

