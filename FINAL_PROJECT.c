#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <unistd.h>

// Function prototypes
void encryptFile(char *inputfilename, char *outputfilename,const char *algorithm,int shift, char *xorKey );
void decryptFile(char *inputfilename, char *outputfilename,const char *algorithm,int shift, char *xorKey );
void encryptText(const char *text, const char *algorithm, int shift , char *xorKey);
void decryptText(const char *text, const char *algorithm, int shift, char *xorKey);
void encryptImage(const char *inputFilename, const char *outputFilename, char *xorKey);
void decryptImage(const char *inputFilename, const char *outputFilename, char *xorKey);

// Encryption functions
void caesarEncrypt(char *text, int shift);
void substitutionEncrypt(char *text, const char *key);
void xorEncrypt(char *text, char *key);

// Decryption functions
void caesarDecrypt(char *text, int shift);
void substitutionDecrypt(char *text, const char *key);
void xorDecrypt(char *text, char *key);


int main() {
    int choice;
    char input[100];
    char algorithm[20];
    int shift;  // Shift value for Caesar Cipher
    char text[1000];
    char substitutionKey[27];
    char xorKey[100];
    char output[100];
    char inputfilename[100];
    char outputfilename[100];

    printf("\nWELCOME TO PROJECT CIPHER! \n \n");
    printf("\n Welcome to Project Cipher: Unveil the Cryptic Shadows! \n\n"
           "Dare to step into the realm of encrypted secrets and forbidden knowledge? Embrace the darkness as Project Cipher beckons you into the enigmatic world of cryptographic mysteries.\n\n"
           "Every algorithm unfolds a tale of its own from the eerie whispers of the Caesar Cipher to the arcane arts of Substitution, and the haunting dance of XOR encryption. As you traverse the cryptic corridors, remember: not everything is as it seems.\n\n"
           "The shadows guard the encrypted secrets, and only the daring shall prevail. Will you decipher the unknown or become entangled in the cryptic web?\n\n"
           "Uncover the arcane, for encryption awaits your command. Choose wisely, for the journey begins now...\n\n"

           "Let the Cipher Games Begin!\n\n");



    while (1) {
        printf("Choose your path wisely:\n\n");
        printf("1. Encrypt a file\n");
        printf("2. Decrypt a file\n");
        printf("3. Encrypt Text\n");
        printf("4. Decrypt Text\n");
        printf("5. Encrypt Image\n");
        printf("6. Decrypt Image\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");

        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 7) {
            // Handle invalid input (non-integer or out of range)
            printf("Invalid input. Please enter a number between 1 and 7.\n");

            // Clear the input buffer
            
            while (getchar() != '\n');

            // Continue to the next iteration of the loop
            continue;
        }

       
int algorithmChoice;
switch (choice) {
    
    case 1:
            printf("Enter the name of the input file: ");
            scanf("%s", inputfilename);

            printf("Enter the name of the output file: ");
            scanf("%s", outputfilename);

            printf("Choose encryption algorithm:\n");
            printf("1. Caesar Cipher\n");
            printf("2. Substitution Cipher\n");
            printf("3. XOR Cipher\n");
            printf("Enter your choice (1-3): ");
            scanf("%d", &algorithmChoice);

            switch (algorithmChoice) {
                case 1:
                    encryptFile(inputfilename, outputfilename, "Caesar Cipher", 0, NULL);
                    break;
                case 2:
                    encryptFile(inputfilename, outputfilename, "Substitution Cipher", 0, NULL);
                    break;
                case 3:
                    encryptFile(inputfilename, outputfilename, "XOR Cipher", 0, xorKey);
                    break;
                default:
                    printf("Invalid choice. Using default algorithm.\n");
                    encryptFile(inputfilename, outputfilename, "Caesar Cipher", 0, NULL);
                    break;
            }
            break;

case 2:
            printf("Enter the name of the input file: ");
            scanf("%s", inputfilename);

            printf("Enter the name of the output file: ");
            scanf("%s", outputfilename);

            printf("Choose decryption algorithm:\n");
            printf("1. Caesar Cipher\n");
            printf("2. Substitution Cipher\n");
            printf("3. XOR Cipher\n");
            printf("Enter your choice (1-3): ");
            scanf("%d", &algorithmChoice);

            switch (algorithmChoice) {
                case 1:
                    decryptFile(inputfilename, outputfilename, "Caesar Cipher", 0, NULL);
                    break;
                case 2:
                    decryptFile(inputfilename, outputfilename, "Substitution Cipher", 0, NULL);
                    break;
                case 3:
                    decryptFile(inputfilename, outputfilename, "XOR Cipher", 0, xorKey);
                    break;
                default:
                    printf("Invalid choice. Using default algorithm.\n");
                    decryptFile(inputfilename, outputfilename, "Caesar Cipher", 0, NULL);
                    break;
            }
     break;
        

    case 3:
        printf("Enter the text to encrypt: ");
        scanf(" %[^\n]s", input);  // Read the whole line
        printf("Choose encryption algorithm:\n");
        printf("1. Caesar Cipher\n");
        printf("2. Substitution Cipher\n");
        printf("3. XOR Cipher\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nCAESAR CIPHER ENCRYPTION\n");
                encryptText(input, "Caesar Cipher", shift , 0);
                break;
            case 2:
                printf("\nSUBSTITUTION ENCYPTION\n");
                encryptText(input, "Substitution Cipher", 0 , 0);
                break;
            case 3:
                printf("\nXOR CIPHER ENCRYPTION\n");
                encryptText(input, "XOR Cipher", 0 , xorKey );
                break;
            default:
                printf("\nInvalid choice. Using default algorithm.\n");
                encryptText(input, "Caesar Cipher", shift , 0);
                break;
        }
        break;
    case 4:
        printf("Enter the text to decrypt: \n");
        scanf(" %[^\n]s", input);  // Read the whole line
        printf("\nChoose decryption algorithm:\n");
        printf("1. Caesar Cipher\n");
        printf("2. Substitution Cipher\n");
        printf("3. XOR Cipher\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nCAESAR CIPHER ENCRYPTION\n");
                decryptText(input, "Caesar Cipher", shift , 0);
                break;
            case 2:
                printf("\nSUBSTITUTION ENCRYPTION\n");
                decryptText(input, "Substitution Cipher", 0 , 0);
                break;
            case 3:
                printf("\nXOR CIPHER ENCRYPTION\n");
                decryptText(input, "XOR Cipher", 0 , xorKey);
                break;
            default:
                printf("\nInvalid choice. Using default algorithm.\n");
                decryptText(input, "Caesar Cipher", shift , 0);
                break;
}
break;
case 5:
            printf("\nEnter input image filename: ");
            scanf("%99s", input);
            printf("\nEnter output image filename: ");
            scanf("%99s", output);
            printf("\nEnter the key for XOR Cipher (a hexadecimal string): ");
            scanf("%99s", xorKey);
            encryptImage(input, output, xorKey);
            printf("\nImage encryption complete.\n");
            break;

        case 6:
            printf("\nEnter input image filename: ");
            scanf("%99s", input);
            printf("\nEnter output image filename: ");
            scanf("%99s", output);
            printf("\nEnter the key for XOR Cipher (a hexadecimal string): ");
            scanf("%99s", xorKey);
            decryptImage(input, output, xorKey);
            printf("\nImage decryption complete.\n");
            break;
  case 7:
                // Exit the program
                printf("\nExiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
        // consume remaining characters in input buffer
        
        while (getchar() != '\n');

    return 0;
}
    }
