#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

  // Setting up command dummies
  if (strcmp(argv[1], "init") == 0)
  {
    printf("git init called");
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
  } else {
    printf("Invalid git command");
  }

  return 0;
}

