#include "alum.h"

int	clear_scr(void)
{
  char	*res;

  res = tgetstr("cl", NULL);
  my_putstr(res);
  return (0);
}

char	*get_name(char **env)
{
  int	i;

  i = -1;
  while (env[++i])
    {
      if (env[i][0] == 'T' && env[i][1] == 'E'
	  && env[i][2] == 'R' && env[i][3] == 'M' && env[i][4] == '=')
	return (&env[i][5]);
    }
  return (NULL);
}

int	raw_mode(struct termios *t)
{
  t->c_lflag &= ~ICANON;
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  t->c_lflag &= ~ECHO;
  if ((tcsetattr(0, TCSANOW, t)) == -1)
    {
      my_puterror("error tcsetattr\n");
      return (-1);
    }
  my_putstr(tgetstr("vi", NULL));
  return (0);
}

int	reactive_can(struct termios *t)
{
  t->c_lflag = (ICANON | ECHO);
  if ((tcsetattr(0, TCSANOW, t)) == -1)
    {
      my_puterror("error tcsetattr\n");
      return (-1);
    }
  my_putstr(tgetstr("ve", NULL));
  return (0);
}

int	init_env(struct termios *t, char *name)
{
  if (name == NULL)
    return (-1);
  if ((tgetent(NULL, name)) <= 0)
    {
      my_puterror("error tgetent\n");
      return (-1);
    }
  if ((tcgetattr(0, t)) == -1)
    {
      my_puterror("error tcgetattr\n");
      return (-1);
    }
  if ((raw_mode(t)) == -1)
    return (-1);
  return (0);
}
