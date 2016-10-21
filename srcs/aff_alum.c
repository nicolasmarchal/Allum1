#include "alum.h"

void	put_underline(char c, int idx, int pos, char ident)
{
  char	*res;

  if (ident == '1')
    {
      res = tgetstr("mr", NULL);

      my_putstr(res);
    }
  if (idx == pos)
    {
      res = tgetstr("us", NULL);
      my_putstr(res);
    }
  my_putchar(c);
  res = tgetstr("me", NULL);
  my_putstr(res);
}

int	biggest_line(char *str)
{
  int	i;

  i = my_strlen(str) - 1;
  while (str[--i] && str[i] != '\n');
  i = my_strlen(str) - i;
  return (i);
}

int			put_mode(char *str, int size, int pos)
{
  struct winsize	ws;
  int			i;
  int			col;
  int			row;

  i = -1;
  if ((ioctl(0, TIOCGWINSZ, &ws)) == -1)
    return (-1);
  row = ws.ws_row / 2 - size / 2;
  col = ws.ws_col / 2;
  if (ws.ws_col <= biggest_line(str) || ws.ws_row <= size)
    return (my_puterror("Please resize the window !"));
  my_putstr(tgoto(tgetstr("cm", NULL), col, row));
  while (str[++i])
    {
      if (str[i] >= '0')
	put_underline('|', i, pos, str[i]);
      else if (str[i] == '\n')
	my_putstr(tgoto(tgetstr("cm", NULL), --col, ++row));
      else
	my_putchar(str[i]);
    }
  return (0);
}

int	delete_space(char *game, int size)
{
  int	i;
  char	bol;

  i = -1;
  bol = 0;
  while (game[++i])
    {
      if (game[i] == '1')
	{
	  game[i] = ' ';
	  bol = 1;
	}
    }
  if (bol == 0)
    {
      my_putstr("You need to pick one alum !\n");
      return (2);
    }
  i = -1;
  while (game[++i])
    if (game[i] == '0')
      return (0);
  put_mode(game, size, -1);
  return (-1);
}
