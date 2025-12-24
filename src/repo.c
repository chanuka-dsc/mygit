#include "helpers/helpers.h"
#include "repo.h"

int cmd_init(void) 
{

  if (init_dirs() != 0)
    return 1;
  if (init_head() != 0)
    return 1;
  if (init_index() != 0)
    return 1;

  printf("Initialized empty mygit repository in .mygit/\n");
  return 0;
}