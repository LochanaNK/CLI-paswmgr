#include <stdio.h>
#include <string.h>
#include "storage.h"

int main(){
    char master[20];
    char site[50];
    Credential cred;
    int option;
    printf("Enter master password: ");
    scanf("%s",master);
    if(strcmp(master,"admin123")!=0){
        printf("Access denied!\n");
        return 0;
    }

     while (1) {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Credential\n2. View Credentials\n3. Remove Credential\n4. Exit\nEnter choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: // Add
                printf("Enter site: ");
                scanf("%s", cred.site);
                printf("Enter username: ");
                scanf("%s", cred.username);
                printf("Enter password: ");
                scanf("%s", cred.password);
                saveCredential(cred);
                break;

            case 2: // View
                viewCredential();
                break;

            case 3: // Remove
                printf("Enter site to remove: ");
                scanf("%s", site);
                removeCredential(site);
                break;

            case 4: // Exit
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}