#include <stdio.h>
#include <string.h>
#include "storage.h"
#include "crypto.h"

#define KEY 'K'


void saveCredential(Credential cred){
    xorEncryptDecrypt(cred.password,KEY);
    FILE *file=fopen("vault.dat","ab+");
    if(!file){
        printf("Error opening vault.dat\n");
        return;
    }
    fwrite(&cred,sizeof(Credential),1,file);
    fclose(file);
    xorEncryptDecrypt(cred.password,KEY);
    printf("Credential saved!\n");
    
}

void viewCredential(){
    FILE *file=fope("vault.dat","rb");
    if(!file){
        printf("No credentials found.\n");
        return;
    }
    Credential cred;
    while(fread(&cred,sizeof(Credential),1,file)){
        xorEncryptDecrypt(cred.password,KEY);
        printf("\nSite: %s\nUsername: %s\nPassword: %s\n",cred.site,cred.username,cred.password);
    }
    fclose(file);
}

void removeCredential(const char *site)
{
    FILE *file = fopen("vault.dat", "rb");
    if (!file)
    {
        printf("No credentials saved yet\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp)
    {
        printf("Errror creating temp file.\n");
        fclose(file);
        return;
    }
    Credential cred;
    int found = 0;

    while (fread(&cred, sizeof(Credential), 1, file))
    {
        xorEncryptDecrypt(cred.password, KEY);
        if (strcmp(cred.site, site) != 0)
        {
            xorEncryptDecrypt(cred.password, KEY);
            fwrite(&cred, sizeof(Credential), 1, temp);
        }
        else
        {
            found = 1;
        }
    }
    fclose(file);
    fclose(temp);

    if(remove("vault.dat")!=0){
        printf("Error deleting original vault file.\n");
        return;
    }else if(rename("temp.dat","vault.dat")!=0){
        printf("Error renaming temp file.\n");
        return;
    }else if(found){
        printf("Credential for '%s' removed.\n",site);
    }else{
        printf("No credentials found for '%s'.\n",site);
    }
}
