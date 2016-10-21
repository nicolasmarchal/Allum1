#include "alum.h"

void	fill_score(char **menu)
{
  menu[0] = " ";
  menu[1] = "Reset";
  menu[2] = "<-Back";
  menu[3] = NULL;
}

void	print_stat(t_game *game, int row, int col, int i)
{
  my_putstr(tgoto(tgetstr("cm", NULL), col, row + 2));
  my_putstr("WIN: ");
  my_put_nbr(game->stat[i]);
  my_putstr(tgoto(tgetstr("cm", NULL), col, row + 3));
  my_putstr("PLAYED: ");
  my_put_nbr(game->stat[i + 3]);
}

void	fill_score2(char **menu)
{
  menu[0] = "Score ";
  menu[1] = "Hard";
  menu[2] = "Medium";
  menu[3] = "Easy";
  menu[4] = NULL;
}

int	gere_score(t_game *game)
{
  int	ret;
  char	buf[SIZE];
  char	*menu[4];

  buf_init(buf, SIZE + 1);
  game->pos = 1;
  game->which_display = 5;
  fill_score(menu);
  print_menu(menu, game->pos, -1, -2);
  fill_stat(game);
  print_score(game);
  while ((ret = read(0, buf, SIZE)) > 0)
    {
      if (buf[0] == 27 && buf[1] == 0)
	return (1);
      if (buf[0] == 10 && buf[1] == 0 && game->pos == 2)
	return (clear_scr());
      if (buf[0] == 10 && buf[1] == 0 && game->pos == 1)
	reset_stat(game);
      game->pos = press_key(menu, buf, game->key, game->pos);
      print_menu(menu, game->pos, -1, -2);
      buf_init(buf, SIZE + 1);
    }
  return (0);
}
