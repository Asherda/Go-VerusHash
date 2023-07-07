#include "keccak.h"

#include "sph_types.h"
#include "sph_keccak.h"


void keccak_hash(const char* input, char* output, uint32_t size)
{
    sph_keccak256_context ctx_keccak;
    sph_keccak256_init(&ctx_keccak);
    sph_keccak256 (&ctx_keccak, input, size);//80);
    sph_keccak256_close(&ctx_keccak, output);
}

