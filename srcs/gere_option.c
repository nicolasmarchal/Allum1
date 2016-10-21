#include "alum.h"

void	fill_option(char **menu)
{
  menu[0] = "Difficulty:";
  menu[1] = "Hard";
  menu[2] = "Medium";
  menu[3] = "Easy";
  menu[4] = "<-Back\n";
  menu[5] = NULL;
}

int	gere_option(t_game *game)
{
  int	ret;
  char	buf[SIZE];
  char	*menu[6];

  game->pos = 1;
  game->which_display = 1;
  buf_init(buf, SIZE + 1);
  fill_option(menu);
  print_menu(menu, game->pos, game->level, 4);
  while ((ret = read(0, buf, SIZE)) > 0)
    {
      if (buf[0] == 27 && buf[1] == 0)
	return (1);
      else if (buf[0] == 10 && buf[1] == 0)
	{
	  if (game->pos != 4)
	    game->level = game->pos;
	  else
	    return (clear_scr());
	}
      game->pos = press_key(menu, buf, game->key, game->pos);
      print_menu(menu, game->pos, game->level, 4);
      buf_init(buf, SIZE + 1);
    }
  return (0);
}
