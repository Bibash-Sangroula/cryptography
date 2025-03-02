#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to create the Playfair cipher key matrix
void createMatrix(char key[], char matrix[SIZE][SIZE]) {
    int alpha[26] = {0};
    alpha['j' - 'a'] = 1; // Treat 'j' as 'i'

    int keyLen = strlen(key), k = 0;

    // Fill the matrix with the keyword
    for (int i = 0; i < keyLen; i++) {
        char ch = tolower(key[i]);
        if (isalpha(ch) && !alpha[ch - 'a']) {
            alpha[ch - 'a'] = 1;
            matrix[k / SIZE][k % SIZE] = ch;
            k++;
        }
    }

    // Fill the rest of the matrix with remaining letters
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (!alpha[ch - 'a']) {
            matrix[k / SIZE][k % SIZE] = ch;
            k++;
        }
        if (ch == 'i') ch++; // Skip 'j'
    }
}

// Function to display the cipher matrix
void displayMatrix(char matrix[SIZE][SIZE]) {
    printf("Playfair Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find the position of a character in the matrix
void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to prepare the plaintext (convert to pairs)
void prepareText(char text[]) {
    int len = strlen(text), k = 0;
    char prepared[100];

    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            prepared[k++] = tolower(text[i]);
            if (k > 1 && prepared[k - 1] == prepared[k - 2]) {
                prepared[k - 1] = 'x'; // Insert 'x' if repeated character in a pair
                i--;                  // Check the same character again
            }
        }
    }

    if (k % 2 != 0) prepared[k++] = 'x'; // Append 'x' if odd length

    prepared[k] = '\0';
    strcpy(text, prepared);
}

// Function to encrypt/decrypt text using Playfair Cipher
void processText(char text[], char matrix[SIZE][SIZE], int encrypt) {
    int len = strlen(text);
    for (int i = 0; i < len; i += 2) {
        int r1, c1, r2, c2;
        findPosition(matrix, text[i], &r1, &c1);
        findPosition(matrix, text[i + 1], &r2, &c2);

        if (r1 == r2) { // Same row
            text[i] = matrix[r1][(c1 + encrypt + SIZE) % SIZE];
            text[i + 1] = matrix[r2][(c2 + encrypt + SIZE) % SIZE];
        } else if (c1 == c2) { // Same column
            text[i] = matrix[(r1 + encrypt + SIZE) % SIZE][c1];
            text[i + 1] = matrix[(r2 + encrypt + SIZE) % SIZE][c2];
        } else { // Rectangle swap
            text[i] = matrix[r1][c2];
            text[i + 1] = matrix[r2][c1];
        }
    }
}

int main() {
    char key[100], text[100];
    char matrix[SIZE][SIZE];
    int choice;

    printf("Enter the keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    createMatrix(key, matrix);
    displayMatrix(matrix);

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    prepareText(text);
    printf("Prepared text: %s\n", text);

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\nYour choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        processText(text, matrix, 1);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        processText(text, matrix, -1);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

