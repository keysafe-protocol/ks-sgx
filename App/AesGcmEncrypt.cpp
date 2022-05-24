#include "AesGcmEncrypt.h"
#include "global.h"

AesGcmEncrypt* AesGcmEncrypt::Create(const unsigned char* shared, const unsigned char* cipher_text, int cipher_len)
{
    auto pObject = new AesGcmEncrypt();
    if(!pObject)
    {
        return NULL;
    }
    pObject->capacity = (cipher_len/16+1)*16;
    pObject->data = (uint8_t*)malloc(pObject->capacity);
    aes_gcm_encrypt(shared, 256, IV, sizeof(IV),
            cipher_text, cipher_len, pObject->data, &pObject->size);
    pObject->isEncrypted = true;
    return pObject;
}