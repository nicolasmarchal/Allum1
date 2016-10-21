#include "alum.h"

int	calc_xor(char *nb_alum, int size)
{
  int	i;
  int	result;

  i = -1;
  result = 0;
  while (++i < size)
    result = result ^ nb_alum[i];
  return (result);
}

int	clean_game(char *game, int nb_alum, int line)
{
  int	i;
  int	pos;
  int	pick_nb;

  i = -1;
  pos = 0;
  pick_nb = 0;
  while (game[++i] && pos != line)
    {
      if (game[i] == '\n')
	pos = pos + 1;
    }
  while (game[i] && game[i] != '\n' && pick_nb < nb_alum)
    {
      if (game[i] == '0')
	{
	  game[i] = '1';
	  pick_nb = pick_nb + 1;
	}
      i = i + 1;
    }
  return (0);
}

void	count_nb_alum_on_line(char *alum, char *nb)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (alum[++i])
    {
      if (alum[i] == '0')
	++nb[j];
      if (alum[i] == '\n')
	++j;
    }
}

int	ia_hard(char *alum, int size, int UNUSED round)
{
  char	nb[size];
  int	result;

  put_mode(alum, size, -1);
  my_putstr("Ia is playing               ");
  buf_init(nb, size);
  count_nb_alum_on_line(alum, nb);
  if ((result = calc_xor(nb, size)) != 0)
    pick_alum(alum, nb, size, 1);
  else
    pick_alum(alum, nb, size, 0);
  put_mode(alum, size, -1);
  sleep(1);
  delete_space(alum, size);
  my_putstr("             ");
  return (0);
}
