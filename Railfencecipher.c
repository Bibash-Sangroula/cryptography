#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt using Rail Fence Cipher
void encrypt(char *plaintext, int rails) {
    int len = strlen(plaintext);
    char rail[rails][len];
    
    // Initialize the rail matrix with 'nul'
        for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\0';
    
    // Fill the rail matrix in a zigzag pattern
    int row = 0, direction = 1;
    for (int i = 0; i < len; i++) {
        rail[row][i] = plaintext[i];
        if (row == 0)
            direction = 1;
        else if (row == rails - 1)
            direction = -1;
        row += direction;
    }
    
    // Read the matrix row-wise to get the ciphertext
    printf("Encrypted text: ");
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\0')
                printf("%c", rail[i][j]);
    printf("\n");
}

// Function to decrypt Rail Fence Cipher
void decrypt(char *ciphertext, int rails) {
    int len = strlen(ciphertext);
    char rail[rails][len];
    
    // Initialize the rail matrix with '*'
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '*';
    
    // Mark positions in a zigzag pattern
    int row = 0, direction = 1;
    for (int i = 0; i < len; i++) {
        rail[row][i] = 'X';
        if (row == 0)
            direction = 1;
        else if (row == rails - 1)
            direction = -1;
        row += direction;
    }
    
    // Fill the marked positions with ciphertext characters
    int index = 0;
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] == 'X' && index < len)
                rail[i][j] = ciphertext[index++];
    
    // Read the matrix in a zigzag pattern to reconstruct plaintext
    row = 0, direction = 1;
    printf("Decrypted text: ");
    for (int i = 0; i < len; i++) {
        printf("%c", rail[row][i]);
        if (row == 0)
            direction = 1;
        else if (row == rails - 1)
            direction = -1;
        row += direction;
    }
    printf("\n");
}

int main() {
    char plaintext[100], ciphertext[100];
    int rails;
    
    printf("Enter number of rails: ");
    scanf("%d", &rails);
    getchar(); // Consume newline character
    
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;
    
    encrypt(plaintext, rails);
    
    printf("Enter ciphertext to decrypt: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = 0;
    
    decrypt(ciphertext, rails);
    
    return 0;
}

