#include <stdio.h>
#include <string.h>
#include "storage.h"
#include "crypto.h"


// Save a credential to vault.dat
void saveCredential(Credential cred,const char *key,int keyLen) {
    cred.passwordLength = strlen(cred.password);
    xorEncryptDecrypt(cred.password, key,cred.passwordLength);
    FILE *file = fopen("vault.dat", "ab+");
    if (!file) {
        printf("\nError opening vault.dat\n");
        return;
    }

    fwrite(&cred, sizeof(Credential), 1, file);
    fclose(file);
    xorEncryptDecrypt(cred.password, key,cred.passwordLength);
    printf("\nCredential saved!\n");
}


void viewCredential(const char *key,int keyLen) {
    FILE *file = fopen("vault.dat", "rb");
    if (!file) {
        printf("\nNo credentials found.\n");
        return;
    }

    Credential cred;
    while (fread(&cred, sizeof(Credential), 1, file)) {
        xorEncryptDecrypt(cred.password, key,cred.passwordLength);

        printf("\n\n\n\nSite: %s\nUsername: %s\nPassword: ", cred.site, cred.username);
        for (int i = 0; i < cred.passwordLength; i++) {
            putchar(cred.password[i]);
        }
        printf("\n\n\n\n");
    }

    fclose(file);
}

void removeCredential(const char *site,const char *key,int keyLen) {
    FILE *file = fopen("vault.dat", "rb");
    if (!file) {
        printf("\nNo credentials saved yet.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        printf("\nError creating temporary file.\n");
        fclose(file);
        return;
    }

    Credential cred;
    int found = 0;

    while (fread(&cred, sizeof(Credential), 1, file)) {
        xorEncryptDecrypt(cred.password, key,cred.passwordLength);

        if (strcmp(cred.site, site) != 0) {
            xorEncryptDecrypt(cred.password, key,cred.passwordLength);
            fwrite(&cred, sizeof(Credential), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    if (remove("vault.dat") != 0) {
        printf("\nError deleting original vault file.\n");
        return;
    }
    if (rename("temp.dat", "vault.dat") != 0) {
        printf("\nError renaming temp file.\n");
        return;
    }
    if (found) {
        printf("\nCredential for '%s' removed.\n", site);
    } else {
        printf("\nNo credentials found for '%s'.\n", site);
    }
}
