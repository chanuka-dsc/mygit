#include <stdio.h>
#include <string.h>
#include "repo.h"
#include "cmd_cat_file.h"
#include "cmd_hash_object.h"

int main(int argc, char *argv[])
{

  // Setting up command dummies
  if (strcmp(argv[1], "init") == 0)
  {
    return cmd_init();
  }
  else if (strcmp(argv[1], "add") == 0)
  {
    printf("git add called");
  }
  else if (strcmp(argv[1], "commit") == 0)
  {
    printf("git commit called");
  }
  else if (strcmp(argv[1], "log") == 0)
  {
    printf("git log called");
  }
  else if (strcmp(argv[1], "checkout") == 0)
  {
    printf("git checkout called");
  }
  else if (strcmp(argv[1], "hash-object") == 0)
  {
    if (argc != 3)
    {
      fprintf(stderr, "usage: mygit hash-object <file>\n");
      return 1;
    }
    return cmd_hash_object(argv[2]);
  } else if (strcmp(argv[1], "cat-file") == 0)
  {
    if (argc != 3)
    {
      fprintf(stderr, "usage: mygit cat-file <hash>\n");
      return 1;
    }
    return cmd_cat_file(argv[2]);
  }
   else {
    printf("Invalid git command");
  }

  return 0;
}

