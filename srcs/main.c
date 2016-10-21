#include "alum.h"

int	main(int UNUSED ac, char UNUSED **av, char **env)
{
  if ((init_game(env)) == -1)
    return (-1);
  my_putchar('\n');
  return (0);
}
