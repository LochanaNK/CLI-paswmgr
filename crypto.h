#ifndef CRYPTO_H
#define CRYPTO_H

// Encrypt or decrypt data in place using XOR
void xorEncryptDecrypt(char *data, const char *key, int dataLen, int keyLen);

#endif
