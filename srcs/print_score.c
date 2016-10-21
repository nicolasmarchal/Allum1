#include "alum.h"

void	print_score2(struct winsize *ws, int decal, char **score, t_game *game)
{
  int	i;
  int	j;

  i = 0;
  j = -1;
  while (score[++i])
    {
      my_putstr(tgoto(tgetstr("cm", NULL), ws->ws_col - decal, ws->ws_row));
      my_putstr(score[i]);
      print_stat(game, ws->ws_row, ws->ws_col - decal, ++j);
      decal = decal - ws->ws_col / 2;
    }
}

int			print_score(t_game *game)
{
  struct winsize	ws;
  char			*score[5];
  int			decal;

  if ((ioctl(0, TIOCGWINSZ, &ws)) == -1)
    return (-1);
  if (ws.ws_col <= 8 * 4 || ws.ws_row <= 10)
    return (my_puterror("Please resize the windows !"));
  ws.ws_row = ws.ws_row / 2 - 5;
  ws.ws_col = ws.ws_col / 2;
  fill_score2(score);
  my_putstr(tgoto(tgetstr("cm", NULL), ws.ws_col
		  - my_strlen(score[0]) / 2, ws.ws_row - 2));
  my_putstr(score[0]);
  decal = ws.ws_col / 2 + 3;
  print_score2(&ws, decal, score, game);
  return (init_score(game->stat));
}
