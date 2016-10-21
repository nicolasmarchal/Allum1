#include "alum.h"

int	nb_line(char *nb_alum, int size)
{
  int	i;
  int	cpt;

  i = -1;
  cpt = 0;
  while (++i < size)
    {
      if (nb_alum[i] != 0)
	cpt = cpt + 1;
    }
  return (cpt);
}

int	add_nb_alum(char *nb_alum, int size)
{
  int	i;
  int	total;

  i = -1;
  total = 0;
  while (++i < size)
    total = total + nb_alum[i];
  return (total);
}

int	check_nb_alum_one_line(char *alum, int line, int nb_elem_del)
{
  int	i;
  int	cpt_nb_alum_on_line;
  int	cpt_back_slash_n;

  i = -1;
  cpt_back_slash_n = 0;
  cpt_nb_alum_on_line = 0;
  while (alum[++i] && cpt_back_slash_n < line)
    {
      if (alum[i] == '\n')
	++cpt_back_slash_n;
    }
  while (alum[i] && alum[i] != '\n')
    {
      if (alum[i] >= '0')
	cpt_nb_alum_on_line = cpt_nb_alum_on_line + 1;
      i = i + 1;
    }
  if (nb_elem_del == cpt_nb_alum_on_line)
    return (1);
  return (0);
}

int	exeption1(char *nb, int size, int i, char bol)
{
  if (bol != 1 && nb[i] == 0 && (calc_xor(nb, size)) != 0)
    return (0);
  else if (bol != 0 && (calc_xor(nb, size)) == 0)
    {
      if ((nb_line(nb, size)) == 0)
	return (1);
      else if ((nb_line(nb, size)) == add_nb_alum(nb, size)
	       && nb_line(nb , size) % 2 == 0)
	return (2);
      return (0);
    }
  return (3);
}

int	pick_alum(char *alum, char *nb, int size, char bol)
{
  int	i;
  char	tmp;
  int	j;
  int	ret_code;

  i = -1;
  while (++i < size)
    {
      tmp = nb[i];
      j = 0;
      while (nb[i] >= 0)
	{
	  if ((ret_code = exeption1(nb, size, i, bol)) != 3)
	    {
	      if (ret_code == 1)
		j = j - 1;
	      else if (ret_code == 2)
		((check_nb_alum_one_line(alum, i, j)) == 1) ? --j : ++j;
	      return (clean_game(alum, j, i));
	    }
	  j = j + 1;
	  nb[i] = nb[i] - 1;
	}
      nb[i] = tmp;
    }
}
