#include "alum.h"

int	ia_medium(char *alum, int size, int round)
{
  char	nb[size];

  put_mode(alum, size, -1);
  my_putstr("Ia is playing               ");
  buf_init(nb, size);
  count_nb_alum_on_line(alum, nb);
  if ((calc_xor(nb, size)) != 0 && (calc_xor(nb, size)) != 1 && round != 1)
    ia_hard(alum, size, round);
  else
    {
      algo_easy(alum, nb, size);
      put_mode(alum, size, -1);
      sleep(1);
      my_putstr("             ");
      if ((delete_space(alum, size)) == -1)
	return (3);
    }
  return (0);
}
