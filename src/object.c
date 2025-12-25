#include <sys/stat.h>
#include "fs.h"
#include <stdlib.h>
#include <stdio.h>

int write_object_blob(const char *hash_hex, const unsigned char *data, size_t len)
{
  char path[512];
  snprintf(path, sizeof(path), ".mygit/objects/%s", hash_hex);

  // if the file is already there we dont write again
  if (file_exists(path))
    return 0;

  FILE *f = fopen(path, "wb");
  if (!f)
  {
    perror(path);
    return -1;
  }

  if (fwrite(data, 1, len, f) != len)
  {
    perror("fwrite");
    fclose(f);
    return -1;
  }

  fclose(f);
  return 0;
}