#include "my.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb > 9)
    my_put_nbr(nb / 10);
  my_putchar((nb % 10) + 48);
}

void	my_putnbr_fd(int nb, int fd)
{
  if (nb < 0)
    {
      my_putchar_fd('-', fd);
      nb = nb * (-1);
    }
  if (nb > 9)
    my_put_nbr(nb / 10);
  my_putchar_fd((nb % 10) + 48, fd);
}