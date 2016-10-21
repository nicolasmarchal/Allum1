#include "alum.h"

int	init_score(int *score)
{
  int	i;

  i = -1;
  while (++i < 8)
    score[i] = 0;
  return (0);
}

int	reset_stat(t_game *game)
{
  clear_scr();
  re_write(game->stat);
  print_score(game);
  return (0);
}
