#include "alum.h"

int	len_nb(int nb)
{
  int	i;

  i = 0;
  while (nb)
    {
      nb = nb / 10;
      ++i;
    }
  return (i);
}

void	print_nb_is_to_big(struct winsize *ws, int *size)
{
  char *str;

  str = "A NUMBER BETWEEN 4 AND 254 !!!!!!!!!!!!!";
  my_putstr(tgoto(tgetstr("cm", NULL), ws->ws_col / 2
		  - my_strlen(str) / 2, ws->ws_row / 2 + 2));
  my_putstr(str);
  sleep(1);
  str = "                                        ";
  my_putstr(tgoto(tgetstr("cm", NULL), ws->ws_col / 2
		  - my_strlen(str) / 2, ws->ws_row / 2 + 2));
  my_putstr(str);
  *size = 0;
}

int	verif_size(char *buf, int *size, struct winsize *ws)
{
  if ((ioctl(0, TIOCGWINSZ, ws)) == -1)
    return (-1);
  if (buf[0] == 27 && buf[1] == 0)
    return (-1);
  if (buf[0] >= '0' && buf[0] <= '9' && (*size * 10 + buf[0] - 48) < 255)
    {
      *size = *size * 10 + buf[0] - 48;
      my_putstr(tgoto(tgetstr("cm", NULL), ws->ws_col / 2
		      - len_nb(*size) / 2, ws->ws_row / 2 + 2));
      my_put_nbr(*size);
    }
  else if (buf[0] >= '0' && buf[0] <= '9')
    print_nb_is_to_big(ws, size);
  return (0);
}

int	print_ask_for_size(struct winsize *ws)
{
  char	*str;

  str = "Please Enter a number between 4 and 254\n";
  if ((ioctl(0, TIOCGWINSZ, ws)) == -1)
    return (-1);
  if (ws->ws_col <= my_strlen(str) || ws->ws_row <= 3)
    return (my_puterror("Please rezise the window"));
  my_putstr(tgoto(tgetstr("cm", NULL), ws->ws_col / 2
		  - my_strlen(str) / 2, ws->ws_row / 2));
  my_putstr(str);
  return (0);
}

int			ask_for_size(t_game *game)
{
  struct winsize	ws;
  int			ret;
  int			size;
  char			buf[SIZE];

  buf_init(buf, SIZE + 1);
  size = 0;
  clear_scr();
  game->which_display = 4;
  print_ask_for_size(&ws);
  while ((ret = read(0, buf, SIZE)) > 0)
    {
      if (buf[0] == 10 && buf[1] == 0 && size >= 4 && size < 255)
	return (size);
      else if (buf[0] == 10 && buf[1] == 0)
	print_nb_is_to_big(&ws, &size);
      if ((verif_size(buf, &size, &ws)) == -1)
	return (0);
      buf_init(buf, SIZE + 1);
    }
  return (0);
}
