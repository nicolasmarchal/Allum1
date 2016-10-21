#include "alum.h"

int	exec_left(char *game, int i)
{
  while (i && game[--i] && game[i] != '\n' && game[i] < '0');
  if (game[i] == '\n' || i < 0)
    {
      while (game[++i] && game[i] != '\n');
      while (game[--i] && game[i] < '0');
    }
  return (i);
}

int	exec_right(char *game, int i)
{
  while (game[++i] && game[i] != '\n' && game[i] < '0');
  if (game[i] == '\n')
    {
      while (--i > -1 && game[i] && game[i] != '\n');
      while (game[++i] && game[i] < '0');
    }
  return (i);
}

int	exec_space(char *game, int pos)
{
  (game[pos] == '0') ? (game[pos] = '1') : (game[pos] = '0');
  return (pos);
}

int	exec_q_key(char *game, int pos)
{
  int	tmp;

  tmp = pos;
  while (pos > -1 && game[pos] && game[pos] != '\n')
    {
      if (game[pos] >= '0')
	game[pos] = '1';
      pos = pos - 1;
    }
  return (tmp);
}

int	exec_s_key(char *game, int pos)
{
  int	tmp;

  tmp = pos;
  while (--pos > -1 && game[pos] != '\n');
  while (game[++pos] && game[pos] != '\n')
    {
      if (game[pos] == '1')
	game[pos] = '0';
    }
  return (tmp);
}
