#include <string.h>
#include "crypto.h"

// XOR encryption/decryption using a variable-length key
void xorEncryptDecrypt(char *data, const char *key, int dataLen, int keyLen) {
    for (int i = 0; i < dataLen; i++) {
        data[i] ^= key[i % keyLen];
    }
}


