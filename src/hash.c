#include <openssl/sha.h>

void sha_hex(const unsigned char * data, size_t len, char out_hex[41])
{
  unsigned char hash[SHA_DIGEST_LENGTH];
  SHA1(data, len, hash);

  static const char *hex = "0123456789abcdef";

  for (int i = 0; i < SHA_DIGEST_LENGTH; i++)
  {
    out_hex[i*2] = hex[(hash[i] >> 4) & 0xF];
    out_hex[i * 2 + 1] = hex[hash[i] & 0xF];
  }
  out_hex[40] = '\0';
}