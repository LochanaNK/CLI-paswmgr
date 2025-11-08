#include "crypto.h"


void xorEncryptDecrypt(char *str, char key, int length) {
    for (int i = 0; i < length; i++) {
        str[i] ^= key;
    }
}
