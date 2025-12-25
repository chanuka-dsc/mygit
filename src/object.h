#ifndef OB_H
#define OB_H

#include <stddef.h> // for size_t

int write_object_blob(const char *hash_hex, const unsigned char *data, size_t len);

#endif