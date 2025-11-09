#include<stdlib.h>
#include<string.h>
#include <time.h>
#include "keygen.h"

void generateRandomKey(char *key,int length){
    const char charset[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
    int charsetSize = strlen(charset);
    for(int i=0;i<length-1;i++){
        key[i] =charset[rand()%charsetSize];
    }
    key[length-1]= '\0';
}