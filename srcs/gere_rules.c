#include "alum.h"

int	return_for_play(t_game UNUSED *game)
{
  return (2);
}

void	fill_rules(char **menu)
{
  menu[0] = "Rules";
  menu[1] = " In Allum1,";
  menu[2] = "two players alternately draw counters from one of x match-heaps";
  menu[3] = "formed by 1, 3, 5 and 7 or more counters.";
  menu[4] = "The player making the last move is the loser.";
  menu[5] = "Use Arrows to move, Space to select and Enter to comfirm.";
  menu[6] = "Good Luck.";
  menu[7] = "<- Back";
  menu[8] = NULL;
}

int	gere_rules(t_game *game)
{
  int	ret;
  char	buf[SIZE];
  char	*menu[9];

  game->which_display = 2;
  buf_init(buf, SIZE + 1);
  fill_rules(menu);
  print_menu(menu, 7, -1, 7);
  while ((ret = read(0, buf, SIZE)) > 0)
    {
      if (buf[0] == 27 && buf[1] == 0)
	return (1);
      if (buf[0] == 10 && buf[1] == 0)
	{
	  clear_scr();
	  return (0);
	}
      buf_init(buf, SIZE + 1);
    }
  return (0);
}

int	gere_exit(t_game UNUSED *game)
{
  return (1);
}