// Function to perform Caesar Cipher encryption
void caesarEncrypt(char *text, int shift)
{
    for (int i = 0; text[i] != '\0'; ++i)
     {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base + shift + 26) % 26 + base;
        }
    }
}

// Function to perform Substitution Cipher encryption
void substitutionEncrypt(char *text, const char *key) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = key[text[i] - base] + (base - 'A');
        }
    }
}

// Function to perform XOR Cipher encryption
void xorEncrypt(char *text, char *key) {
    size_t textLen = strlen(text);
    size_t keyLen = strlen(key);

    for (size_t i = 0; i < textLen; ++i) {
        text[i] = text[i] ^ key[i % keyLen];
    }
}

// Function to perform Caesar Cipher decryption
void caesarDecrypt(char *text, int shift) {
    caesarEncrypt(text, -shift);
}

// Function to perform Substitution Cipher decryption
void substitutionDecrypt(char *text, const char *key) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = strchr(key, text[i]) - key + base;
        }
    }
}

// Function to perform XOR Cipher decryption
void xorDecrypt(char *text, char *key) {
    xorEncrypt(text, key);
}

// Function to encrypt a file
void encryptFile(char *inputfilename, char *outputfilename, const char *algorithm, int shift, char *xorKey) {
    FILE *file = fopen(inputfilename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char text[1000];
    char substitutionKey[27];

    FILE *outputFile = fopen(outputfilename, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(file);
        return;
    }

    // Prompt the user to enter the substitution key
    if (strcmp(algorithm, "Substitution Cipher") == 0) {
        printf("\nEnter the key for Substitution Cipher (26 uppercase letters, each letter used exactly once): ");
        scanf("%26s", substitutionKey);

        // Validate the substitution key (each letter used exactly once)
        if (strlen(substitutionKey) != 26) {
            printf("\nInvalid key for Substitution Cipher. Exiting program.\n");
            fclose(file);
            fclose(outputFile);
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (!isalpha(substitutionKey[i]) || !isupper(substitutionKey[i])) {
                printf("\nInvalid key for Substitution Cipher. Exiting program.\n");
                fclose(file);
                fclose(outputFile);
                return;
            }
        }
    }

    // Prompt the user to enter the XOR key
    if (strcmp(algorithm, "XOR Cipher") == 0) {
        printf("\nEnter the key for XOR Cipher (a hexadecimal string): ");
        scanf("%99s", xorKey);
    }

    // Prompt the user to enter the shift value for Caesar Cipher
    if (strcmp(algorithm, "Caesar Cipher") == 0) {
        printf("\nEnter the shift value for encryption: ");
        scanf("%d", &shift);
    }

    while (fgets(text, sizeof(text), file) != NULL) {
        // Perform encryption based on the chosen algorithm
        if (strcmp(algorithm, "Caesar Cipher") == 0) {
            caesarEncrypt(text, shift);
        } else if (strcmp(algorithm, "Substitution Cipher") == 0) {
            substitutionEncrypt(text, substitutionKey);
        } else if (strcmp(algorithm, "XOR Cipher") == 0) {
            xorEncrypt(text, xorKey);
        }

        // Write encrypted text to the output file
        fprintf(outputFile, "%s", text);
    }

    printf("\n\nEncryption successful using %s algorithm.\n\nEncrypted file saved in %s\n \n",algorithm, outputfilename);
    puts("");

    fclose(file);
    fclose(outputFile);
}

// Function to decrypt a file
void decryptFile(char *inputfilename, char *outputfilename, const char *algorithm, int shift, char *xorKey) {
    FILE *file = fopen(inputfilename, "r");
    if (file == NULL) {
        perror("\nError opening file");
        return;
    }

    char text[1000];
    char substitutionKey[27];

    FILE *outputFile = fopen(outputfilename, "w");
    if (outputFile == NULL) {
        perror("\nError opening output file");
        fclose(file);
        return;
    }

    // Prompt the user to enter the substitution key
    if (strcmp(algorithm, "Substitution Cipher") == 0) {
        printf("\nEnter the key for Substitution Cipher (26 uppercase letters, each letter used exactly once): ");
        scanf("%26s", substitutionKey);

        // Validate the substitution key (each letter used exactly once)
        if (strlen(substitutionKey) != 26) {
            printf("\nInvalid key for Substitution Cipher. Exiting program.\n");
            fclose(file);
            fclose(outputFile);
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (!isalpha(substitutionKey[i]) || !isupper(substitutionKey[i])) {
                printf("Invalid key for Substitution Cipher. Exiting program.\n");
                fclose(file);
                fclose(outputFile);
                return;
            }
        }
    }

    // Prompt the user to enter the XOR key
    if (strcmp(algorithm, "XOR Cipher") == 0) {
        printf("\nEnter the key for XOR Cipher (a hexadecimal string): ");
        scanf("%99s", xorKey);
    }

    // Prompt the user to enter the shift value for Caesar Cipher
    if (strcmp(algorithm, "Caesar Cipher") == 0) {
        printf("\nEnter the shift value for encryption: ");
        scanf("%d", &shift);
    }

    while (fgets(text, sizeof(text), file) != NULL) {
        // Perform decryption based on the chosen algorithm
        if (strcmp(algorithm, "Caesar Cipher") == 0) {
            caesarDecrypt(text, shift);
        } else if (strcmp(algorithm, "Substitution Cipher") == 0) {
            substitutionDecrypt(text, substitutionKey);
        } else if (strcmp(algorithm, "XOR Cipher") == 0) {
            xorDecrypt(text, xorKey);
        }

        // Write decrypted text to the output file
        fprintf(outputFile, "%s", text);
    }

    printf("\n\nDecryption successful using %s algorithm\n\nDecrypted file saved in %s\n\n",algorithm, outputfilename);
    puts("");

    fclose(file);
    fclose(outputFile);
}

// Function to encrypt text
void encryptText(const char *text, const char *algorithm , int shift, char *xorKey) {
    char substitutionKey[27];

    // Prompt the user to enter the substitution key
    if (strcmp(algorithm, "Substitution Cipher") == 0) {
        printf("\nEnter the key for Substitution Cipher (26 uppercase letters, each letter used exactly once): ");
        scanf("%26s", substitutionKey);

        // Validate the substitution key (each letter used exactly once)
        if (strlen(substitutionKey) != 26) {
            printf("\nInvalid key for Substitution Cipher. Exiting program.\n");
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (!isalpha(substitutionKey[i]) || !isupper(substitutionKey[i])) {
                printf("\nInvalid key for Substitution Cipher. Exiting program.\n");
                return;
            }
        }
    }

    // Prompt the user to enter the XOR key
    if (strcmp(algorithm, "XOR Cipher") == 0) {
        printf("\nEnter the key for XOR Cipher (a hexadecimal string): ");
        scanf("%99s", xorKey);
    }


    // Prompt the user to enter the shift value for Caesar Cipher
    if (strcmp(algorithm, "Caesar Cipher") == 0) {
        printf("\nEnter the shift value for encryption: ");
        scanf("%d", &shift);
    }

    char encryptedText[1000];

    // Perform encryption based on the chosen algorithm
    if (strcmp(algorithm, "Caesar Cipher") == 0) {
        strcpy(encryptedText,            text);  // Copy the original text to encryptedText to preserve it
        caesarEncrypt(encryptedText, shift);
    } else if (strcmp(algorithm, "Substitution Cipher") == 0) {
        strcpy(encryptedText, text);
        substitutionEncrypt(encryptedText, substitutionKey);
    } else if (strcmp(algorithm, "XOR Cipher") == 0) {
        strcpy(encryptedText, text);
        xorEncrypt(encryptedText, xorKey);
    }

    // Save encrypted text to a file
    FILE *outputFile = fopen("encrypted_text_output.txt", "w");
    if (outputFile == NULL) {
        perror("\nError opening output file");
        return;
    }

    fprintf(outputFile, "%s", encryptedText);

    printf("\n\nEncryption successful !!!!!! Encrypted text saved to: encrypted_text_output.txt\n\n");
    puts("");

    fclose(outputFile);
}

// Function to decrypt text
void decryptText(const char *text, const char *algorithm , int shift, char *xorKey) {
    char substitutionKey[27];

    // Prompt the user to enter the substitution key
    if (strcmp(algorithm, "Substitution Cipher") == 0) {
        printf("\nEnter the key for Substitution Cipher (26 uppercase letters, each letter used exactly once): ");
        scanf("%26s", substitutionKey);

        // Validate the substitution key (each letter used exactly once)
        if (strlen(substitutionKey) != 26) {
            printf("\nInvalid key for Substitution Cipher. Exiting program.\n");
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (!isalpha(substitutionKey[i]) || !isupper(substitutionKey[i])) {
                printf("\nInvalid key for Substitution Cipher. Exiting program.\n");
                return;
            }
        }
    }

    // Prompt the user to enter the XOR key
    if (strcmp(algorithm, "XOR Cipher") == 0) {
        printf("\nEnter the key for XOR Cipher (a hexadecimal string): ");
        scanf("%99s", xorKey);
    }

    // Prompt the user to enter the shift value for Caesar Cipher
    if (strcmp(algorithm, "Caesar Cipher") == 0) {
        printf("\nEnter the shift value for encryption: ");
        scanf("%d", &shift);
    }


    char decryptedText[1000];

    // Perform decryption based on the chosen algorithm
    if (strcmp(algorithm, "Caesar Cipher") == 0) {
        strcpy(decryptedText, text);
        caesarDecrypt(decryptedText, shift);
    } else if (strcmp(algorithm, "Substitution Cipher") == 0) {
        strcpy(decryptedText, text);
        substitutionDecrypt(decryptedText, substitutionKey);
    } else if (strcmp(algorithm, "XOR Cipher") == 0) {
        strcpy(decryptedText, text);
        xorDecrypt(decryptedText, xorKey);
    }

        // Save decrypted text to a file
    FILE *outputFile = fopen("decrypted_text_output.txt", "w");
    if (outputFile == NULL) {
        perror("\nError opening output file");
        return;
    }

    fprintf(outputFile, "%s", decryptedText);

    printf("\n\nDecryption successful !!!! Decrypted text saved to: decrypted_text_output.txt\n\n");
    puts("");

    fclose(outputFile);
}

// Function to encrypt an image file using XOR cipher
void encryptImage(const char *inputFilename, const char *outputFilename, char *xorKey) {
    FILE *inputFile = fopen(inputFilename, "rb");
    FILE *outputFile = fopen(outputFilename, "wb");

    if (inputFile == NULL || outputFile == NULL) {
        perror("\nError opening files");
        return;
    }

    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    char *buffer = (char *)malloc(fileSize);
    fread(buffer, 1, fileSize, inputFile);

    xorEncrypt(buffer, xorKey);

    fwrite(buffer, 1, fileSize, outputFile);

    free(buffer);
    fclose(inputFile);
    fclose(outputFile);
}

// Function to decrypt an image file using XOR cipher
void decryptImage(const char *inputFilename, const char *outputFilename, char *xorKey) {
    encryptImage(inputFilename, outputFilename, xorKey); // XOR encryption and decryption are the same
}


