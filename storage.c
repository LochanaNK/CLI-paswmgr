#include <stdio.h>
#include <string.h>
#include "storage.h"
#include "crypto.h"
#include "keygen.h"

void saveCredential(Credential cred, const char *key, int keyLen) {
    strcpy(cred.key, key);
    cred.passwordLength = strlen(cred.password);
    xorEncryptDecrypt(cred.password, cred.key, cred.passwordLength, keyLen);

    FILE *file = fopen("vault.dat", "ab+");
    if (!file) {
        printf("\nError opening vault.dat\n");
        return;
    }

    fwrite(&cred, sizeof(Credential), 1, file);
    fclose(file);

    printf("\nCredential saved!\n");
}

void viewCredential(const char *key, int keyLen) {
    FILE *file = fopen("vault.dat", "rb");
    if (!file) {
        printf("\nNo credentials found.\n");
        return;
    }

    Credential cred;
    while (fread(&cred, sizeof(Credential), 1, file)) {
        xorEncryptDecrypt(cred.password, cred.key, cred.passwordLength, strlen(cred.key));

        printf("\nSite: %s\nUsername: %s\nPassword: %s\n", 
               cred.site, cred.username, cred.password);

        xorEncryptDecrypt(cred.password, cred.key, cred.passwordLength, strlen(cred.key));
    }

    fclose(file);
}

void removeCredential(const char *site, const char *key, int keyLen) {
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
        xorEncryptDecrypt(cred.password, cred.key, cred.passwordLength, strlen(cred.key));

        if (strcmp(cred.site, site) != 0) {
            xorEncryptDecrypt(cred.password, cred.key, cred.passwordLength, strlen(cred.key));
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

    if (found)
        printf("\nCredential for '%s' removed.\n", site);
    else
        printf("\nNo credentials found for '%s'.\n", site);
}
