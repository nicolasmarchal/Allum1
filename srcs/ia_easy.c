#include "alum.h"

int	algo_easy(char *alum, char *nb, int size)
{
  int	i;
  int	j;

  srand(time(NULL));
  i = rand() % size;
  while (nb[i] == 0)
    i = rand() % size;
  j = 1 + rand() % nb[i];
  clean_game(alum, j, i);
  return (0);
}

int	ia_easy(char *alum, int size, int UNUSED round)
{
  char	nb[size];

  put_mode(alum, size, -1);
  my_putstr("Ia is playing");
  buf_init(nb, size);
  count_nb_alum_on_line(alum, nb);
  algo_easy(alum, nb , size);
  put_mode(alum, size, -1);
  sleep(1);
  my_putstr("             ");
  if ((delete_space(alum, size)) == -1)
    return (3);
  return (0);
}
