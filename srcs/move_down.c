#include "alum.h"

int	check_left(char *game, int pos)
{
  while (game[++pos] && game[pos] != '\n')
    {
      if (game[pos] >= '0')
	return (pos);
    }
  return (-1);
}

int	check_right(char *game, int pos)
{
  while (--pos > -1 && game[pos] && game[pos] != '\n')
    {
      if (game[pos] >= '0')
	return (pos);
    }
  return (-1);
}

int	check_next_line(char *game, int pos, int cpt)
{
  int	ret;

  while (game[++pos] && game[pos] != '\n');
  pos = pos + cpt;
  if (pos >= my_strlen(game))
    return (-1);
  if (game[pos] < '0')
    {
      if ((ret = check_left(game, pos)) != -1)
	return (ret);
      if ((ret = check_right(game, pos)) != -1)
	return (ret);
      if ((ret = check_next_line(game, pos, cpt + 1)) != -1)
	return (ret);
      return (-1);
    }
  return (pos);
}

int	exec_down(char *game, int i)
{
  int	pos;
  int	cpt;
  int	ret;

  pos = i;
  cpt = 0;
  while (pos && game[--pos] && game[pos] != '\n')
    cpt = cpt + 1;
  while (game[++pos] && game[pos] != '\n');
  pos = pos + cpt + 2;
  if (pos >= my_strlen(game))
    pos = i;
  else if (game[pos] < '0')
    {
      if ((ret = check_left(game, pos)) != -1)
	return (ret);
      if ((ret = check_right(game, pos)) != -1)
	return (ret);
      if ((ret = check_next_line(game, pos, cpt + 3)) != -1)
	return (ret);
      return (i);
    }
  return (pos);
}
