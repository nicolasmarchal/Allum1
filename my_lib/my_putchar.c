#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putchar_fd(char c, int fd)
{
  write(fd, &c, 1);
}
