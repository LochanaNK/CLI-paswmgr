#include <string.h>
#include "crypto.h"


void xorEncryptDecrypt(char *str, char *key, int length) {
    int keyLen = strlen(key);

    for (int i = 0; i < length; i++) {
        str[i] ^= key[i % keyLen];
    }
}
