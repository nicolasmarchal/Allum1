#include "alum.h"

void	put_under_inverse(char *str, char pos, char sel, int i)
{
  if (pos == i)
    my_putstr(tgetstr("mr", NULL));
  if (i == sel)
    my_putstr(tgetstr("us", NULL));
  my_putstr(str);
  my_putstr(tgetstr("me", NULL));
}

int	biggest_len_of_tab(char **menu)
{
  int	i;
  int	len;

  i = -1;
  len = 0;
  while (menu[++i])
    {
      if (len < my_strlen(menu[i]))
	len = my_strlen(menu[i]);
    }
  return (len);
}

int	size_tab(char **menu)
{
  int	i;

  i = -1;
  while (menu[++i]);
  return (i);
}

int	print_menu(char **menu, int pos, char sel, int decal)
{
  struct winsize	ws;
  int			i;
  int			row;
  int			col;

  i = -1;
  if ((ioctl(0, TIOCGWINSZ, &ws)) == -1)
    return (-1);
  row = ws.ws_row / 2 - decal;
  col = ws.ws_col / 2;
  if (ws.ws_row <= size_tab(menu) * 2 || ws.ws_col <= biggest_len_of_tab(menu))
    return (my_puterror("Please resize the window !"));
  while (menu[++i])
    {
      my_putstr(tgoto(tgetstr("cm", NULL), col - my_strlen(menu[i]) / 2, row));
      if (pos == i || i == sel)
	put_under_inverse(menu[i], pos, sel, i);
      else
	my_putstr(menu[i]);
      row = row + 2;
    }
  return (0);
}
