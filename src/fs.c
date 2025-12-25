#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// helper to create a directory
int ensure_dir(const char *path)
{

  if (mkdir(path, 0755) == 0)
    return 0;

  if (errno == EEXIST)
    return 0; // fine if it already exists

  fprintf(stderr, "mkdir failed for %s: %s\n", path, strerror(errno));

  return -1;
}

// helper to create the folder structure
int init_dirs(void)
{
  if (ensure_dir(".mygit") != 0)
    return -1;
  if (ensure_dir(".mygit/objects") != 0)
    return -1;
  if (ensure_dir(".mygit/refs") != 0)
    return -1;
  if (ensure_dir(".mygit/refs/heads") != 0)
    return -1;

  return 0;
}

// helper to  write to a file
int write_file(const char *path, const char *content)
{
  FILE *f = fopen(path, "wb");

  // file not available
  if (!f)
  {
    perror("fopen");
    return -1;
  }

  size_t n = fwrite(content, 1, strlen(content), f);
  // write error
  if (n != strlen(content))
  {
    perror("fwrite");
    fclose(f);
    return -1;
  }

  fclose(f);
  return 0;
}

// init head for repo
int init_head(void)
{
  return write_file(".mygit/HEAD", "ref: refs/heads/main\n");
}

// int index for repo
int init_index(void)
{
  return write_file(".mygit/index", "");
}

// helper to read entire file
unsigned char *read_entire_file(const char *path, size_t *out_size)
{
  FILE *f = fopen(path, "rb");

  // file not found
  if (!f)
    return NULL;

  if (fseek(f, 0, SEEK_END) != 0)
  {
    fclose(f);
    return NULL;
  }

  long sz = ftell(f);
  // empty file
  if (sz < 0)
  {
    fclose(f);
    return NULL;
  }

  rewind(f);

  unsigned char *buff = malloc((size_t)sz);
  // error allocating memory
  if (!buff)
  {
    fclose(f);
    return NULL;
  }

  size_t n = fread(buff, 1, (size_t)sz, f);
  fclose(f);

  if (n != (size_t)sz)
  {
    free(buff);
    return NULL;
  }

  *out_size = n;
  return buff;
}

// check if file exists
int file_exists(const char *path)
{
  struct stat st;
  return stat(path, &st) == 0;
}