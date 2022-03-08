#ifndef _KS_ENCLAVE_SSL_FUNCS_H
#define _KS_ENCLAVE_SSL_FUNCS_H
#include <string>

#include "stdio.h"
#include "stdlib.h"
#include "ks_enclave_ssl_define.h"

char* Base64Encode(const char* input, int len, bool withc_new_line);
char* Base64Decode(const char * input, int length, bool with_new_line);

unsigned char* decrypt(EVP_PKEY* evp_key, unsigned char* in, size_t inlen);
unsigned char* encrypt(EVP_PKEY* evp_pkey, const char* str);

int FormatPubToPem(RSA * pRSA, std::string& base64);


#endif
