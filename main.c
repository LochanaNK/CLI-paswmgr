#include <stdio.h>
#include <string.h>
#include "storage.h"

int main(){
    char master[20];
    printf("Enter master password: ");
    scanf("%s",master);
    if(strcmp(master,"admin123")!=0){
        printf("Access denied!\n");
        return 0;
    }

    int option;
    while(1){
        printf("\nPlease press the coresponding number to select the option\n");
        printf("1:Add Credentials\n2:View Credentials\n3:Remove Credentials\n4:Exit\nChoice: ");
        scanf("%d",&option);

        switch(option){
            case 1:{
                Credential cred;
                printf("Site: ");
                scanf("%s",cred.site);
                printf("Username: ");
                scanf("%s",cred.username);
                printf("Password: ");
                scanf("%s",cred.password);
                saveCredential(cred);
                break;
            }
            case 2:{
                viewCredential();
                break;
            }
            case 3:{
                char site[50];
                printf("Enter the site to remove: ");
                scanf("%s",site);
                removeCredential(site);
                break;
            }
            case 4:
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
}