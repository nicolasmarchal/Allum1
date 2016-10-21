#include "alum.h"

int	check_for_sel(char *game)
{
  int	i;

  i = -1;
  while (game[++i])
    {
      if (game[i] == '1')
	return (-1);
    }
  return (0);
}

int	init_data(t_game *game, struct termios *t, char **env)
{
  if ((init_env(t, get_name(env))) == -1)
    return (-1);
  fill_key(game->key);
  game->size = 4;
  game->level = 1;
  game->pos = 0;
  game->which_display = 0;
  init_score(game->stat);
  return (0);
}

char	*fill_the_game(int size)
{
  int	i;
  int	j;
  char	*alum;
  char	nb_alum;
  int	cpt_alum;

  if ((alum = malloc(sizeof(char) * (size * size + size + 1))) == NULL)
    return (NULL);
  buf_init(alum, size * size + size + 1);
  i = -1;
  j = -1;
  nb_alum = 1;
  cpt_alum = -1;
  while (++i < size)
    {
      cpt_alum = -1;
      while (++cpt_alum < nb_alum)
	alum[++j] = '0';
      alum[++j] = '\n';
      nb_alum = nb_alum + 2;
    }
  return (alum);
}

int	are_you_ready_to_play_the_game(t_game *game)
{
  char	ret;

  clear_scr();
  if ((game->alum = fill_the_game(game->size)) == NULL)
    return (-1);
  game->which_display = 3;
  ret = play_the_game(game);
  if (ret == 1)
    ++game->stat[game->level - 1];
  ++game->stat[game->level + 2];
  return (0);
}

int			init_game(char **env)
{
  struct termios	t;
  t_game		game;

  glo_si = &game;
  if ((init_data(&game, &t, env)) == -1)
    return (-1);
  signal(SIGWINCH, check_si);
  while ((gere_menu(&game)) == 2)
    {
      game.pos = 0;
      game.size = ask_for_size(&game);
      if (game.size >= 4 && game.size <= 255
	  && (are_you_ready_to_play_the_game(&game)) == -1)
	return (-1);
      game.which_display = 0;
      if (game.size >= 4 && game.size <= 255)
	free(game.alum);
    }
  fill_stat(&game);
  return (reactive_can(&t));
}
