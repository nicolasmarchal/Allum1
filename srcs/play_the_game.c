#include "alum.h"

int	check_key(char *game, char *buf, char key[8][4], int *pos)
{
  int	(*pft[7])(char *, int );
  int	i;

  pft[0] = exec_right;
  pft[1] = exec_left;
  pft[2] = exec_up;
  pft[3] = exec_down;
  pft[4] = exec_space;
  pft[5] = exec_q_key;
  pft[6] = exec_s_key;
  i = -1;
  while (key[++i][0] && (my_strcmp(buf, key[i])) != 0);
  if ((i == 2 || i == 3) && (check_for_sel(game)) == -1)
    return (0);
  if (i < 7)
    return (*pos = (pft[i])(game, *pos));
  return (0);
}

int	player_turn(t_game *game)
{
  char	buf[SIZE + 1];
  int	ret;
  char	ret_code;

  buf_init(buf, SIZE + 1);
  while ((ret = read(0, buf, SIZE)) > 0)
    {
      if ((buf[0] == 27 && buf[1] == 0))
	return (1);
      if ((buf[0] == 10 && buf[1] == 0))
	{
	  if ((ret_code = delete_space(game->alum, game->size)) == -1)
	    return (0);
	  if (ret_code != 2)
	    return (2);
	}
      check_key(game->alum, buf, game->key, &game->pos);
      put_mode(game->alum, game->size, game->pos);
      buf_init(buf, SIZE + 1);
    }
  return (0);
}

char	print_result(char who_win)
{
  struct winsize ws;
  int	row;
  int	col;

  if ((ioctl(0, TIOCGWINSZ, &ws)) == -1)
    return (-1);
  clear_scr();
  row = ws.ws_row / 2;
  col = ws.ws_col / 2 - 5;
  my_putstr(tgoto(tgetstr("cm", NULL), col, row));
  if (who_win == 0)
    {
      my_putstr("YOU LOOSE !");
      sleep(1);
      return (0);
    }
  else if (who_win == 1)
    {
      my_putstr("RAGE QUIT !");
      sleep(1);
      return (0);
    }
  my_putstr("YOU WINNN !");
  sleep(1);
  return (1);
}

int	check_who_play_the_first_for_hard(t_game *game)
{
  char	nb[game->size];

  buf_init(nb, game->size);
  count_nb_alum_on_line(game->alum, nb);
  if ((calc_xor(nb, game->size)) != 0)
    return (ia_hard(game->alum, game->size, 0));
  return (0);
}

char	play_the_game(t_game *game)
{
  int	round;
  char	stop;
  int	(*ptf[3])(char *, int, int);

  ptf[0] = ia_hard;
  ptf[1] = ia_medium;
  ptf[2] = ia_easy;
  stop = 0;
  round = 0;
  if (game->level == 1)
    check_who_play_the_first_for_hard(game);
  while (42)
    {
      game->pos = -1;
      while (game->alum[++game->pos] && game->alum[game->pos] < '0');
      put_mode(game->alum, game->size, game->pos);
      if ((stop = player_turn(game)) <= 1)
	return (print_result(stop));
      stop = (ptf[game->level - 1])(game->alum, game->size, ++round);
      if (stop == 3)
	return (print_result(2));
    }
  return (0);
}
