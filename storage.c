#include <stdio.h>
#include <string.h>
#include "storage.h"
#include "crypto.h"

#define KEY 'K'   // XOR key

// Save a credential to vault.dat
void saveCredential(Credential cred) {
    cred.passwordLength = strlen(cred.password);
    xorEncryptDecrypt(cred.password, KEY,cred.passwordLength);
    FILE *file = fopen("vault.dat", "ab+");
    if (!file) {
        printf("Error opening vault.dat\n");
        return;
    }

    fwrite(&cred, sizeof(Credential), 1, file);
    fclose(file);
    xorEncryptDecrypt(cred.password, KEY,cred.passwordLength);
    printf("Credential saved!\n");
}


void viewCredential() {
    FILE *file = fopen("vault.dat", "rb");
    if (!file) {
        printf("No credentials found.\n");
        return;
    }

    Credential cred;
    while (fread(&cred, sizeof(Credential), 1, file)) {
        xorEncryptDecrypt(cred.password, KEY,cred.passwordLength);

        printf("\n\n\n\nSite: %s\nUsername: %s\nPassword: ", cred.site, cred.username);
        for (int i = 0; i < cred.passwordLength; i++) {
            putchar(cred.password[i]);
        }
        printf("\n\n\n\n");
    }

    fclose(file);
}

void removeCredential(const char *site) {
    FILE *file = fopen("vault.dat", "rb");
    if (!file) {
        printf("No credentials saved yet.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    Credential cred;
    int found = 0;

    while (fread(&cred, sizeof(Credential), 1, file)) {
        xorEncryptDecrypt(cred.password, KEY,cred.passwordLength);

        if (strcmp(cred.site, site) != 0) {
            xorEncryptDecrypt(cred.password, KEY,cred.passwordLength);
            fwrite(&cred, sizeof(Credential), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    if (remove("vault.dat") != 0) {
        printf("Error deleting original vault file.\n");
        return;
    }
    if (rename("temp.dat", "vault.dat") != 0) {
        printf("Error renaming temp file.\n");
        return;
    }
    if (found) {
        printf("Credential for '%s' removed.\n", site);
    } else {
        printf("No credentials found for '%s'.\n", site);
    }
}
