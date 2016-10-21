#include "alum.h"

int	check_particular2(char *game, int pos, int real_pos)
{
  while (--pos > -1 && game[pos] && game[pos] != '\n')
    {
      if (game[pos] >= '0')
	return (pos);
    }
  if (pos == -1 || !game[pos])
    {
      return (real_pos);
    }
  if (game[pos] == '\n')
    return (check_particular2(game, pos, real_pos));
  return (pos);
}

int	check_particular(char *game, int pos, int real_pos)
{
  int	next_pos;

  next_pos = -1;
  while (--pos > -1 && game[pos] && game[pos] != '\n')
    {
      if (game[pos] >= '0')
	next_pos = pos;
    }
  if (pos == -1 && next_pos == -1)
    return (real_pos);
  if (next_pos == -1)
    next_pos = check_particular(game, pos, real_pos);
  return (next_pos);
}

int	check_next_line2(char *game, int pos, int cpt)
{
  int	ret;

  while (game[--pos] && game[pos] != '\n');
  while (game[--pos] && game[pos] != '\n');
  pos = pos + cpt;
  if (pos < 0)
    return (-1);
  if (game[pos] < '0')
    {
      if ((ret = check_left(game, pos)) != -1)
	return (ret);
      if ((ret = check_right(game, pos)) != -1)
	return (ret);
      if ((ret = check_next_line2(game, pos, cpt)) == -1)
	return (ret);
      return (-1);
    }
  return (pos);
}

int	exec_up(char *game, int i)
{
  int	pos;
  int	cpt;
  int	ret;

  pos = i;
  cpt = 0;
  if (i && game[i - 1] == '\n')
    return (check_particular(game, i - 1, i));
  while (pos && game[--pos] && game[pos] != '\n')
    cpt = cpt + 1;
  while (--pos > -1 && game[pos] && game[pos] != '\n');
  (pos + cpt < 0) ? (pos = i) : (pos = pos + cpt);
  if (game[pos] < '0' && pos != i)
    {
      if (game[pos] != '\n')
	{
	  if ((ret = check_left(game, pos)) != -1 ||
	      (ret = check_right(game, pos)) != -1)
	    return (ret);
	  return (check_particular2(game, pos, i));
	}
      return (check_particular2(game, pos, i));
    }
  return (pos);
}
