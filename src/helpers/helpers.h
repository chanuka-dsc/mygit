#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

// helper to create a directory
static int ensure_dir(const char *path)
{

  if (mkdir(path, 0755) == 0)
    return 0;

  if (errno == EEXIST)
    return 0; // fine if it already exists

  fprintf(stderr, "mkdir failed for %s: %s\n", path, strerror(errno));

  return -1;
}

// helper to create the folder structure
static int init_dirs(void)
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
static int write_file(const char *path, const char *content)
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