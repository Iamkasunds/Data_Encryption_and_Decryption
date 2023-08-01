#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void encrypt(char *message, int key) {
int i = 0;
char ch;

while (message[i] != '\0') {
    ch = message[i];

    if (ch >= 'A' && ch <= 'Z')
    message[i] = ((ch - 'A') + key) % 26 + 'A';
    else if (ch >= 'a' && ch <= 'z')
    message[i] = ((ch - 'a') + key) % 26 + 'a';
    i++;
    }
}

void decrypt(char *message, int key) {
    encrypt(message, -key);
}

int main() {
    FILE *messageFile, *encryptedFile, *keyFile;
    char message[1000];
    int key;
    char action;

    printf("Do you want to encrypt or decrypt (E/D)? ");
    scanf(" %c", &action);

    if (action == 'E' || action == 'e') {

        printf("Enter a message to encrypt: ");
        getchar(); // Clear the input buffer
        fgets(message, sizeof(message), stdin);

        message[strcspn(message, "\n")] = '\0';

        printf("Enter the encryption key (an integer): ");
        scanf("%d", &key);

        encrypt(message, key);

        messageFile = fopen("encrypted_message.txt", "w");
        if (messageFile == NULL) {
            printf("Error creating the encrypted message file.\n");
            return 1;
        }
        fprintf(messageFile, "%s", message);
        fclose(messageFile);

        printf("Message encryption completed. Encrypted content saved in encrypted_message.txt\n");

        keyFile = fopen("encryption_key.txt", "w");
        if (keyFile == NULL) {
            printf("Error creating the encryption key file.\n");
            return 1;
        }

        fprintf(keyFile, "%d", key);
        fclose(keyFile);

        printf("Encryption key saved in encryption_key.txt\n");
    } else if (action == 'D' || action == 'd') {
        printf("Enter the decryption key (the same key used for encryption): ");
        scanf("%d", &key);

        keyFile = fopen("encryption_key.txt", "r");
        if (keyFile == NULL) {
            printf("Error opening the encryption key file.\n");
            return 1;
        }

        int originalKey;
        fscanf(keyFile, "%d", &originalKey);
        fclose(keyFile);

        if (key != originalKey) {
            printf("Wrong key! Decryption failed.\n");
            return 1;
        }

        messageFile = fopen("encrypted_message.txt", "r");
        if (messageFile == NULL) {
            printf("Error opening the encrypted message file.\n");
            return 1;
        }

        fgets(message, sizeof(message), messageFile);
        message[strcspn(message, "\n")] = '\0';
        fclose(messageFile);
        decrypt(message, key);

        messageFile = fopen("decrypted_message.txt", "w");
        if (messageFile == NULL) {
            printf("Error creating the decrypted message file.\n");
            return 1;
        }
        fprintf(messageFile, "%s", message);

        fclose(messageFile);

        printf("Message decryption completed. Decrypted content saved in decrypted_message.txt\n");
    } else {
        printf("Invalid action. Please choose 'E' or 'D' for encryption or decryption.\n");
    }

    return 0;
}

