#include "crypto.h"

void xorEncryptDecrypt(char *str, char key){
    for(int i=0;str[i];i++){
        str[i] ^= key;
    }
}