#include "my.h"

int	my_puterror(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    write(2, &str[i], 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    write(1, &str[i], 1);
}
