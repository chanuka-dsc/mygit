#include <stdlib.h>
#include "fs.h"
#include <stdio.h>

int cmd_cat_file(const char *hash)
{
  char path[512];
  snprintf(path, sizeof(path), ".mygit/objects/%s", hash);

  size_t len = 0;
  unsigned char *data = read_entire_file(path, &len);

  if (!data)
  {
    fprintf(stderr, "Object not found: %s\n", hash);
    return 1;
  }

  fwrite(data, 1, len, stdout);
  free(data);
  return 0;
}