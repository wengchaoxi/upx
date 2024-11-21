
#pragma once

#ifndef NULL
#define NULL ((void*)0)
#endif

inline int xor_cipher(unsigned char *data, size_t len, const char *key, size_t key_len){
    if ( data == NULL || key == NULL || len == 0 || key_len == 0)
        return -1;
    size_t i;
    for (i = 0; i < len; i++)
        data[i] ^= key[i % key_len];
    return 0;
}
