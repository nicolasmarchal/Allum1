#include "alum.h"

int	parse_stat(char *str, int *stat)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (str[++i] && j < 8)
    {
      if (str[i] == '=')
	{
	  stat[j] = stat[j] + my_getnbr(&str[i + 1]);
	  j = j + 1;
	}
    }
  return (0);
}

void	fill_score_for_file(char **score)
{
  score[0] = "W_H=";
  score[1] = "W_M=";
  score[2] = "W_E=";
  score[3] = "P_H=";
  score[4] = "P_M=";
  score[5] = "P_E=";
  score[6] = "W=";
  score[7] = "P=";
}

int	re_write(int *test)
{
  char	*score[8];
  int	fd;
  int	i;

  if ((fd = open("./.score.allum1", O_RDWR)) == -1)
    {
      my_puterror("can't open score file !\n");
      return (-1);
    }
  fill_score_for_file(score);
  i = -1;
  while (++i < 8)
    {
      write(fd, score[i], my_strlen(score[i]));
      my_putnbr_fd(test[i], fd);
      write(fd, ";\n", 2);
    }
  close(fd);
  return (0);
}

int	fill_stat(t_game *game)
{
  int	fd;
  int	ret;
  char	buf[SIZE_MAX_];

  buf_init(buf, SIZE_MAX_);
  if ((fd = open("./.score.allum1", O_RDWR | O_CREAT)) == -1)
    {
      my_puterror("can't open score file !\n");
      return (-1);
    }
  while ((ret = read(fd, buf, SIZE_MAX)) > 0);
  close(fd);
  parse_stat(buf, game->stat);
  re_write(game->stat);
  return (0);
}
