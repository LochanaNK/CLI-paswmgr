#ifndef STORAGE_H
#define STORAGE_H

#define MAX_LEN 50

typedef struct {
    char site[MAX_LEN];
    char username[MAX_LEN];
    char password[MAX_LEN];
    int passwordLength;
} Credential;

// Storage functions
void saveCredential(Credential cred,const char *key,int keyLen);
void viewCredential(const char *key,int keyLen);
void removeCredential(const char *site,const char *key,int keyLen);

#endif
