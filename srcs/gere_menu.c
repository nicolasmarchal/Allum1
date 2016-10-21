#include "alum.h"

void	fill_menu(char **menu)
{
  menu[0] = "ALLUM 1\0";
  menu[1] = "Play!\0";
  menu[2] = "Options\0";
  menu[3] = "Rules\0";
  menu[4] = "Score\0";
  menu[5] = "Exit!\0";
  menu[6] = NULL;
}

int	press_key(char **menu, char *buf, char key[8][4], int pos)
{
  if ((my_strcmp(buf, key[2])) == 0)
    {
      if (pos == 1)
	while (menu[++(pos) + 1]);
      else
	pos = pos - 1;
    }
  else if ((my_strcmp(buf, key[3])) == 0)
    {
      if (!menu[pos + 1])
	while (--(pos) > 1);
      else
	pos = pos + 1;
    }
  return (pos);
}

int	gere_select(t_game *game, int pos)
{
  int	(*ptf[5])(t_game *);

  clear_scr();
  ptf[0] = return_for_play;
  ptf[1] = gere_option;
  ptf[2] = gere_rules;
  ptf[3] = gere_score;
  ptf[4] = gere_exit;
  return ((ptf[pos - 1])(game));
}

int	gere_menu(t_game *game)
{
  int	ret;
  char	buf[SIZE];
  char	*menu[7];

  game->pos = 1;
  buf_init(buf, SIZE + 1);
  fill_menu(menu);
  game->which_display = 0;
  clear_scr();
  print_menu(menu, game->pos, -1, 5);
  while ((ret = read(0, buf, SIZE)) > 0)
    {
      if ((buf[0] == 27 && buf[1] == 0))
	return (1);
      if (buf[0] == 10 && buf[1] == 0)
	{
	  if ((ret = gere_select(game, game->pos)) >= 1)
	    return (ret);
	}
      game->pos = press_key(menu, buf, game->key, game->pos);
      game->which_display = 0;
      print_menu(menu, game->pos, -1, 5);
      buf_init(buf, SIZE + 1);
    }
  return (0);
}
