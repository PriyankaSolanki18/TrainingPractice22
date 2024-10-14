#include <string.h>
#include "functions.h"

void encrypt(char *input, char *output) {
    // Simple XOR encryption for demonstration
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ 0xFF; // XOR with a key
    }
    output[strlen(input)] = '\0';
}

void decrypt(char *input, char *output) {
    // Same XOR decryption
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ 0xFF; // XOR with the same key
    }
    output[strlen(input)] = '\0';
}

