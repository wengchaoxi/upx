
#pragma once

inline int xor_cipher(unsigned char *data, size_t len, const char *key, size_t key_len){
    if ( data == NULL || key == NULL || len == 0 || key_len == 0)
        return -1;
    for (size_t i = 0; i < len; i++)
        data[i] ^= key[i % key_len];
    return 0;
}
