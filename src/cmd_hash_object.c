#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fs.h"
#include "hash.h"
#include "object.h"
int cmd_hash_object(const char *filepath) 
{
  size_t len = 0;
  unsigned char *data = read_entire_file(filepath, &len);

  if(!data)
  {
    fprintf(stderr, "Failed to read form file %s\n", filepath);
    return -1;
  }

  // Build: "blob <len>\0" + data
  char header[64];
  int header_len = snprintf(header, sizeof(header), "blob %zu", len) + 1; // +1 for '\0'
  if (header_len <= 0 || (size_t)header_len >= sizeof(header))
  {
    free(data);
    fprintf(stderr, "Header too long\n");
    return 1;
  }

  size_t obj_len = (size_t)header_len + len;
  unsigned char *obj = malloc(obj_len);
  if (!obj)
  {
    free(data);
    perror("malloc");
    return 1;
  }

  memcpy(obj, header, (size_t)header_len);
  memcpy(obj + header_len, data, len);

  char hex[41];
  sha_hex(obj, obj_len, hex);

  int rc = write_object_blob(hex, obj, obj_len); // store header+content
  free(obj);
  free(data);

  if (rc != 0)
    return 1;

  printf("%s\n", hex);
  return 0;
}