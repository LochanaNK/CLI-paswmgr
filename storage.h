#ifndef STORAGE_H
#define STORAGE_H

typedef struct{
    char site[50];
    char username[50];
    char password[50];
}Credential;

void saveCredential(Credential cred);
void viewCredential();
void removeCredential(const char *site);

#endif